#lang racket
;2018.07

(define (addDefault val l)
(if (null? l) (list val) l))
(define (sumMinFix fl xl)
(apply +
 (map
  (lambda (f)
    (apply min
         (addDefault 0
                     (filter
                      (lambda (x) (= x (f x)) ) xl)))) fl)))


;пример:
;(sumMinFix (list (lambda (x) (/ 1 x)) exp (lambda (x) (- (* 2 x) 3)))'(-2 -1 1 3))
; ->2 (= -1 + 3)