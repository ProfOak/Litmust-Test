#! /usr/bin/env racket
#lang racket

; time2secs in Racket
(define (time2secs time)
  (let ([time (map string->number (string-split time ":"))])
    (for/sum ([t (reverse time)]
              [s '(1 60 3600)])
      (* t s))))

; main function
(let ([args (current-command-line-arguments)])
  (if (equal? 1 (vector-length args))
     (printf "=== ~a seconds ===\n"  (time2secs (vector-ref args 0)))
     (displayln "Please enter a command line arg\nHH:MM:SS\nEX:\n    time2secs 12:34:56")))
