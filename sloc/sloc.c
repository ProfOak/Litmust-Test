#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int sloc(char *buffer);
char *read_file(char *filename);
void usage(void);

int main(int argc, char **argv) {
    int source_lines_of_code = 0;
    int file_sloc;

    if (argc == 1) {
        usage();
    }

    for (int i = 1; i < argc; i++) {
        file_sloc = sloc(argv[i]);
        printf("%s: %d\n", argv[i], file_sloc);
        source_lines_of_code += file_sloc;
    }
    printf("Total: %d\n", source_lines_of_code);

    return 0;
}


int sloc(char *filename) {
    int count = 0;
    char *buffer = read_file(filename);
    char *token;

    while ((token = strsep(&buffer, "\n")) != NULL) {
        if (strncmp(token, "", 1) != 0) {
            count++;
        }
    }

    free(buffer);
    return count;
}


char *read_file(char *filename) {

    int file_size;
    char *buffer;
    FILE *file_pointer;

    file_pointer = fopen(filename, "r");
    if (!file_pointer) {
        printf("Cannot open file: %s\n", filename);
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

    return buffer;
}


void usage(void) {
    puts("Usage:");
    puts("    sloc filename.txt [filename2.txt ...]");
    exit(0);
}
