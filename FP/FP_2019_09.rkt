#lang racket

;10.09.2019

(define db (list (cons "scheme" (list (cons "typing" "dynamic") (cons "evaluation" "strict")))
(cons "haskell" (list (cons "typing" "static"))) (cons "c++" (list))))
(define (evaluation lang)
(case lang (("scheme") (list (cons "evaluation" "strict") (cons "macros" "true")))
(("haskell") (list (cons "evaluation" "lazy"))) (("c++") (evaluation "scheme"))))
(define (purity lang) (if (eqv? lang "haskell") (list (cons "pure" "true")) (list)))

;test
;(annotate db (list evaluation purity))
;(("scheme" ("macros" . "true") ("typing" . "dynamic") ("evaluation" . "strict"))
;("haskell" ("evaluation" . "lazy") ("pure" . "true") ("typing" . "static"))
;("c++" ("evaluation" . "strict") ("macros" . "true")))


(define (addIfNew x l)
  (if (not (member x l)) (cons x l)  l))
(define (annotate db annotators)
(map
(lambda (item-labels-pair)
(let ((item (car item-labels-pair)) (labels (cdr item-labels-pair)))
  (cons item (foldr addIfNew labels
(apply append (map
(lambda (annotator) (annotator item)) annotators))))))db))


