#include "history.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Initialize the linked list to keep the history. */
List* init_history(){
  List *list = (List*) malloc(sizeof(List));
    list -> root = NULL;
    return list;
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str){
  Item *item = (Item*) malloc(sizeof(Item));
  item -> str = strdup(str);
  item -> next = NULL;

  Item *curr = list -> root;
  int id = 1;

  if(curr == NULL){
    item -> id = id;
    list -> root = item;
  }else{
    while(curr -> next != NULL){
      curr = curr -> next;
      id++;
    }
    item -> id = id + 1;
    curr -> next = item;
  }
}


/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id){
  Item * curr = list -> root;

  while(curr != NULL){
    if(curr -> id == id){
      return curr -> str;
    }
    curr = curr -> next;
  }
  return NULL;
}

/*Print the entire contents of the list. */
void print_history(List *list){
  Item *curr = list -> root;
  while(curr != NULL){
    printf("%d: %s\n", curr -> id, curr ->str);
    curr = curr -> next;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list){
  Item *curr = list -> root;
  
  while(curr != NULL){
    Item *delete = curr;
    curr = curr -> next;
    free(delete -> str);
    free(delete);
  }
  free(list);
}


