#!/usr/bin/env python

import argparse


# This byte stores information on what Game Boys a rom will work on.
CGB_INDICATOR_BYTE = 0x0143


def get_magic_byte(filename: str) -> int:
    with open(filename, "rb") as f:
        f.seek(CGB_INDICATOR_BYTE)
        return int(f.read(1).hex().upper())


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("filenames", nargs="+", help="list of files to check")
    args = parser.parse_args()

    for filename in args.filenames:
        magic_byte = get_magic_byte(filename)
        if magic_byte == "C0":
            print(f"CGB only     (0x{magic_byte:02x}): {filename}")
        elif magic_byte == "80":
            print(f"CGB enhanced (0x{magic_byte:02x}): {filename}")
        else:
            print(f"GB only      (0x{magic_byte:02x}): {filename}")


if __name__ == "__main__":
    main()
