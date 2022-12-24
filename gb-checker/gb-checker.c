#include <stdio.h>

#define CGB_INDICATOR_BYTE 0x0143

// This magic byte address signifies which versions of Game Boy consoles can
// play a specific game.
int get_magic_byte(char *filename) {
    FILE *fp;
    int magic_byte;
    fp = fopen(filename, "r");
    fseek(fp, CGB_INDICATOR_BYTE, SEEK_SET);
    magic_byte = fgetc(fp);
    fclose(fp);
    return magic_byte;
}

int main(int argc, char *argv[]) {

    int magic_byte;

    for (int i = 1; i < argc; i++) {
        magic_byte = get_magic_byte(argv[i]);
        if (magic_byte == 0xC0) {
            printf("CGB only     (0x%.2X): ", magic_byte);
        } else if (magic_byte == 0x80) {
            printf("CGB enhanced (0x%.2X): ", magic_byte);
        } else {
            printf("GB only      (0x%.2X): ", magic_byte);
        }
        printf("%s\n", argv[i]);
    }
    return 0;
}
