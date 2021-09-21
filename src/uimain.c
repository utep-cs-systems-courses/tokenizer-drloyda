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
  //  printf("%d\n",  count_words(userIn));
  //copy_str(userIn, 4);
    // }
  char **tkn = tokenize(userIn);
  print_tokens(tkn);
  free_tokens(tkn);
  
  return 0;
}
