(in-package :cl-user)
(defpackage #:template.main
  (:use :cl)
  (:export #:inc))
(in-package #:template.main)

(defun inc (a)
  (+ a 1))

(defun dec (a)
  (- a 1))

(defun main ()
  (format T "Incremented to ~d" (inc 1)))
