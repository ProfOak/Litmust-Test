#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count(char time[], char delim) {
    int sum = 0;
    int i;
    for (i = 0; time[i] != '\0'; i++)
        if (time[i] == delim)
            sum++;
    return sum;

}
int time_to_seconds(char *time) {
    char *token;
    int t[] = {0, 0, 0};
    char delim = ':';
    int time_i = count(time, delim);

    // populate array in reverse
    // depending on number of indices
    token = strtok(time, ":");
    t[time_i--] = atoi(token);

    while ((token = strtok(NULL, ":")) != NULL)
        t[time_i--] = atoi(token);

    return t[0] + t[1]*60 + t[2]*3600;
}

int main(int argc, char *args[]) {
    if (argc == 2) {
        printf("=== %d seconds ===\n", time_to_seconds(args[1]));
    }
    else {
        puts("Please enter a command line arg");
        puts("HH:MM:SS");
        puts("Example:");
        puts("time2sex 12:34:56");
    }
    return 0;
}

