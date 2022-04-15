// Write a function that takes a string of parentheses, 
// and determines if the order of the parentheses is valid. 
// The function should return true if the string is valid, 
// and false if it's invalid.

// Examples
// "()"              =>  true
// ")(()))"          =>  false
// "("               =>  false
// "(())((()())())"  =>  true

// Constraints
// 0 <= input.length <= 100
// Along with opening (() and closing ()) parenthesis, 
// input may contain any valid ASCII characters. 
// Furthermore, the input string may be empty and/or 
// not contain any parentheses at all. Do not treat other forms 
// of brackets as parentheses (e.g. [], {}, <>).

#include <stdbool.h>
#include <stdio.h>

#include <stdbool.h>

bool validParentheses(const char *str_in) 
{
  int i, count_of_not_closed = 0, count_of_opener = 0, count_of_closer = 0;
  for(i = 0; str_in[i] != '\0'; ++i)
  {
    if (str_in[i] == '(') ++count_of_opener;
    if (str_in[i] == ')') 
    {
        ++count_of_closer;
        count_of_not_closed = count_of_opener - count_of_closer;
        if (count_of_not_closed < 0)    return false;
    }
  }
  return (bool)(count_of_closer == count_of_opener);
}

#include <stdbool.h>

bool validParentheses2(const char* strin)
{
    int c = 0;
    while(*strin) {
        switch(*strin) {
            case '(':
                c++; break;
            case ')':
                if (c == 0) return false;
                c--; break;
        }
        strin++;
    }

    return c == 0;
}

bool validParentheses3(const char* strin) {
    int k = 0;
    for (const char *p = strin; *p && k >= 0; ++p) {
        k += *p == '(';
        k -= *p == ')';
    }
    return k == 0;
}

int main()
{
    printf("%d", validParentheses("(()) ( (()) (()) )(())"));
    
    return 0;
}