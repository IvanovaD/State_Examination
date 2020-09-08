#lang racket
;09.2018

(define (selectList l1 l2)
(if (>= (length l1) (length l2)) l1 l2))
(define (sumMaxRoots f ll)
  (apply +
       (foldr  selectList  '()
               (map (lambda (l)
                             (filter (lambda (x) (= (f x) 0)) l)) ll))))


;Пример:
;(sumMaxRoots (lambda (x) (- (* x x x) x)) '((1 2 3) (-1 0 5) (1 4 -1))) → -1