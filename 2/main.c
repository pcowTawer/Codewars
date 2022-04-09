#include <stdio.h>
#include <stdlib.h>


// Write a function that takes in a string of one or more words, 
// and returns the same string, but with all five or more letter 
// words reversed (Just like the name of this Kata). 
// Strings passed in will consist of only letters and spaces. 
// Spaces will be included only when more than one word is present.

// Examples: 
// spinWords( "Hey fellow warriors" ) => returns "Hey wollef sroirraw" 
// spinWords( "This is a test") => returns "This is a test" 
// spinWords( "This is another test" )=> returns "This is rehtona test"

void spin_words(const char *sentence, char *result) 
{
    int len;
    for(len = 0; sentence[len] != '\0'; ++len);


    int wlen, i, j;
    for(i = 0; i < len;)
    {
        for(wlen = 0, j = i; sentence[j] != ' ' && sentence[j] != '\0'; ++wlen, ++j);
        if (wlen < 5) 
        {
            for(j = i; sentence[j] != ' ' && sentence[j] != '\0'; ++j)
                result[j] = sentence[j];
            result[j] = sentence[j];
            i = i + wlen + 1;
            continue;
        }
        for (j = i + wlen - 1; j > i - 1; --j)
            result[2*i + wlen - j - 1] = sentence[j];
        result[i + wlen] = sentence[i + wlen];
        i = i + wlen + 1;
    }
}

void spin_words2(const char *sentence, char *result) {
  int count = 0, i, j;
  for(i = 0; sentence[i]!='\0'; i++)
  {
    if(sentence[i+1]==' ' || sentence[i+1]=='\0')
    {
      count++;
      if(count>=5)
      {
        for(j = 0; j<count; j++) 
          result[i+1-count+j]=sentence[i-j];
      }
      else 
      {
        for(j = 0; j<count; j++) 
          result[i-j]=sentence[i-j];
      }
      count = -1;
      result[i+1]=sentence[i+1];
    }
    else count++;
  }
}

int main(int argc, char const *argv[])
{
    char* sentence = "Welc my dear friend";
    char* result = (char*)malloc(sizeof(char) * 100);
    spin_words2(sentence, result);
    printf("%s", result);
    return 0;
}
