#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

void splitToInts(char *str, int t[], char delimiter) {
    // 3 numbers X 3 = 2 didgits and a null char
    char tmp[3][3];
    
    // split by ':'
    int i;
    int j = 0, k = 0;

    int slen = strlen(str);
    for (i = 0; i < slen; i++) {
        // found a match, separate by delimiter
        if (str[i] == delimiter && j < 3) {
            tmp[j++][k] = '\0';
            k = 0;
        }
        else {
            tmp[j][k++] = str[i];
        }
    }
    
    // ascii to int conversion
    for (i = 0; i <= j; i++) 
         t[i] = atoi(tmp[i]);
    
    // Goal is to have the format HH:MM:SS for time
    // Hours and Minutes not present in input (seconds only)
    if (t[2] == 0 && t[1] == 0) { 
       // seconds to the end
        swap(&t[0], &t[2]);
    }
    // Minutes and seconds only
    else if (t[2] == 0) {
        swap(&t[0], &t[2]);
        swap(&t[1], &t[2]);
    }
}

int time_to_seconds(char *time) {
    // t = {HH,MM,SS}
    int t[] = {0, 0, 0}; 
    int seconds = 0;
    
    // split by ':' and store in array 't'
    splitToInts(time, t, ':');

    // total seconds 
    return t[0]*3600 + t[1]*60 + t[2];    
}

int main(int argc, char *args[]) {
    if (argc == 2)
        // basically the entire program
        printf("=== %d seconds ===\n", time_to_seconds(args[1]));
    else {
        puts("Please enter a command line arg");
        puts("HH:MM:SS");
        puts("Example:");
        puts("time2sex 1:23:45");
    }
    return 0;
}


