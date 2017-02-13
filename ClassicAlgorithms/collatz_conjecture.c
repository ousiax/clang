#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int n;

    if(argc != 2) {
        printf("Number required!\n");
        exit(1);
    }

    n = atoi(argv[1]);

    if(n <= 0) {
        printf("Number MUST be greater than zero.\n");
        exit(1);
    }

    while(n != 1) {
        printf("%d ", n);

        if(n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
    }

    printf("%d\n", n);
    exit(0);
}
