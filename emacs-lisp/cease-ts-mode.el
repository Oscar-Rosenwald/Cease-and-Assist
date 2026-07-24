;;; cease-ts-mode.el --- Tree-sitter support for Cease -*- lexical-binding: t; -*-

(require 'treesit)

(defcustom cease-ts-mode-indent-offset 4
  "Number of spaces for each indentation step in `cease-ts-mode'."
  :type 'integer
  :group 'cease)

(defvar cease-ts-mode--syntax-table
  (let ((table (make-syntax-table)))
    (modify-syntax-entry ?/ ". 124b" table)
    (modify-syntax-entry ?* ". 23" table)
    (modify-syntax-entry ?\n "> b" table)
    table)
  "Syntax table for `cease-ts-mode'.")

(setq cease-ts-mode--font-lock-settings
  (treesit-font-lock-rules
   :language 'cease
   :feature 'comment
   '((comment) @font-lock-comment-face)

   :language 'cease
   :feature 'string
   '((string) @font-lock-string-face
     (char) @font-lock-string-face)

   :language 'cease
   :feature 'keyword
   '((keyword) @font-lock-keyword-face
	 (terminator) @diff-added
     (modifier) @match)

   :language 'cease
   :feature 'type
   '((type_keyword) @font-lock-type-face
	 (type_identifier) @font-lock-type-face)

   :language 'cease
   :feature 'function
   '((procedure_definition name: (identifier) @font-lock-function-name-face)
	 (func_usage name: (identifier) @font-lock-function-call-face)
	 (pipe_usage name: (identifier) @diff-removed))

   :language 'cease
   :feature 'constant
   '((boolean) @font-lock-constant-face
     (number) @font-lock-number-face)

   :language 'cease
   :feature 'operator
   '((operator) @font-lock-builtin-face
     (punctuation) @font-lock-delimiter-face)
   ))

