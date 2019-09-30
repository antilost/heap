/*
 * gcc prime_factor_decomposition.c -lm
 * 
 */


#include <stdio.h>
#include <math.h>

main()
{
    long int b, n, d, i;
    scanf("%ld", &n);

    d = 2;
    while (n > 1)
    {
        b = n % d;

        //printf("%ld %ld %ld\n", n, d, b);

        if (b == 0)
        {
            printf("%ld\n", d);
            n /= d;
        }
        else
        {
            int next_div_not_found = 1;
            while (next_div_not_found)
            {
                d++;
                int is_prime = 1;
                for (i = 2; i < (long int)sqrt(d); i++)
                {
                    if (d % i == 0)
                    {
                        is_prime = 0;
                        break;
                    }
                }
                
                if (is_prime)
                    break;
            }
        }
    }
    
}