;;; cease-mode.el --- Major mode for Cease programming language -*- lexical-binding: t; -*-

;;; Commentary:
;; Major mode for editing Cease (.stop) files

;;; Code:

(defvar cease-mode-syntax-table
  (let ((table (make-syntax-table)))
    ;; Comments
    (modify-syntax-entry ?/ ". 124b" table)
    (modify-syntax-entry ?* ". 23" table)
    (modify-syntax-entry ?\n "> b" table)

    ;; Strings
    (modify-syntax-entry ?\" "\"" table)
    (modify-syntax-entry ?\' "\"" table)
    (modify-syntax-entry ?\` "\"" table)

    ;; Operators and punctuation
    (modify-syntax-entry ?+ "." table)
    (modify-syntax-entry ?- "." table)
    (modify-syntax-entry ?= "." table)
    (modify-syntax-entry ?< "." table)
    (modify-syntax-entry ?> "." table)
    (modify-syntax-entry ?& "." table)
    (modify-syntax-entry ?| "." table)
    (modify-syntax-entry ?* "." table)
    (modify-syntax-entry ?~ "." table)
    (modify-syntax-entry ?! "." table)
    (modify-syntax-entry ?? "." table)
    (modify-syntax-entry ?$ "." table)
    (modify-syntax-entry ?% "." table)
    (modify-syntax-entry ?@ "." table)
    (modify-syntax-entry ?# "." table)

    ;; Parentheses and brackets
    (modify-syntax-entry ?\( "()" table)
    (modify-syntax-entry ?\) ")(" table)
    (modify-syntax-entry ?\[ "(]" table)
    (modify-syntax-entry ?\] ")[" table)
    (modify-syntax-entry ?\{ "(}" table)
    (modify-syntax-entry ?\} "){" table)

    ;; Underscores and word constituents
    (modify-syntax-entry ?_ "w" table)

    table)
  "Syntax table for `cease-mode'.")

(defvar cease-mode-abbrev-table nil
  "Abbreviation table for `cease-mode'.")

(define-abbrev-table 'cease-mode-abbrev-table
  '(("fn" ":: -> :\n" nil 0)
    ("ret" "return " nil 0)
    ("sw" "switch " nil 0)))

;; Font-lock (syntax highlighting)
(defconst cease-font-lock-keywords
  (list
   ;; Documentation blocks (=== text ===) - custom matcher for multiline support
   ;; TODO Implement, uncomment.
   ;; '(cease-match-doc-block (1 font-lock-doc-face t))

   ;; Keywords - control flow termination
   `(,(regexp-opt '("return" "break" "yield" "loop"
                    "cascade" "fail" "failure" "success") 'words)
     . font-lock-keyword-face)

   ;; Keywords - control structures
   `(,(regexp-opt '("if" "else" "while" "for" "switch" "case" "in" "over") 'words)
     . font-lock-keyword-face)

   ;; Keywords - declarations (excluding 'use' which gets special handling below)
   `(,(regexp-opt '("new" "old" "heap" "set" "struct" "enum" "interface"
                    "prop" "data" "sec" "fn" "type" "alias" "impl" "package" "scope") 'words)
     . font-lock-keyword-face)

   ;; Use statements - comprehensive patterns
   ;; use privateName = package/name;
   '("\\buse\\s-+\\([a-z_][a-zA-Z0-9_]*\\)\\s-*=\\s-*\\([a-z_][a-zA-Z0-9_/]*\\)"
     (0 nil) ;; Don't highlight the whole match
     (1 font-lock-variable-name-face) ;; privateName
     (2 font-lock-constant-face)) ;; package/name

   ;; use package/name symbol1 = imported1, symbol2 = imported2;
   '("\\buse\\s-+\\([a-z_][a-zA-Z0-9_/]*\\)\\s-+\\([a-z_][a-zA-Z0-9_]*\\)\\s-*=\\s-*\\([a-z_][a-zA-Z0-9_]*\\)"
     (0 nil)
     (1 font-lock-constant-face) ;; package/name
     (2 font-lock-variable-name-face) ;; local name
     (3 font-lock-function-name-face)) ;; imported symbol

   ;; use package/name *;
   '("\\buse\\s-+\\([a-z_][a-zA-Z0-9_/]*\\)\\s-+\\(\\*\\)"
     (0 nil)
     (1 font-lock-constant-face) ;; package/name
     (2 font-lock-keyword-face)) ;; *

   ;; use package/name symbol1 symbol2;
   '("\\buse\\s-+\\([a-z_][a-zA-Z0-9_/]*\\)\\s-+\\([a-z_][a-zA-Z0-9_]+\\)"
     (0 nil)
     (1 font-lock-constant-face) ;; package/name
     (2 font-lock-function-name-face)) ;; symbols

   ;; use package/name; (simple case)
   '("\\buse\\s-+\\([a-z_][a-zA-Z0-9_/]*\\)\\s-*;"
     (0 nil)
     (1 font-lock-constant-face)) ;; package/name

   ;; 'use' keyword itself
   '("\\buse\\b" . font-lock-keyword-face)

   ;; Built-in types
   `(,(regexp-opt '("void" "int" "char" "bool" "float" "string" "line" "word"
                    "range" "Self" "Type" "Field" "Program" "Embedded"
                    "ptr" "mut" "ref" "may" "err" "ark" "into" "fun" "itr") 'words)
     . font-lock-type-face)

   ;; Pointer/reference operators before types (*T, &T, ~T)
   '("\\([*&~]\\)\\s-*\\([A-Z][A-Za-z0-9]*\\|[a-z_][a-zA-Z0-9_]*\\)"
     (1 font-lock-keyword-face))

   ;; Generic type parameters (#A, #T) - highlight both # and name
   '("\\(#\\)\\([A-Z][A-Za-z0-9]*\\)"
     (1 font-lock-keyword-face)
     (2 font-lock-type-face))

   ;; Free type (%A)
   '("\\(%\\)\\([A-Z][A-Za-z0-9]*\\)"
	 (1 font-lock-keyword-face)
     (2 font-lock-type-face))

   ;; Interface names (_Interface) - highlight both _ and name like generics
   '("\\b\\(_\\)\\([A-Z][A-Za-z0-9]*\\)\\b"
     (1 font-lock-keyword-face)
     (2 font-lock-type-face))

   ;; CamelCase types
   '("\\b\\([A-Z][A-Za-z0-9]*\\)\\b" . font-lock-type-face)

   ;; Pipe definitions (| or |> or |- before name then ::)
   '("\\(|[->]?\\)\\s-*\\([a-z_][a-zA-Z0-9_]*\\)\\s-*::"
     2 font-lock-function-name-face)

   ;; Pipe calls (| or |> followed by name, not in a pipe signature)
   '("|[>-]?\\s-*\\([a-z_][a-zA-Z0-9_]*\\)\\(?:\\s-\\|$\\|[^:]\\)"
     1 font-lock-constant-face)

   ;; Function definitions (:: indicates function)
   '("\\([a-z_][a-zA-Z0-9_]*\\)\\s-*::" 1 font-lock-function-name-face)

   ;; Function calls
   '("\\([a-z_][a-zA-Z0-9_]*\\)\\s-*\\$" 1 font-lock-function-name-face)
   '("\\([a-z_][a-zA-Z0-9_]*\\)\\s-*<<" 1 font-lock-function-name-face)
   '("fn\\s-*\\([a-z_][a-zA-Z0-9_]*\\)" 1 font-lock-function-name-face)

   ;; Operators (including new ones: ..., $, --)
   `(,(regexp-opt '("::" "|-" "|>" "|" "=>" "->" "<<" ">>" "??" "___"
                    ".." "..<" "..." "$" "--") t)
     . font-lock-builtin-face)

   ;; Enum variants (--variant) - just the variant name, not --
   '("--\\([a-z_][a-zA-Z0-9_]*\\)" 1 font-lock-constant-face)

   ;; Variable names in declarations
   '("\\(new\\|old\\|heap\\)\\s-+\\([a-z_][a-zA-Z0-9_]*\\)"
     2 font-lock-variable-name-face)
   '("\\(,\\|:\\|)\\|over\\|in\\|=\\|for\\)\\s-+\\([a-z_][a-zA-Z0-9_]*\\)"
	 2 font-lock-variable-name-face)
   '("\\([a-z_][a-zA-Z0-9_]*\\)\\s-+|" 1 font-lock-variable-name-face)

   ;; Numbers
   '("\\b[0-9]+\\(\\.[0-9]+\\)?\\b" . font-lock-constant-face)

   ;; Special keywords
   '("\\bme\\b" . font-lock-variable-name-face))
  "Keyword highlighting for `cease-mode'.")

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

