#include <tokenizer.h>
#include <stdio.h>

int space_char(char c)
{
  if(c ==" " || c == "\t"){
    return 0;
  }
  return 1;
}

int non_space_char(char c)
{
  if(c == " " || c == "\t" || c == "\0"){
    return 1;
  }
  return 0;
}
