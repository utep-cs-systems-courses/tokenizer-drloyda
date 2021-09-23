#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

List* init_history(){
  List* list = (List*) malloc(sizeof(List));
  return list;
}

void add_history(List *list, char *str)
{
  int id = 1;
  //creating new node and a temp head node
  Item* new_node = (Item*) malloc(sizeof(Item));

  //new_node->str = (char*)malloc(sizeof(struct s_Item*));
  new_node->str = str;

  Item* temp = list->root;

  //if list is empty
  if (!list->root){
    new_node->id = 0;
    list->root = new_node;
    return;
  }
  //go to last node
  while (temp->next){
    temp = temp->next;
    id++;
  }
  new_node->id = id;
  temp->next = new_node;
  new_node->next = NULL;
  return; 
}

char *get_history(List *list, int id)
{
  //creating temp node
  Item* temp = list->root;

  //go to node at id
  while (temp) {
    if(temp->id == id){
      break;
    }
    temp = temp->next;
  }
  
  if(id > temp->id){
    puts("Entered id is greater than list length:\n Returning last node id.");
  }
  return temp->str;
}

/*Print the entire contents of the list. */

void print_history(List *list)
{
  puts("------Printing History------");

  Item* temp = list->root;
  while (temp) {
    printf("H[%d] %s\n", temp->id, temp->str);
    temp = temp->next;
  }
}

/*Free the history list and the strings it references. */

void free_history(List *list)
{
  Item* temp = list->root;
  Item* nextNode;
  
  while (temp){
    nextNode = temp->next;
    free(temp);
    temp = nextNode;
  }
  list->root = NULL;
  free(list);
}
