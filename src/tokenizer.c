#include <stdio.h>
#include <string.h>
#include "tokenizer.h"

int space_char(char c)
{
  //if character is space or tab return true
  if(c ==' ' || c == '\t'){
    return 1;
  }
  return 0;
}

int non_space_char(char c)
{
  //if character is space,tab,or terminator return false
  if(c == ' ' || c == '\t' || c == '\0'){
    return 0;
  }
  return 1;
}

char *word_start(char *str)
{
  //loop until we reach a char
  while(non_space_char(str[0]) ==0){
    str++;
  }
  return str;
}

char *word_terminator(char *str)
{
  //loop until we reach ' ' , '\t' or '\0'
  while(non_space_char(str[0]) == 1){
    str++;
  }

  return str;
}

int count_words(char *str)
{
  int count = 0;

  while(1){
    //move to first char
    str = word_start(str);

    //if theres a space before the end
    if(str[1] == '\0'){
      break;
    }
    count++;

    //move to terminator char
    str = word_terminator(str);

    //if at end of setence
    if(str[0] == '\0'){
      break;
    }
  }
  printf("Number of words: %d\n", count);
  return count;
}

char *copy_str(char *str, short len)
{
  char copy[100];
  int i = 0;
  while(len != 0){
    copy[i] = str[i];
    i++;
    len--;
  }
  copy[i] = '\0';
  printf("Copy str: %d\n", copy);
  return &copy[0];
}

char **tokenize(char *str)
{
  char **tokens = (char**) malloc((count_words(str)+1), sizeof(char));
  int j = 0;
  for(int i = 0; i < strlen(str); i++){
    if(space_char(str[i])||str[i] == '\0'){
      tokens[j] = copy_str(str, i-1);
      j++;
      str = word_start(str);
    }
  }
  tokens[j] = '\0';

  return &tokens;
}
