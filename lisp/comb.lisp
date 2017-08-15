(defun comb (str)
  (if str
    (let ((restcomb (comb (cdr str))))
      (append restcomb (map 'list #'(lambda (c) (cons (car str) c)) restcomb)))
    (list str)))

