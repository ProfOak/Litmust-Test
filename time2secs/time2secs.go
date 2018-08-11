package main

import (
	"fmt"
	"os"
	"strconv"
	"strings"
)

func time2secs(str string) int {

	var (
		seconds     int
		s           int
		time        []string
		conversions [3]int
	)

	conversions = [3]int{1, 60, 3600}
	time = strings.Split(str, ":")
	reverse(time)

	for i, t := range time {
		s, _ = strconv.Atoi(t)
		seconds += s * conversions[i]
	}

	return seconds
}

func reverse(s []string) {
	for i := len(s)/2 - 1; i >= 0; i-- {
		j := len(s) - 1 - i
		s[i], s[j] = s[j], s[i]
	}
}

func main() {

	if len(os.Args) == 2 {
		fmt.Println("===", time2secs(os.Args[1]), "seconds ===")
	} else {
		fmt.Println("[Incorrect input]")
		fmt.Println("example: ./time2secs 12:34:56")
	}
}
