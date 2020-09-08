#lang racket
;2016.09

(define (filterByElement x m)
  (filter (lambda (l) (member x l)) m))

;израз: ( filterByElement 2 '( (1 2 3) (2 3 4) (3 4 5) ) )
;желана оценка: ( (1 2 3) (2 3 4) )

;( apply + ( map ( lambda (l) (apply max l) ) ' ( (5 -2) (1 9) (6 -8) ) ) ) --> 20