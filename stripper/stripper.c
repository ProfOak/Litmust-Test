#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define is_space(c)      (c == ' ' || c == '\t')
#define is_newline(c)    (c == '\n' || c == '\r')
#define is_whitespace(c) (is_space(c) || is_newline(c))

void usage(void);
char *stripper(char *buffer, unsigned int file_size);
char *rstrip(char *line);

int main(int argc, char **argv) {
    int file_size;
    char *buffer;
    FILE *file_pointer;

    if (argc != 2) {
        usage();
    }

    file_pointer = fopen(argv[1], "r");
    if (!file_pointer) {
        printf("Cannot open file %s\n", argv[1]);
        exit(1);
    }

    // Get the file size to malloc just enough memory to store the file in
    // a buffer.
    fseek(file_pointer, 0, SEEK_END);
    file_size = ftell(file_pointer);
    fseek(file_pointer, 0, SEEK_SET);

    // Dump contents of file into buffer.
    buffer = malloc(sizeof(char) * file_size);
    fread(buffer, file_size, 1, file_pointer);
    fclose(file_pointer);

    buffer = stripper(buffer, file_size);
    file_pointer = fopen(argv[1], "w");
    fprintf(file_pointer, buffer, 1);
    fclose(file_pointer);
}


/**
 * usage prints the usage message then exists successfully.
 */
void usage(void) {
    puts("Usage:");
    puts("    stripper filename.txt");
    exit(0);
}


/**
 * stripper replaces the end of each line with 0's so they don't get
 * written to the file.
 */
char *stripper(char *buffer, unsigned int file_size) {

    // The new buffer will be at most as large as the original buffer.
    char *new_buffer = malloc(sizeof(char) *file_size);
    char *token;

    // Zero out new buffer to later append to it.
    for (unsigned int i = 0; i < file_size; i++) {
        new_buffer[i] = 0;
    }

    // Strip the end of the file of all whitespace.
    for (int i = file_size-1; i >= 0; i--) {
        if (is_whitespace(buffer[i])) {
            buffer[i] = 0;
        } else {
            break;
        }
    }

    while ((token = strsep(&buffer, "\n")) != NULL) {
        strcat(new_buffer, rstrip(token));
        strcat(new_buffer, "\n");
    }

    return new_buffer;
}


/**
 * rstrip replaces all trailing whitespace with 0's.
 */
char *rstrip(char *line) {
    for (int i = strlen(line)-1; i >= 0; i--) {
        if (is_space(line[i])) {
            line[i] = 0;
        } else {
            break;
        }
    }
    return line;
}
