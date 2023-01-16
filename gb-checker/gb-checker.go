package main

import (
	"flag"
	"fmt"
	"log"
	"os"
)

type fileData struct {
	Filename      string
	Indicatorbyte byte
}

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
	var (
		magicByte   byte
		gbOnly      []fileData
		cgbEnhanced []fileData
		cgbOnly     []fileData
	)

	flag.Parse()

	for _, filename := range flag.Args() {
		magicByte = getMagicByte(filename)
		switch magicByte {
		case 0xC0:
			cgbOnly = append(cgbOnly, fileData{filename, magicByte})
		case 0x80:
			cgbEnhanced = append(cgbEnhanced, fileData{filename, magicByte})
		default:
			gbOnly = append(gbOnly, fileData{filename, magicByte})
		}
	}
	for _, data := range cgbOnly {
		fmt.Printf("CGB only     (0x%.2X): %s\n", data.Indicatorbyte, data.Filename)
	}
	for _, data := range cgbEnhanced {
		fmt.Printf("CGB enhanced (0x%.2X): %s\n", data.Indicatorbyte, data.Filename)
	}
	for _, data := range gbOnly {
		fmt.Printf("GB only      (0x%.2X): %s\n", data.Indicatorbyte, data.Filename)
	}
}
