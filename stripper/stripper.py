#!/usr/bin/env python3

import argparse
import os

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('filename', help='filename to strip whitespace from')
    args = parser.parse_args()

    if not args.filename or not os.path.exists(args.filename):
        print('no')

    with open(args.filename) as f:
        contents = stripper(f.read())

    with open(args.filename, 'w') as f:
        f.write(contents)


def stripper(contents):
    contents = contents.rstrip()
    return '\n'.join([line.rstrip() for line in file_contents.split('\n')])


if __name__ == '__main__':
    main()

