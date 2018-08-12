package main

import (
	"bytes"
	"fmt"
	"io/ioutil"
	"os"
)

func main() {
	if len(os.Args) == 1 {
		usage()
		return
	}

	for _, filename := range os.Args[1:] {
		stripFile(filename)
	}
}

// stripFile reads in a file, strips the whitespace, then overwrites
// the same file.
func stripFile(filename string) {
	var (
		buffer []byte
		err    error
	)
	buffer, err = ioutil.ReadFile(filename)
	if err != nil {
		panic(err)
	}
	buffer = stripper(buffer)

	if err = ioutil.WriteFile(filename, buffer, 0644); err != nil {
		panic(err)
	}
}

// stripper removes the whitespace from the file. First removing the trailing
// newlines, then trimming the whitespace from the edges of source lines.
func stripper(buffer []byte) []byte {

	var (
		i      int
		result []byte
		line   []byte
		lines  [][]byte
	)

	// Only start counting from the last character that's not whitespace.
	for i = len(buffer) - 1; i > 0; i-- {
		if !isWhitespace(buffer[i]) {
			break
		}
	}
	lines = bytes.Split(buffer[:i+1], []byte{'\n'})

	for _, line = range lines {
		line = bytes.TrimRight(line, " \t")
		line = append(line, '\n')
		result = append(result, line...)
	}

	return result
}

// isWhitespace checks if a character is a newline, a space, or a tab.
func isWhitespace(char byte) bool {
	return char == '\n' || char == '\r' || char == ' ' || char == '\t'
}

func usage() {
	fmt.Println("Usage:")
	fmt.Println("    stripper filename.txt [filename2.txt ...]")
}
