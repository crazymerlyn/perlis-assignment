(defun valid (ys x)
  (not (loop for y in ys and i from 0 if (or (= x y) (= (abs (- y x)) (- (length ys) i))) collect y)))

(defun queens (n xs)
  (if (= (length xs) n)
      (list xs)
      (loop for i from 1 to n if (valid xs i) append (queens n (append xs (list i))))))
