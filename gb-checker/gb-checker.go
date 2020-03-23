package main

import (
	"fmt"
	"log"
	"os"
)

const cgbIndicatorByte = 0x0143

func main() {
	var (
		buffer    []byte = make([]byte, 1)
		magicByte byte
	)

	for _, filename := range os.Args[1:] {
		file, err := os.Open(filename)
		if err != nil {
			log.Fatalf("Unable to open file: %s\n", filename)
		}
		defer file.Close()
		// ReadAt reads only len(buffer) amount of characters from a file. Neat!
		file.ReadAt(buffer, cgbIndicatorByte)
		magicByte = buffer[0]
		if magicByte == 0xC0 {
			fmt.Printf("0x%.2X: CGB only\n", magicByte)
		} else if magicByte == 0x80 {
			fmt.Printf("0x%.2X: Supports CGB\n", magicByte)
		} else {
			fmt.Printf("0x%.2X: No CGB support\n", magicByte)
		}
	}
}
