#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    unsigned int data, char_frequency[256] = {0};

    FILE *fptr;

    fptr = fopen(argv[1], "rb");

    if(!fptr) {
        printf("File not found.");
        fclose(fptr);
        exit(0);
    }

    while(fread(&data, 1, 1, fptr)) {
        char_frequency[data]++;
    }

    printf("The Frequency of character in this file.\n");
    printf("FREQUENCY\n");

    for(int i = 0; i < 256; i++) {
        printf("\t%3d(%c). %d\n", i, isprint(i) ? i: 32, char_frequency[i]);
    }
    return 0;
}
