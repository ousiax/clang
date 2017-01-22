
/*
 *  The following is an implementation of
 *  Sieve of Eratosthenes, which may be considered
 *  as the fastest prime number generator algorithm
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void primeGenerator(long int n);

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("usage: %s number\n", argv[0]);
        exit(1);
    }

    primeGenerator(atoi(argv[1]));
    printf("\n");
}

void primeGenerator(long int n)
{
    int i, j, count;

    // create a boolean array whose indices represent the numbers.
    bool *prime = malloc(n + 1);

    // assume all numbers from 2 - n be prime initially.
    for(i = 2; i <= n; i++)
    {
        prime[i] = true;
    }

    // we need to loop from i to sqrt(n), this can be done in a
    // faster way by looping from i to n with condition i*i <= n
    // which is faster than calculating square root.
    for(i = 2; i * i <= n; i++)
    {
        count = 0;
        // in the second loop we eliminate all multiples of i
        // from being a prime. e.g, if i = 2, we know that 4, 6, 8, 10 ...
        // will not be prime, hence we change the bool array to false for
        // all such values upto n.
        for(j = i * i; j <= n; j = i * i + count * i)
        {
            prime[j] = false;
            count++;
        }
    }

    for(i = 2; i <= n; i++)
    {
        // if prime[i] is true then we know its a prime numbers.
        if(prime[i])
        {
            printf("%d, ", i);
        }
    }
}
