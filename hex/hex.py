#!/usr/bin/env python

import argparse
import re
import sys

def is_hex(n):
    """ Check if a number is in hexadecimal format """

    return re.match(r'^(0x)?[0-9a-fA-F]+$', n) != None

def hex2int(numbers):
    """ Print the decimal representations of a list of hexadecimal numbers """

    numbers = [ n for n in numbers if is_hex(n) ]
    for n in numbers:

        # will capitalize later
        if n.startswith('0x'):
            n = n[2:]

        print('0x{} -> {}'.format(n.upper(), int(n, 16)))


def int2hex(numbers):
    """ Print the hexadecimal representations of a list of numbers """

    numbers = [ n for n in numbers if n.isdigit() ]
    for n in numbers:
        # print the number in uppercase except for the 0x part
        print '{} -> 0x{}'.format(n, hex(int(n))[2:].upper())


def main():
    parser = argparse.ArgumentParser('./hex.py')
    parser.add_argument('direction', choices=('from', 'to'), help='The conversion direction')
    parser.add_argument('numbers', nargs='+', help='List of numbers to convert')
    args = parser.parse_args()

    convert = {
        'to':   int2hex,
        'from': hex2int,
    }

    convert[args.direction](args.numbers)

if __name__ == '__main__':
    main()

