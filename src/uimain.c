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
  printf("%d\n",  count_words(userIn));
  copy_str(userIn, 4);
    // }
 
  return 0;
}
