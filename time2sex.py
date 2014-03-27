#!/usr/bin/python
import sys

def time_to_seconds(time):
    try:
        time = [ int(i) for i in time.split(":") ]
    except ValueError:
        print "Please provide valid input"
        sys.exit()

    timeLen = len(time) 
    if timeLen == 1:
        # seconds only
        return time[0]
    elif timeLen == 2:
        # minutes, seconds
        return (time[0] * 60) + time[1]
    elif timeLen == 3:
        # hours, minutes, seconds
        return (time[0]*3600) + (time[1]*60) + time[2]


if __name__ == "__main__":
    if len(sys.argv) == 2:
        print "===", time_to_seconds(sys.argv[1]), "seconds ==="
    else:
        print "Please enter a command line arg"
        print "HH:MM:SS"
        print "EX:"
        print "    time2sex 1:23:45"