;; Navigation functions
(defun cease-goto-chevron-chevron-start ()
  "Moves to the beginning of the '<<' symbol which starts the block we're
currently in. The caller must ensure we are indeed in such a block."
  (let ((open-bracket-count 1)
		temp-start substring)

	(re-search-forward ">>")
	(re-search-backward ">>")
	(setq temp-start (point))

	(catch 'done
	  (while t
		(backward-char 1)
		(setq substring (buffer-substring-no-properties (point) (1+ temp-start)))
		(cond ((s-equals-p substring "<<") (cl-decf open-bracket-count))
			  ((s-equals-p substring ">>") (cl-incf open-bracket-count)))
		(when (= open-bracket-count 0) (throw 'done nil))
		(setq temp-start (point))))))

(defun cease-beginning-of-defun ()
  "Move to the beginning of the current function or pipe definition."
  (interactive)
  (re-search-backward
   "^\\([\[a-zA-Z_].*::\\)\\|\\(impl .*\\)\\|\\(interface \\)\\|\\(struct \\)\\|\\(enum \\)"
   nil t))

(defun cease-end-of-defun ()
  "Move to the end of the current function or pipe definition."
  (interactive)
  (if (save-excursion (beginning-of-line)
					  (looking-at-p "^[\[a-zA-Z_].*::.*=.*;$"))
	  (progn (beginning-of-line)
			 (re-search-forward "="))
	(re-search-forward "^[[:blank:]]*return\\b" nil t)
	(back-to-indentation)))

(defun cease-find-definition ()
  "Find the definition of the symbol at point."
  (interactive)
  (let ((symbol (thing-at-point 'symbol t)))
    (when symbol
      (let ((case-fold-search nil))
        (if (string-match "^[A-Z]" symbol)
            ;; Type definition
            (or (re-search-backward (concat "^\\(struct\\|enum\\|type\\|alias\\|interface\\)\\s-+" symbol "\\b") nil t)
                (re-search-forward (concat "^\\(struct\\|enum\\|type\\|alias\\|interface\\)\\s-+" symbol "\\b") nil t)
                (message "Definition of %s not found" symbol))
          ;; Function/pipe definition
          (or (re-search-backward (concat "^\\(impl\\s-+.*:\\)?\\s-*" symbol "\\s-*\\(|[>-]?\\s-*[a-z_][a-zA-Z0-9_]*\\)?\\s-*::") nil t)
              (re-search-forward (concat "^\\(impl\\s-+.*:\\)?\\s-*" symbol "\\s-*\\(|[>-]?\\s-*[a-z_][a-zA-Z0-9_]*\\)?\\s-*::") nil t)
              (message "Definition of %s not found" symbol)))))))

(defun cease-mark-defun ()
  "Mark the current function or pipe definition."
  (interactive)
  (cease-beginning-of-defun)
  (push-mark (point))
  (cease-end-of-defun)
  (exchange-point-and-mark))

;; ============================================================================
;; COMPLETION - IMPLEMENT YOUR OWN
;; ============================================================================
;; You need to define: (defun cease-completion-at-point () ...)
;; This function should return a list: (START END COLLECTION)
;; where START and END are buffer positions defining what to complete,
;; and COLLECTION is a list of completion candidates.
;;
;; To make it context-aware:
;; 1. Check if point is after | or |> -> complete only pipes
;; 2. Check if point is after . -> complete only fields
;; 3. Otherwise -> complete functions and variables
;;
;; To gather candidates:
;; - Search buffer for patterns like "functionName ::" (functions)
;; - Search for "| pipeName ::" (pipes)
;; - Search for "new varName" (variables)
;; - Search for ".fieldName" or "fieldName: Type" in structs (fields)
;;
;; Optional: add :annotation-function to show signatures
;;
;; [PUT YOUR cease-completion-at-point FUNCTION HERE]

;; Keymap
(defvar cease-mode-map
  (let ((map (make-sparse-keymap)))
    ;; TAB for indentation
    (define-key map (kbd "TAB") 'indent-for-tab-command)

    ;; Navigation
    (define-key map (kbd "C-M-a") 'cease-beginning-of-defun)
    (define-key map (kbd "C-M-e") 'cease-end-of-defun)
    (define-key map (kbd "C-M-h") 'cease-mark-defun)

    ;; Paragraph movement (treat functions as paragraphs)
    (define-key map (kbd "M-{") 'cease-beginning-of-defun)
    (define-key map (kbd "M-}") 'cease-end-of-defun)

    ;; Go to definition
    (define-key map (kbd "C-c C-d") 'cease-find-definition)

    map)
  "Keymap for `cease-mode'.")

;; Mode definition
;;;###autoload
(define-derived-mode cease-mode prog-mode "Cease"
  "Major mode for editing Cease (.stop) files.

Key bindings:
\\{cease-mode-map}"
  :syntax-table cease-mode-syntax-table
  :abbrev-table cease-mode-abbrev-table

  ;; Set up font-lock
  (setq font-lock-defaults '(cease-font-lock-keywords nil nil nil nil
                             (font-lock-multiline . t)))

  ;; Set up indentation
  (setq-local indent-line-function #'cease-indent-line)
  (setq-local tab-width 4)
  (setq-local indent-tabs-mode nil)

  ;; Set up comment syntax
  (setq-local comment-start "// ")
  (setq-local comment-end "")
  (setq-local comment-start-skip "//+\\s-*")

  ;; Navigation
  (setq-local beginning-of-defun-function #'cease-beginning-of-defun)
  (setq-local end-of-defun-function #'cease-end-of-defun)

  ;; Completion
  ;; (add-hook 'completion-at-point-functions #'cease-completion-at-point nil t)  ; Uncomment when you implement it

  ;; Electric pair mode support
  (setq-local electric-pair-pairs '((?\{ . ?\}) (?\[ . ?\]) (?\( . ?\))))
  (setq-local electric-pair-text-pairs electric-pair-pairs))

(add-hook 'cease-mode-hook #'nlinum-mode)

;; Auto-mode association
;;;###autoload
(add-to-list 'auto-mode-alist '("\\.stop\\'" . cease-mode))

(provide 'cease-mode)
;;; cease-mode.el ends here