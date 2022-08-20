(defun my_abs(x)
    (cond ((> x 0) x)
          ((= x 0) 0)
          ((< x 0) (- x))
    )
)

(defun fun(x)
    (if (< x 20)
        (progn
                (print "cold")
                (+ x 100))
        (progn
                (print "hot")
                (- x 5)))
)

(fun (fun 10))
(print (my_abs 10))
(print (my_abs -10))
; first should print cold, since 10 is smaller 20, it will however return 110
; this will be used in the second run of fun which will now make it above 20
; so hold will be printed
