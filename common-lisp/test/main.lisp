(defpackage #:template/test.main
            (:use :cl :prove :template.main))
(in-package #:template/test.main)

(plan nil)

(subtest "Inc test"
  (is (inc 1) 2))

(finalize)
