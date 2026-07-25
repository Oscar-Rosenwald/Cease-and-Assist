# Build the tree-sitter grammar and compile the shared object
build-parser:
    cd emacs-lisp && fnm exec --using=22 npx tree-sitter generate
    cd emacs-lisp && gcc -shared -fPIC -Isrc src/parser.c -o ~/.emacs.d/tree-sitter/libtree-sitter-cease.so
