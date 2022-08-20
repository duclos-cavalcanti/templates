(defstruct node key left right)
(defun createNode (k)
        (make-node :key k))

(defun tinsert (tree n)
  (cond ((equal tree nil) n)
        ((< (node-key n) (node-key tree)) 
            (setf (node-left tree) (tinsert (node-left tree) n))
            tree)
        ((> (node-key n) (node-key tree)) 
            (setf (node-right tree) (tinsert (node-right tree) n))
            tree)
        (t (error "Duplicates not allowed"))))

(defun tmake ()
    (let ( (tree (createNode 10)) )
        (progn
            (loop for I from 0 to 2 do
               (tinsert tree (createNode (+ 9 (* 2 I))))
            )
            (print tree)
        )
    )
)

; (trace tinsert)
(tmake)



