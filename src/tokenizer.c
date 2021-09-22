#include <stdio.h>
#include <stdlib.h>
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
  char *copy = malloc(len);
  int i = 0;
  while(len != 0){
    copy[i] = str[i];
    i++;
    len--;
  }
  copy[i] = '\0';
  return copy;
}

char **tokenize(char *str)
{
  //geting size and allocating memory
  int len = count_words(str);
  char **tokens = (char**)malloc((len+1)*sizeof(char*));

  for(int i = 0; i < len; i++){
    //size of word
    short size = &*word_terminator(str) - &*word_start(str);
    //if at last word
    if(i == len-1){
      tokens[i] = copy_str(str, size-1);
      tokens[i+1] = 0;
    }
    tokens[i] = copy_str(str, size);
    str = word_terminator(str);
    str = word_start(str);
  }
  return tokens;
}

void print_tokens(char **tokens)
{
  int i = 0;
  while (*tokens) {
    printf( "[%d] %s\n",i, *tokens++ );
    i++;
  }
}

void free_tokens(char **tokens)
{
  char **q = tokens;
  while (*q) {
    free(*q++);
  }
  free(tokens);
}
