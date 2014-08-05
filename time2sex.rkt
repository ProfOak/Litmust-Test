#! /usr/bin/env racket
#lang racket

; time2sex in Racket 

(define helpstring "Please enter a command line arg
HH:MM:SS
EX:
    time2sex 1:23:45")

(define (printsex s)
  (printf "=== ~a seconds ===\n" s))

(define (add-numbers n)
  (cond
    [(empty? n) 0]
    [else 
     (+ (first n) (add-numbers (rest  n)))]))

(define (get-numbers l1 l2)
  (let ([multiplied-numbers (map (lambda (a b) (* a b)) l1 l2)])
    (add-numbers multiplied-numbers )))

(define (convert time) 
  (let ([t (map string->number (string-split time ":"))])
    (cond 
    [(equal? 1 (length t))    ; seconds only
     (printsex  (list-ref t 0))]
    [(equal? 2 (length t))    ; minutes:seconds
     (printsex (get-numbers t (list 60 1)))]
    [(equal? 3 (length t))
     (printsex (get-numbers t (list 3600 60 1)))])))
     

; main function
(let ([args (vector->list (current-command-line-arguments))])
  (if (equal? 1 (length args))
     (convert (list-ref args 0))
     (displayln helpstring)))
