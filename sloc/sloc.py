#!/usr/bin/env python3
import argparse
import os

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument(
        'filenames',
        nargs='+',
        help='filenames to read lines of code from',
    )
    args = parser.parse_args()

    source_lines_of_code = 0
    for filename in args.filenames:
        if not os.path.exists(filename):
            print('File not found'.format(filename))
            continue

        with open(filename) as file_pointer:
            contents = file_pointer.read()

        file_sloc = sloc(contents)
        print('{}: {}'.format(filename, file_sloc))

        source_lines_of_code += file_sloc
    print('Total: {}'.format(source_lines_of_code))


def sloc(contents):
    return sum([1 for line in contents.split('\n') if line])

if __name__ == '__main__':
    main()
