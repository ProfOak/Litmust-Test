#!/usr/bin/env python

import argparse


# This byte stores information on what Game Boys a rom will work on.
CGB_INDICATOR_BYTE = 0x0143

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('filenames', nargs='+', help='list of files to check')
    args = parser.parse_args()

    for filename in args.filenames:
        with open(filename, 'rb') as f:
            f.seek(CGB_INDICATOR_BYTE)
            magic_byte = f.read(1).hex().upper()

            if magic_byte == 'C0':
                print('0x{}: CGB only'.format(magic_byte))
            elif magic_byte == '80':
                print('0x{}: Supports CGB'.format(magic_byte))
            else:
                print('0x{}: No CGB support'.format(magic_byte))

if __name__ == '__main__':
    main()