(defun cease-indent-line ()
  "Indent current line. (I did my best.)"
  (interactive)
  
  ;; This is unfortunately quite an involved function because cease indentation,
  ;; while completely predictable unlike Python's, isn't dictated by braces but
  ;; terminator words. There are a lot of cases, and not all of them are covered
  ;; here because there's a limit to how much time I'm willing to spend on this.
  ;; It should be relatively good, though.
  
  (let* (
 		 ;; Will be set to the last line which isn't empty.
 		 (previous-line "")
 		 ;; Will be set when the previous line is found.
 		 (previous-line-indent 0)
 		 ;; Magic numbers are bad.
 		 (indent-increment 4) (pipe-indent-increment 2)
 		 ;; Regular expressions used in the code. Obvious.
 		 (terminator-regex "^\\(return\\|yield\\|break\\|loop\\)\\b")
 		 (top-level-block-regex "^\\(impl\\|struct\\|enum\\|data\\|type\\|alias\\|interface\\)\\b")
 		 ;; Content of the current line.
 		 (current-line (s-trim (buffer-substring-no-properties (point-at-bol) (point-at-eol))))
 		 ;; How many characters from the beginning of the line (accounting for
 		 ;; indentation) is the cursor currently in. After this line is
 		 ;; indented, we'll move the cursor to the same position within the
 		 ;; line.
 		 (columns-from-indentation-count (- (point) (save-excursion (back-to-indentation) (point)))))
	
 	;; Load the previous non-empty line and its indentation. This will skip
 	;; empty lines and also indent them to 0 columns.
	
 	(save-excursion
 	  (while (s-equals-p previous-line "")
 		(indent-line-to 0)
 		(previous-line)
 		(setq previous-line-indent (current-indentation)
 			  previous-line (s-trim (buffer-substring-no-properties (point-at-bol) (point-at-eol))))))
	
 	;; Main logic: We go through all the possible cases and try to do our best.
 	;; We'll be comparing the prefixes and suffices of the current line, the
 	;; previous non-empty line (that we've just loaded), and in some cases of
 	;; the line which starts the current expression.
	
 	(indent-line-to
 	 (cond
 	  ;; This happens after top-level blocks (like structs) and after Embeddeds
 	  ;; or Programs.
 	  ((s-starts-with-p "}" current-line) (- previous-line-indent indent-increment))
	  
 	  ;; Function signatures, type definitions, and interfaces are always
 	  ;; indented to 0. This has the benefit of getting around a very hard
 	  ;; problem caused by this sort of thing:
 	  ;;
 	  ;;   return if cond:
 	  ;;       yield value;
 	  ;;
 	  ;; The next line should be completely unindented, but it's hard to compute
 	  ;; that because "yield" is caught first and the next line is indented to
 	  ;; "return"'s indentation. But the next statement, whatever it is, should
 	  ;; be indented 4 characters to the left.
 	  ((s-matches-p "^[\[a-zA-Z_].*::.*:" current-line) 0)
 	  ((s-matches-p top-level-block-regex current-line) 0)
 	  ;; The line following an impl tag is unindented, but that would also be
 	  ;; caught by the function match above. This just makes things easier for
 	  ;; us.
 	  ((s-starts-with-p "impl" previous-line) 0)
	  
 	  ;; Pipes have their own indentation. This is derived from whether the last
 	  ;; line was a pipe as well. Sometimes we can't just check the previous
 	  ;; line but the line which starts that sub-expression. That means there's
 	  ;; some logic here to determine how high up we need to go before we check
 	  ;; the pseudo-previous line. It's a lot.
 	  ((s-starts-with-p "|" current-line)
 	   (cond
 		((s-starts-with-p "|" previous-line) previous-line-indent)
		
 		((s-ends-with-p ">>" previous-line)
 		 (save-excursion (end-of-line -0)
 						 (re-search-backward ">>")
 						 (cease-goto-chevron-chevron-start)
 						 (if (s-starts-with-p "|" (s-trim (buffer-substring-no-properties (point-at-bol) (point-at-eol))))
 							 (current-indentation) (+ pipe-indent-increment previous-line-indent))))
		
 		((s-ends-with-p "}" previous-line)
 		 (save-excursion (end-of-line -0) ; This is probably a bug, but it also works, so...
 						 (backward-sexp)
 						 (if (s-starts-with-p "|" (s-trim (buffer-substring-no-properties (point-at-bol) (point-at-eol))))
 							 (current-indentation) (+ pipe-indent-increment previous-line-indent))))
		
 		(t (+ pipe-indent-increment previous-line-indent))))
	  
 	  ;; This is a sort of catch for all new expression. The previous line ended
 	  ;; its own expression, we we now need to determine whether the previous
 	  ;; expression was terminating or not. If it was, the current line should
 	  ;; be less indented than that. If it wasn't, we can keep the previous
 	  ;; line's indentation, unless it's a pipe in which case we need to remove
 	  ;; the pipe-specific indentation. I know, it's stupidly complicated.
 	  ((s-ends-with-p ";" previous-line)
 	   (cond ((s-matches-p terminator-regex previous-line) (- previous-line-indent indent-increment))
 			 ((s-starts-with-p "|" previous-line) (- previous-line-indent pipe-indent-increment))
			 
 			 ((s-ends-with-p "};" previous-line)
 			  (save-excursion (end-of-line -0)
 							  (re-search-backward "};")
 							  (forward-char)
 							  (backward-sexp)
 							  (if (s-matches-p terminator-regex (s-trim (buffer-substring-no-properties (point-at-bol) (point-at-eol))))
 								  (- (current-indentation) indent-increment) (current-indentation))))
			 
 			 ((s-ends-with-p ">>;" previous-line)
 			  (save-excursion (end-of-line -0)
 							  (re-search-backward ">>;")
 							  (cease-goto-chevron-chevron-start)
 							  (if (s-matches-p terminator-regex (s-trim (buffer-substring-no-properties (point-at-bol) (point-at-eol))))
 								  (- (current-indentation) indent-increment) (current-indentation))))
			 
 			 (t previous-line-indent)))
	  
 	  ;; The previous line may have closed a multi-line block denoted by the <<
 	  ;; ... >> pattern. In that case we should return to its parent's
 	  ;; indentation.
 	  ((or (s-ends-with-p ">>" previous-line)
 		   (s-ends-with-p ">>," previous-line))
 	   (save-excursion
 		 (end-of-line -0)
 		 (re-search-backward ">>")
 		 (cease-goto-chevron-chevron-start)
 		 (current-indentation)))
	  
 	  ;; Some symbols at the end of a line denote that the next line must be
 	  ;; indented. These are quite simple to deal with.
 	  ((s-ends-with-p ":" previous-line) (+ indent-increment previous-line-indent))
 	  ((s-ends-with-p "<<" previous-line) (+ indent-increment previous-line-indent))
 	  ((s-ends-with-p "{" previous-line) (+ indent-increment previous-line-indent))
	  
 	  ;; For everything else, we should keep the last line's indentation. In
 	  ;; practice there aren't many cases left, but e.g. lines ending with ','
 	  ;; are covered.
 	  (t previous-line-indent)))
	
 	;; This is to preserve the cursor offset within a line becaues
 	;; `indent-to-column' moves the cursor to the beginning of the line.
 	(back-to-indentation)
 	(forward-char columns-from-indentation-count)))


;;;###autoload
(define-derived-mode cease-ts-mode prog-mode "Cease"
  "Major mode for editing Cease files, powered by tree-sitter."
  :syntax-table cease-ts-mode--syntax-table

  (when (treesit-ready-p 'cease)
    (treesit-parser-create 'cease)
    (setq-local treesit-font-lock-settings cease-ts-mode--font-lock-settings)
    (setq-local treesit-font-lock-feature-list
                '((comment string)
                  (keyword type constant)
                  (function)
                  (operator)))
	(setq-local indent-line-function #'cease-indent-line)
    (treesit-major-mode-setup)))

;;;###autoload
(add-to-list 'auto-mode-alist '("\\.stop\\'" . cease-ts-mode))

(provide 'cease-ts-mode)
;;; cease-ts-mode.el ends here