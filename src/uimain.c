#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"

int main()
{
  char userIn[1001];
  // while(1){
  puts("$");
  fgets(userIn, 100, stdin);
  printf("%s\n", userIn);
  word_start(userIn);
    // }
 
  return 0;
}
