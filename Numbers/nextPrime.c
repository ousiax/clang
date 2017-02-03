#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef enum { true = 1, false = 0} bool;

bool is_prime(int);

int main()
{
    int n;

    while (true)
    {
        printf("Next number (0 for exit): ");
        scanf("%d", &n);
        if (n == 0)
        {
            exit(0);
        }
        while (true)
        {
            if (is_prime(n) == true)
            {
                printf("%d\n", n);
                break;
            }
            n++;
        }
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
