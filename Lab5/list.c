#include <stdio.h>
#include "list.h"

list_ptr_t list_create 	( // callback functions
        void (*element_copy)(element_ptr_t *dest_element, element_ptr_t src_element),
        void (*element_free)(element_ptr_t *element),
        int (*element_compare)(element_ptr_t x, element_ptr_t y),
        void (*element_print)(element_ptr_t element)
        ){
  return 0;
}

void list_free( list_ptr_t* list ){

}

int list_size( list_ptr_t list ){
  return 0;
}

list_ptr_t list_insert_at_index( list_ptr_t list, element_ptr_t element, int index){
  return 0;
}

list_ptr_t list_remove_at_index( list_ptr_t list, int index){
  return 0;
}

list_ptr_t list_free_at_index( list_ptr_t list, int index){
  return 0;
}

list_node_ptr_t list_get_reference_at_index( list_ptr_t list, int index ){
  return 0;
}

element_ptr_t list_get_element_at_index( list_ptr_t list, int index ){
  return 0;
}

int list_get_index_of_element( list_ptr_t list, element_ptr_t element ){
  return 0;
}
