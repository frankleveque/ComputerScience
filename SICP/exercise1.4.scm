#lang planet neil/sicp  ;allows for full Racket and SICP compatibility
; Exercise 1.4 
; Observe that our model of evaluation allows for combinations whose operators
; are compound expressions. Use this observation to describe the behavior of
; the following procedure:

(define (a-plus-abs-b a b)
  ((if (> b 0) + -) a b))

; it adds a and the absolute value of b together
