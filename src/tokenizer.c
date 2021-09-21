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
  char **tokens = (char**)malloc(((count_words(str)+1)*sizeof(char*)));
  int i=0,j=0;
  
  //move to start of sentence
  str = word_start(str);
  while(1){
    if(space_char(str[i]) || str[i] == '\0'){
      //if at end of word copy last word and add terminator
      if(str[i] == '\0'){
	tokens[j] = copy_str(str, i-1);
	j++;
	tokens[j] = 0;
	break;
      }else{
	//if in between words, add the previous word
	tokens[j] = copy_str(str, i);
	str = word_terminator(str);
	str = word_start(str);
	j++;
	i = 0;
      }
    }
    i++;
  }
  //printf("[0] %s\n", tokens[0]);
  //printf("[1] %s\n", tokens[1]);
  //printf("[2] %s\n", tokens[2]);
  //printf("[3] %s\n", tokens[3]);
  //printf("[4] %s\n", tokens[4]);
  return tokens;
}

void print_tokens(char **tokens)
{
  for(int i = 0; i < strlen(*tokens); i++){
    printf("[%d] %s\n",i, tokens[i]);
  }
}

void free_tokens(char **tokens)
{
  free(tokens);
}
