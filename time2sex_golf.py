#!/usr/bin/python
import sys
print "=== %s seconds ===" % sum( [[1,60,3600][i] * int(j) for i, j in enumerate(reversed(sys.argv[1].split(":")[:3]))] )
