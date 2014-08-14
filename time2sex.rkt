#! /usr/bin/env racket
#lang racket

; time2sex in Racket 

(define help-string "Please enter a command line arg\nHH:MM:SS\nEX:\n    time2sex 12:34:56")

(define (printsex s) (printf "=== ~a seconds ===\n" s))

(define (get-seconds l1 l2)
  (let ([multiplied-numbers (map * l1 l2)])
    (apply + multiplied-numbers)))

(define (convert time) 
  (let ([t (map string->number (string-split time ":"))])
    (cond 
    [(equal? 1 (length t)) (first t)]                            ; seconds only
    [(equal? 2 (length t)) (get-seconds t (list 60 1))]          ; minutes:seconds
    [(equal? 3 (length t)) (get-seconds t (list 3600 60 1))])))  ; hours:minutes:seconds
     
; main function
(let ([args (current-command-line-arguments)])
  (if (equal? 1 (vector-length args))
     (printsex (convert (vector-ref args 0)))
     (displayln help-string)))
