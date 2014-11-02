#lang planet neil/sicp  ;allows for full Racket and SICP compatibility

;Exercise 1.8.
;==============================================================================
;Newton's method for cube roots is based on the fact that if y is
;an approximation to the cube root of x, then a better approximation is given by
;the value (x/y^2 + 2y)/3
;
;Use this formula to implement a cube-root procedure analogous to the
;square-root procedure. (In section 1.3.4 we will see how to implement Newton's
;method in general as an abstraction of these square-root and cube-root
;procedures.)
;==============================================================================
; All that needed to be done was to replace the test in the improve procedure with
; Newton's cube root method and update names.
;

(define (cbrt x) 
  (cbrt-iter 1.0 0.0 x))

(define (cbrt-iter guess prev-guess x)
  (if (good-enough? guess prev-guess) 
    guess
    (cbrt-iter (improve guess x) guess x)))

(define (good-enough? guess prev-guess) 
  (< (abs (- guess prev-guess)) 0.00001))

(define (improve guess x) 
  (/ (+ (/ x (* guess guess)) (* 2 guess)) 3))
 

