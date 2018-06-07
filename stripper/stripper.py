#!/usr/bin/env python3

import argparse
import os

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        'filenames',
        nargs='+',
        help='filename to strip whitespace from',
    )
    args = parser.parse_args()

    for filename in args.filenames:
        if not os.path.exists(filename):
            print('Cannot open file {}'.format(filename))

        with open(filename) as f:
            contents = stripper(f.read())

        with open(filename, 'w') as f:
            f.write(contents)


def stripper(contents):
    return '\n'.join([line.rstrip() for line in contents.split('\n')]).rstrip()


if __name__ == '__main__':
    main()
