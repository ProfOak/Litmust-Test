package main

import (
	"flag"
	"fmt"
	"strconv"
)

func time2sex(s string) int {
	var time [3]int
	j := 2 // backward traversal
	to := len(s) - 1
	from := 0
	seconds := 0
	for i := len(s) - 1; i > 0; i-- {
		if s[i] == ':' {
			from = i + 1
			time[j], _ = strconv.Atoi(s[from : to+1])
			j--
			to = i - 1
		}
	}
	time[j], _ = strconv.Atoi(s[:to+1])

	i := 0
	conversions := [3]int{3600, 60, 1}
	for _, c := range conversions {
		seconds += time[i] * c
		i++
	}
	return seconds
}

func main() {
	flag.Parse()
	args := flag.Args()

	if len(args) == 1 {
		fmt.Println("===", time2sex(args[0]), "seconds ===")
	} else {
		fmt.Println("[Incorrect input]")
		fmt.Println("example: ./time2sex 12:34:56")
	}
}
