#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Trolls are attacking your comment section!

// A common way to deal with this situation is to remove all of the vowels from the trolls' comments, neutralizing the threat.

// Your task is to write a function that takes a string and return a new string with all vowels removed.

// For example, the string "This website is for losers LOL!" would become "Ths wbst s fr lsrs LL!".

// Note: for this kata y isn't considered a vowel.

//solution must allocate all required memory
//and return a free-able buffer to the caller.

char* vowels = "euioaEUIOA";

bool in_vowels(const char c)
{
    int i;
    for (i = 0; vowels[i] != '\0'; ++i)
        if (c == vowels[i])
            return true;
    return false;    
}


char *disemvowel(const char *str)
{
    int i, count = 0;
    for (i = 0; str[i]; i++)
        if (in_vowels(str[i]))
            ++count;
    printf("\n%i", count);

    return "";
}

int main()
{
    char* str = "This website is for losers LOL!";
    printf("%s", str);
    disemvowel(str);
}