#lang racket

--(assoc v lst [is-equal?]) → (or/c pair? #f)
-- v : any/c  --всякакава стойност
--  lst : (listof pair?)
--  is-equal? : (any/c any/c -> any/c) = equal?
--  Locates the first element of lst whose car is equal to v according to is-equal?.
--If such an element exists, the pair (i.e., an element of lst) is returned.
--Otherwise, the result is #f.

--(lookup ([key value] ...) needle)
--Returns the first value whose key matches the needle

--2019.07
(define (recommended basket bestFit products)
  (define (findPrice product)
    (cdr (assoc product products )))
    (define basketCost
      (sum (map findPrice basket))) 
      (map
       (lambda (product)
         (bestFit product))  (filter (lambda (x) (and (not (member((bestFit x) basket)))
                     (> (basketCost basket) (findPrice (hestFit x) ))))  basket)))