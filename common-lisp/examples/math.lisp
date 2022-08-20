(defun add_let (a b)
    (let ( (r (+ a b)) 
         )
      r)
)

(defun sub(x y)
    (- x y))

(defun add(x y)
    (+ x y))

(defun div(x y)
    (/ x y))

(defun mul(x y)
    (* x y))

(defun sqr(x)
    (* x x))

(defun cube(x)
    (* x x x ))

(defun recMul(a b)
    (if (= b 1)
         a 
         (+ a (recMul a (- b 1)))))

(defun recPow(a b)
    (if (= b 1)
         a 
         (* a (recPow a (- b 1)))
    )
)

(defun fact(n)
    (if (= n 0)
        1
        (* n (fact(- n 1))))
)

(print (add 12 (cube 10))); prints 1012

(print (recMul 2 3))

(print (recPow 2 3))

(trace fact)
(fact 4)

(print (add_let 2 3))
