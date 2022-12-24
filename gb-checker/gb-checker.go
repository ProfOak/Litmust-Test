package main

import (
	"fmt"
	"log"
	"os"
)

const cgbIndicatorByte = 0x0143

func getMagicByte(filename string) byte {
	var (
		buffer    []byte = make([]byte, 1)
		magicByte byte
	)
	file, err := os.Open(filename)
	if err != nil {
		log.Fatalf("Unable to open file: %s\n", filename)
	}
	defer file.Close()

	// ReadAt reads only len(buffer) amount of characters from a file. Neat!
	file.ReadAt(buffer, cgbIndicatorByte)
	magicByte = buffer[0]
	return magicByte

}

func main() {

	for _, filename := range os.Args[1:] {
		var magicByte byte = getMagicByte(filename)
		if magicByte == 0xC0 {
			fmt.Printf("CGB only     (0x%.2X): ", magicByte)
		} else if magicByte == 0x80 {
			fmt.Printf("CGB enhanced (0x%.2X): ", magicByte)
		} else {
			fmt.Printf("GB only      (0x%.2X): ", magicByte)
		}
		fmt.Println(filename)
	}
}
