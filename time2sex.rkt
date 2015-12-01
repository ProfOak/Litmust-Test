#! /usr/bin/env racket
#lang racket

; time2sex in Racket

(define (get-seconds l1 l2)
  (let ([multiplied-numbers (map * l1 l2)])
    (apply + multiplied-numbers)))

(define (convert time)
  (let ([t (map string->number (string-split time ":"))])
    (case (length t)
    [(1) (first t)]                            ; seconds only
    [(2) (get-seconds t (list 60 1))]          ; minutes:seconds
    [(3) (get-seconds t (list 3600 60 1))])))  ; hours:minutes:seconds

; main function
(let ([args (current-command-line-arguments)])
  (if (equal? 1 (vector-length args))
     (printf "=== ~a seconds ===\n"  (convert (vector-ref args 0)))
     (displayln "Please enter a command line arg\nHH:MM:SS\nEX:\n    time2sex 12:34:56")))
