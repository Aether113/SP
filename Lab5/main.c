#include "list.h"
#include <stdlib.h>
#include <stdio.h>


int main(void){

  int list_errno = 0;

  char* a = malloc(sizeof(char));
  *a = 'x';
  char* b = malloc(sizeof(char));
  *b = 'y';
  char* c = malloc(sizeof(char));
  *c = 'z';

  list_ptr_t list = NULL;
  list = list_create();

  list_insert_at_index(list,a, 1);
  list_insert_at_index(list,b, 0);
  list_insert_at_index(list,c, -3);

  list_print(list);
  printf("Error code: %d\n", list_errno);

  list_free(&list);

  printf("\nlist = %s", (void*)list);
  return 0;
}
