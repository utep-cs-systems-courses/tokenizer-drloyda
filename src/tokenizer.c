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
  int i = 0;
  while(non_space_char(str[i]) ==0){
    i++;
  }
  return &str[i];
}

char *word_terminator(char *str)
{
  int i = 0;
  while(space_char(str[i]) == 0){
    i++;
  }
  //printf("%s\n", &str[i]);
  return &str[i];
}

int count_words(char *str)
{
  int count = 0;
  int i = 0;
  while(1){
    //moves to start of the word
    word_start(&str[i]);
    //if at end of word, count it
    if(space_char(str[i]) && str[i+2] != '\0'){
      count++;
    }

    //if at end of sentence
    if(str[i] == '\0' && count != 0){
      count++;
      // printf("%d\n", count);
      return count;
    }
    
    //if sentence is empty
    else if (str[i] == '\0' && count == 0){
      //printf("%d\n", count);
      return count;
    }
    i++;
  }
  return 0;
}
