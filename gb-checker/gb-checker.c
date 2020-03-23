#include <stdio.h>

#define CGB_INDICATOR_BYTE 0x0143

int main(int argc, char *argv[]) {

    FILE *fp;
    int magic_byte;

    for (int i=1; i<argc; i++) {
        fp = fopen(argv[i], "r");
        fseek(fp, CGB_INDICATOR_BYTE, SEEK_SET);
        magic_byte = fgetc(fp);
        if (magic_byte == 0xC0) {
            printf("0x%.2X: CGB only\n", magic_byte);
        } else if (magic_byte == 0x80) {
            printf("0x%.2X: Supports CGB\n", magic_byte);
        } else {
            printf("0x%.2X: No CGB support\n", magic_byte);
        }
        fclose(fp);
    }
    return 0;
}
