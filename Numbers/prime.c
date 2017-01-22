#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum { true = 1, false = 0} bool;

bool is_prime(int);

int main(int argc, char *argv[])
{
    int n;

    if (argc != 2)
    {
        printf("Number required!\n");
        exit(1);
    }

    n = atoi(argv[1]);

    while ( n > 1)
    {
        if (is_prime(n) == true)
        {
            printf("%d ", n);
        }
        n--;
    }

    printf("\n");

    exit(0);
}

bool is_prime(int n)
{
    float r;
    int i;

    r = sqrtf((float)n);

    for (i = 2; i <= r; i++)
    {
        if (n % i == 0)
        {
            return false;
            break;
        }
    }

    return true;
}
