#lang racket
(define (merge l1 l2)
  (cond ((null? l1) l2)
        ( (null? l2) l1)
        ((< (car l1) (car l2)) (cons (car l1) (merge (cdr l1) l2)))
        (else (cons (car l2) (merge l1 (cdr l2))))))
;израз: (merge '(1 3 5 7) '(2 2 6 10))
;желана оценка: (1 2 2 3 5 6 7 10)

((lambda (x) (filter (lambda (y) (= 0 (modulo y 2))) x)) '(1 2 3 4))
;желана оценка: (2,4)