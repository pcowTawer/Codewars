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
    return --n % 9 + 1;
}

int main()
{
    printf("%i", digital_root(167346));
    return 0;
}