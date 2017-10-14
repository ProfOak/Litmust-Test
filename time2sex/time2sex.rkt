#! /usr/bin/env racket
#lang racket

; time2sex in Racket
(define (time2sex time)
  (let ([time (map string->number (string-split time ":"))])
    (for/sum ([t (reverse time)]
              [s '(1 60 3600)])
      (* t s))))

; main function
(let ([args (current-command-line-arguments)])
  (if (equal? 1 (vector-length args))
     (printf "=== ~a seconds ===\n"  (time2sex (vector-ref args 0)))
     (displayln "Please enter a command line arg\nHH:MM:SS\nEX:\n    time2sex 12:34:56")))
