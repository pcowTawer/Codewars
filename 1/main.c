#include <stdio.h>
#include <stdbool.h>

// Complete the solution so that it returns true if the first argument(string) passed in ends with the 2nd argument (also a string).

// Examples:

// solution('abc', 'bc') // returns true
// solution('abc', 'd') // returns false


bool solution(const char *string, const char *ending)
{
    int count1, count2, i = 0;
    for(count1 = 0; string[count1]!='\0'; count1++);
    for(count2 = 0; ending[count2]!='\0'; count2++);

    if (count1 >= count2)
    {
        for(i = count1 - count2; i < count1; i++)
        {
            if(string[i]!=ending[i - count1 + count2]) return false;
        }
    }
    return true;
}

int main()
{

    printf("%i", solution("abc", "bcdeasdfasdf"));
}