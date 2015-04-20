#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void element_copy(element_ptr_t *dest_element, element_ptr_t src_element)
{

}


/*
 * Clean up element, including freeing memory if needed
 */
void element_free(element_ptr_t *element)
{
}

/*
 * Print 1 element to stdout.
 */
void element_print(element_ptr_t element)
{
}

/*
 * Compare two element elements; returns -1, 0 or 1
 */
int element_compare(element_ptr_t x, element_ptr_t y)
{
  return 0;
}

int main(void){

  list_ptr_t list = list_create(&element_copy, &element_free, &element_compare, &element_print);
  int* a = malloc(sizeof(int));
  *a = 3;
  int* b = malloc(sizeof(int));
  *b = 6;
  int* c = malloc(sizeof(int));
  *c = 9;
  list_insert_at_index(list, a, 0);
  list_insert_at_index(list, b, 0);
  list_insert_at_index(list, c, 0);
  
  return 0;
}
