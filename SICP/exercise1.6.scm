#lang planet neil/sicp  ;allows for full Racket and SICP compatibility

(define (abs x)
  (cond ((< x 0) (- x))
        (else x)))

(define (square x)
  (* x x))

(define (average x y)
  (/ (+ x y) 2))

(define (improve guess x)
  (average guess (/ x guess)))

(define (good-enough? guess x)
  (< (abs (- (square guess) x)) 0.001))


(define (new-if predicate then-clause else-clause)
  (cond (predicate then-clause)
        (else else-clause)))
 
(define (sqrt-iter guess x)
  (new-if (good-enough? guess x)
          guess
          (sqrt-iter (improve guess x)
                     x)))
(sqrt-iter 1.0 81)

;eevaluation runs out of memory
