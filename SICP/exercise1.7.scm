; Exercise 1.7
; ==============================================================================
; The good-enough? test used in computing square roots will not be
; very effective for finding the square roots of very small numbers. Also, in
; real computers, arithmetic operations are almost always performed with limited
; precision. This makes our test inadequate for very large numbers. Explain these
; statements, with examples showing how the test fails for small and large
; numbers. An alternative strategy for implementing good-enough? is to watch how
; guess changes from one iteration to the next and to stop when the change is a
; very small fraction of the guess. Design a square-root procedure that uses this
; kind of end test. Does this work better for small and large numbers?
; ==============================================================================
; The original example squares the guess and subtracts that from x, the number
; we're trying to find the square root of. Then it compares that to a set
; threshold of 0.001. This was inadaquate for really small numbers because a
; wrong answer could satisfy the test. Really large numbers caused the program
; to hang due to floating point number inaccuracies. 
;

(define (sqrt x) 
  (sqrt-iter 1.0 0.0 x))

(define (sqrt-iter guess prev-guess x)
  (if (good-enough? guess prev-guess) 
    guess
    (sqrt-iter (improve guess x) guess x)))

(define (good-enough? guess prev-guess) 
  (< (abs (- guess prev-guess)) 0.00001))

(define (improve guess x) 
  (average guess (/ x guess)))

(define (average x y) 
  (/ (+ x y) 2))

