time2sex
========

A command line utility to convert standard time (HH:MM:SS) into seconds.

Why?
====

A while ago I was playing Minesweeper and the client I was using displayed time in an MM:SS format, and I preferred seconds only, so I made this. After I made a version in python I challenged myself to use my beginner C skills and come up with a C solution.

**Usage:**


Python
------

Add executable privileges to the python file with chmod.

[chmod examples](http://www.thegeekstuff.com/2010/06/chmod-command-examples/)

```
$ chmod u+x time2sex.py
$ ./time2sex.py 12:34:56
=== 45296 seconds ===
```

C
-

```
$ gcc -o time2sex time2sex.c
$ ./time2sex 12:34:56
=== 45296 seconds ===
```

Go
--

```
$ go build time2sex.go
$ ./time2sex 12:34:56
=== 45296 seconds ===
```
