#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  List* list =init_history();
  while(1){
    puts("Type a sentence to tokenize it(h = Print History, !<num> = Get History, q = Quit Program)");
    char *userIn = (char*)malloc(sizeof(char*));
    fgets(userIn, 100, stdin);

    if(*userIn == '\n'){
      break;

    }else if(strcmp(userIn,"h\n") == 0){
      print_history(list);
      free_history(list);

    }else if(userIn[0] == '!'){
      int x = userIn[1] - '0';
      printf("Got node at id: %d\n", x);
      printf("H[%d] %s\n", x, get_history(list, x));

    }else if(strcmp(userIn,"q\n") == 0){
      puts("Goobdbye");
      break;
    }else{
      puts("------Tokenized String------");
      char ** tkns = tokenize(userIn);
      free_tokens(tkns);
      add_history(list, userIn);
    }
  }
  return 0;
}
