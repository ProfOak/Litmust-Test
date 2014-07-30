time2sex
========

A command line utility to convert standard time (HH:MM:SS) into seconds.

Why?
====

A while ago I was playing Minesweeper and the client I was using displayed time in an MM:SS format, and I preferred seconds only, so I made this. After I made a version in python I challenged myself to use my beginner C skills and come up with a C solution.

**Test usage:**


Python
------

```
$ make py 
$ ./time2sex 12:34:56
=== 45296 seconds ===
```

C
-

```
$ make c
$ ./time2sex 12:34:56
=== 45296 seconds ===
```

Go
--

```
$ make go
$ ./time2sex 12:34:56
=== 45296 seconds ===
```

Instal
-----

Just add install at the end of the one you want to compile

Python
------
`make py install`

C
-
`make c install`

Go
--
`make go install`

