(ql:quickload :prove)  ; because of prove-asdf
(ql:quickload :template)
(in-package :template.main)
(sb-ext:save-lisp-and-die
 "template"
 :toplevel #'main :executable t :compression 9)
