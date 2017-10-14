#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define str_eq(a, b)    (strcmp(a, b) == 0)
#define is_digit(n)     (n >= '0' && n <= '9')
#define is_hex_digit(n) (is_digit(n) || ('a' <= n && n <= 'f') || ('A' <= n && n <= 'F' ))

int usage();

bool is_number(char[]);
bool is_hex_number(char[]);

void to_hex(char[]);
void from_hex(char []);

int main(int argc, char *argv[]) {

    if (argc < 3) {
        return usage();
    }

    if (str_eq(argv[1], "to")) {
        // for each element in argv[2:] convert to hex

        for (int i = 2; i < argc; i++) {
            if (!is_number(argv[i])) {
                printf("%s is not a valid number\n", argv[i]);
            } else {
                to_hex(argv[i]);
            }
        }
    }

    else if (str_eq(argv[1], "from")) {
        // for each element in argv[2:] convert to decimal

        for (int i = 2; i < argc; i++) {
            if (!is_hex_number(argv[i])) {
                printf("%s is not a valid hex number\n", argv[i]);
            } else {
                from_hex(argv[i]);
            }
        }
    }

    else {
        return usage();
    }

    return 0;
}

int usage() {
    // print and exit

    printf("Usage\n");
    printf("    hex to 1234 4321\n");
    printf("    hex from cafe babe\n");
    return 1;
}

bool is_hex_number(char str[]) {
    // verify that the string is a hexadecimal number

    int i = 0;
    if (strncmp("0x", str, 2) == 0) {
        i = 2;
    }

    for ( ; i < strlen(str); i++) {
        if ( !is_hex_digit(str[i]) ) {
            return false;
        }
    }

    return true;
}

bool is_number(char str[]) {
    // verify that the string is a decimal number

    for (int i = 0; i < strlen(str); i++) {
        if ( !is_digit(str[i]) ) {
            return false;
        }
    }

    return true;
}

void to_hex(char str[]) {
    // print out the string in hex format

    printf("%s -> 0x%X\n", str, atoi(str));
}

void from_hex(char str[]) {
    // print out the string in decimal format

    char tmp[strlen(str) + 2];

    // make sure it begins with 0x
    if (strncmp("0x", str, 2) != 0) {
        sprintf(tmp, "0x%s", str);
    } else {
        sprintf(tmp, "%s", str);
    }

    // set all hex letters to uppercase
    for (int i = 2; i < strlen(tmp); i++) {

        // not a digit and a-f
        if (!is_digit(tmp[i]) && !isupper(tmp[i])) {
            tmp[i] = toupper(tmp[i]);
        }

        // is already a digit and is not a-f
        else {
            tmp[i] = tmp[i];
        }
    }

    printf("%s -> %d\n", tmp, (int)strtol(tmp, NULL, 0));
}
