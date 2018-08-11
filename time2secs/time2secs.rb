#!/usr/bin/env ruby

def time2secs(time)
    secs = [1, 60, 3600]
    time = time.split(":").reverse
    seconds = 0

    for i in 0..time.length-1
        seconds +=  secs[i] * time[i].to_i
    end

    return "=== " + seconds.to_s + " seconds ==="
end

if ARGV.length == 1
    puts time2secs(ARGV[0])
else
    puts "Please enter a command line arg"
    puts "HH:MM:SS"
    puts "EX:"
    puts "    time2secs 12:34:56"
end
