#include <math.h>
#include <stdio.h>

// Digital root is the recursive sum of all the digits in a number.

// Given n, take the sum of the digits of n. 
// If that value has more than one digit, 
// continue reducing in this way until a 
// single-digit number is produced. 
// The input will be a non-negative integer.

int digital_root(int n)
{
    int buf = n;
    int i, sum = 0;
    do
    {
        sum = 0;
        for (i = 0; buf != 0; ++i)
        {
            sum += buf % 10;
            buf = buf/10;
        }
        buf = sum;
    } while (sum >= 10);
    
    return sum;
}

int main()
{
    printf("%i", digital_root(167346));
    return 0;
}