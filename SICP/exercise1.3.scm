#lang planet neil/sicp  ;allows for full Racket and SICP compatibility
; Exercise 1.3 
; Define a procedure that takes three numbers as arguments and returns
; the sum of the squares of the two larger numbers.

(define (getbigger x y) 
  (if (> x y) x y))

(define (square x)
  (* x x))

(define (square-sum-larger a b c)
 (if (> a b)  
 (+ (square a) (square (getbigger b c)))
 (+ (square b) (square (getbigger a c))) ))