#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    int r;
    unsigned int seed = 300;

    srand(seed);
    int i;

    while (1) {
        r = 33 + rand() % 93;
        putchar(r);
        if (i % 79 == 0) {
            printf("\n");
        }
    }

    return 0;
}
