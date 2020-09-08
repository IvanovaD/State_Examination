#lang racket
( map ( lambda (x) (append (list x) x) ) '( (1 2) (3 4) ) )
; (append (list (1 2)) (1 2)) -> (append ((1 2)) (1 2)) -> ((1 2) 1 2) 
; (append (list (3 4)) x) -> ((3 4) 3 4)
;->''(((1 2) 1 2) ((3 4) 3 4))

( map ( lambda (f) ( map (lambda (x) (f 5 x)) '(1 2 3) ) ) (list + *))
;(list + *) ->'(+ *)
;(map (f 5 x) '(1 2 3)) -> '((f 5 1) (f 5 2) (f 5 3))
;- > ((6 7 8) (5 10 15))

( apply list (list (quote +) (quote 5) 8) )
;Оценка: (list (quote +) (quote 5) 8) -> '('+ '5 8)
;'(+ 5 8)