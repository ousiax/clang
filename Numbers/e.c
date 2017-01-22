#include <stdio.h>
#include <stdlib.h>

// e = 1/1 + 1/1 + 1/(1*2) + 1/(1*2*3) + 1/(1*2*3*4) + ...

static int factor(int n);

int main(int argc, char* argv[])
{
    int n;
    double e;
    if (argc != 2)
    {
        printf("Number required!\n");
        exit(1);
    }

    n = atoi(argv[1]);

    while (n >= 0)
    {
        e += 1.0 / factor(n);
        n--;
    }

    printf("e = %.20lf\n", e);

    return 0;
}

static int factor(int n)
{
    if (n <= 0)
    {
        return 1;
    }
    else
    {
        return n * factor(n - 1);
    }
}
