#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct list{
  int size;
  list_node_ptr_t first_node;
  void * free;
  void * copy;
  void * compare;
  void * print;
};

struct list_node{
  element_ptr_t data;
  list_node_ptr_t next;
  list_node_ptr_t prev;
};

int list_errno = 0;

list_ptr_t list_create 	( // callback functions (ptr_to_callback_func)(arguments)
        void (*element_copy)(element_ptr_t *dest_element, element_ptr_t src_element),
        void (*element_free)(element_ptr_t *element),
        int (*element_compare)(element_ptr_t x, element_ptr_t y),
        void (*element_print)(element_ptr_t element))
        {

  list_ptr_t list = malloc(sizeof(list_t));    // returned een pointer = list_ptr
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
  int i;
  for(i = 0; i <= (*list)->size-1; i++){
    list_free_at_index(*list, i);
  }

  if(list_errno == 2){
    //list was empty, so list_free_at_index() set errno to LIST_EMPTY_ERROR;
    list_errno = LIST_NO_ERROR;
  }

  free(*list);
  *list = NULL;
}

int list_size( list_ptr_t list ){
  return list->size;
}

list_ptr_t list_insert_at_index( list_ptr_t list, element_ptr_t element, int index){

  list_node_ptr_t new_node = malloc(sizeof(list_node_t));

  new_node->data = element;

  if(list == NULL){
    list_errno = LIST_INVALID_ERROR;
    return NULL;
  }

  //eerste node
  if(list->size <= 0){
    new_node->next = NULL;
    new_node->prev = NULL;
    list->first_node = new_node;
    list->size++;
    return list;
  }

  else if(index >= list->size){
    list_node_ptr_t current_node = list_get_reference_at_index(list, index);

    current_node->next = new_node;
    new_node->next = NULL;
    new_node->prev = current_node;
    list->size++;
    return list;
  }

  else{
    list_node_ptr_t current_node = list_get_reference_at_index(list, index);
    if(index <= 0){
      new_node->next = list->first_node;
      list->first_node = new_node;
      new_node->prev = NULL;
      new_node->next->prev = new_node;
    }

    else{
      new_node->next = current_node;
      new_node->prev = current_node->prev;
      current_node->prev->next = new_node;
      current_node->prev = new_node;
    }
    list->size++;
    return list;
  }
}

list_ptr_t list_remove_at_index( list_ptr_t list, int index){
  if(list == NULL){
    list_errno = LIST_INVALID_ERROR;
    return NULL;
  }

  if(list->size == 0){
    list_errno = LIST_EMPTY_ERROR;
    return list;
  }

  if(index <= 0){
    //remove first_node
    list->first_node->next->prev = NULL;
    list->first_node = list->first_node->next;
    list->size--;

  }

  else if(index >= (list->size - 1)){
      list_node_ptr_t last_node = list_get_reference_at_index(list, index);
      if(last_node->prev == NULL){
        list->first_node = NULL;
      }
      else{
        last_node->prev->next = NULL;
      }
      last_node->prev = NULL;
      list->size--;
    }

  else{
    list_node_ptr_t current_node = list_get_reference_at_index(list, index);
    current_node->next->prev = current_node->prev;
    current_node->prev->next = current_node->next;
    list->size--;
  }
  return list;
}

list_ptr_t list_free_at_index( list_ptr_t list, int index){
  if(list == NULL){
    list_errno = LIST_INVALID_ERROR;
    return NULL;
  }

  if(list->size == 0){
    list_errno = LIST_EMPTY_ERROR;
    return list;
  }

  list_node_ptr_t current_node = list_get_reference_at_index(list, index);
  list = list_remove_at_index(list, index);
  free(current_node);
  return list;
}

list_node_ptr_t list_get_reference_at_index( list_ptr_t list, int index ){

  if(list == NULL){
    list_errno = LIST_INVALID_ERROR;
    return NULL;
  }

  if(index <= 0){
    return list->first_node;
  }

  else if(index >= (list->size - 1)){
    list_node_ptr_t current_node = list->first_node;
    while(current_node->next != NULL){
      current_node = current_node->next;
    }
    return current_node;
  }

  else{
    list_node_ptr_t current_node = list->first_node;
    int i = 0;
    while(i < index){
      current_node = current_node->next;
      i++;
    }
    return current_node;
  }
  return NULL;
}

element_ptr_t list_get_element_at_index( list_ptr_t list, int index ){
  list_node_ptr_t temp = list_get_reference_at_index(list, index);
  if(list == NULL){
    return NULL;
  }

  return temp->data;
}

int list_get_index_of_element(list_ptr_t list, element_ptr_t element ){

  if(list == NULL){
    list_errno = LIST_INVALID_ERROR;
    return -1;
  }

  if(list->first_node == NULL){
    return -1;
  }

  list_node_ptr_t current_node = list->first_node;
  int i;
  for(i = 0; i <= list->size-1; i++){
    if(list_get_element_at_index(list, i) == element){
      return i;
    }
  }
  return -1;
}

void list_print(list_ptr_t list){
  list_node_ptr_t current_node = list->first_node;

  while(current_node != NULL){
    printf("%s\n", (current_node->data));
    current_node = current_node->next;
    }
}
