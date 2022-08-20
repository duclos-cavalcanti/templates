(defun _length (l)
  (if (equal l nil)
    0
    (+ 1 (_length (cdr l)))))

(defun _reverse(l)
    (if (null l)
        nil
        (append (_reverse (cdr l))
        (list (car l)))))

(defun _append (a b)
  (if (null a)
    b
    (cons (car a) (_append (cdr a) b))))

(defun _count (a l)
  (if (null l)
    0
    (if (equal a (car l))
        (+ 1 (_count a (cdr l)))
        (+ 0 (_count a (cdr l))))))

(defun _pos (a l c)
  (if (null l)
    nil
    (if (= a (car l))
     c 
     (_pos a (cdr l) (+ c 1)))))

(defun findPos (a l)
  (_pos a l 0))

; (trace rev)
(setq l (list 1 2 2 4 3))

(print l)
(print (_length l))
(print (_reverse l))
(print (cdr l))
(print (car l))
(print (cons 9 l))
(print (_append l (list 1 2)))
(print (_count 2 l))

(trace _pos)
(print (findPos 4 l))
