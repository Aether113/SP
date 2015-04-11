#include <stdio.h>
#include <stdlib.h>
#include "list.h"


struct list{
  int size;
  list_node_t *first_node;
  void *free;
  void *copy;
  void *compare;
  void *print;
  void *head;
};

struct list_node{
  void *data;
  struct list_node_t* next;
  struct list_node_t* prev;
};

list_ptr_t list_create 	( // callback functions (ptr_to_callback_func)(arguments)
        void (*element_copy)(element_ptr_t *dest_element, element_ptr_t src_element),
        void (*element_free)(element_ptr_t *element),
        int (*element_compare)(element_ptr_t x, element_ptr_t y),
        void (*element_print)(element_ptr_t element)
        ){

  list_t* list = malloc(sizeof(list_t));
    if(list == NULL){
      list_errno = LIST_MEMORY_ERROR;
      return NULL;
    }

  list->size = 0;
  list->first_node = NULL;
  list->free = element_free;
  list->copy = element_copy;
  list->compare = element_compare;
  list->print = element_print;
  return list;
}

void list_free( list_ptr_t* list ){

}

int list_size( list_ptr_t list ){
  return 0;
}
/*Lab solution
list_ptr_t list_insert_at_index( list_ptr_t list, element_ptr_t element, int index){
  list_node_t* current_node = list_get_reference_at_index(list,index),
  list_node_t* new_node = malloc(sizeof(list_node_t))
  new_node->element = element;
  new_node->next = current_node ->next;
  new_node->prev = current_node
  current_node ->next = new_node;
  if(new_node->next != NULL){
    new_node->next->prev = new_node;
  }
  return list;
}*/

list_ptr_t list_remove_at_index( list_ptr_t list, int index){
  return NULL;
}

list_ptr_t list_free_at_index( list_ptr_t list, int index){
  return NULL;
}

list_node_ptr_t list_get_reference_at_index( list_ptr_t list, int index ){
  //list_node_t* first_node =
  return NULL;
}

element_ptr_t list_get_element_at_index( list_ptr_t list, int index ){
  return NULL;
}

int list_get_index_of_element( list_ptr_t list, element_ptr_t element ){
  return 0;
}
