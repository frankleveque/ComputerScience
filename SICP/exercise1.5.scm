(define (p) 0)

(define (test x y)
  (if (= x 0)
    0 
    y))

  (test 0 (p))


; Applicative-order evaluation will cause an infinite loop. Normal-order will
; cause (p) to evaluate to 0 and the final result is 0
