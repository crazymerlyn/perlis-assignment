(defun primes (n)
  (loop
    with sieve = (make-array (1+ n) :element-type 'bit :initial-element 0)
    for i from 2 to n
    when (zerop (bit sieve i))
    collect i
    and do (loop for j from (* i i) to n by i do (setf (bit sieve j) 1))))
