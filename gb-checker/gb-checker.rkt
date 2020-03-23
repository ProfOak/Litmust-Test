#!/usr/bin/env racket
#lang racket/base

(define (hex-formatter x)
  (let ([hex-str (format "~x" x)])
    (string-upcase (string-append
                    (if (= (string-length hex-str) 1)
                        "0x0"
                        "0x")
                    hex-str))))

(define (magic-byte in)
  (file-position in #x0143)
  (let ([byte (read-byte in)])
    (displayln (string-append (hex-formatter byte)
                              (case byte
                                [(#xC0) ": CGB only"]
                                [(#x80) ": Supports CGB"]
                                [else   ": No CGB support"])))))

(for ([filename (current-command-line-arguments)])
 (call-with-input-file filename
   (lambda (in) (magic-byte in))))