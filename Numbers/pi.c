#include <stdio.h>
#include <stdlib.h>

// pi = 4/1 - 4/3 + 4/5 - 4/7 + 4/8 - 4/9 + ...
// pi = 3 + 4/(2*3*4) - 4/(4*5*6) + 4/(6*7*8) + 4/(8*9*10) - ...
int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("An integer number required!\n");
        exit(1);
    }

    long i = 2;
    long j = i + 1;
    long k = j + 1;
    int s = -1;
    double pi = 3.0;
    double modi = 0.0;
    long n = atol(argv[1]);
    long c = 0;

    while(c <= n)
    {
        s = -s;
        modi = s * 4.0 / (i * j * k);
        pi = pi + modi;
#if 0
        printf("%.10f %.10f %d %d %d\n", pi, modi, i, j, k);
        if(c > 1000000 && pi > 3.14159267)
        {
            printf(".....\nc = %d, pi = %.20f\n", c, pi);
            break;
        }
#endif
        i = k;
        j = k + 1;
        k = j + 1;
        c++;
    }
    printf("PI = %.20f\n", pi);

    exit(0);
}
