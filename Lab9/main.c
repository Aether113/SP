#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "myqueue.h"

void element_print(element_t element);
void element_copy(element_t *dest_element, element_t src_element);
void element_free(element_t *element);

int main( void )
{
//   int* a = malloc(sizeof(int));
//   int* b = malloc(sizeof(int));
//   int* c = malloc(sizeof(int));
//   *a = 1;
//   *b = 2;
//   *c = 3;
  queue_t* queue = NULL;
  queue = queue_create();
  queue_enqueue(queue, 1);
  queue_enqueue(queue, 2);
  queue_enqueue(queue, 3);
  queue_enqueue(queue, 4);
  queue_enqueue(queue, 5);

//   queue_enqueue(queue, a);
//   queue_enqueue(queue, b);
//   queue_enqueue(queue, b);
  queue_print(queue);
  queue_dequeue(queue);
  queue_dequeue(queue);
  queue_dequeue(queue);
  queue_enqueue(queue, 15);
  queue_enqueue(queue, 20);
  queue_enqueue(queue, 37);
  queue_enqueue(queue, 35);
  queue_dequeue(queue);
  queue_dequeue(queue);
  queue_dequeue(queue);
  queue_dequeue(queue);
  queue_free(&queue);
  //queue_print(queue);

//   free(a);
//   free(b);
//   free(c);

  return 0;
}



/*
 * Implement here private functions to copy, to print and to destroy an element. Do you understand why you need these functions?
 * Later you will learn how you could avoid this by using funtion pointers.
 *
 */

/*
 * Print 1 element to stdout.
 * If the defition of element_t changes, then this code needs to change as well.
 */
void element_print(element_t element){
  //printf("%d\n", )
}


/*
 * Copy the content (e.g. all fields of a struct) of src_element to dst_element.
 * dest_element should point to allocated memory - no memory allocation will be done in this function
 * If the defition of element_t changes, then this code needs to change as well.
 */
void element_copy(element_t *dest_element, element_t src_element){
  //element_t temp =
}

/*
 * Free the memory allocated to an element (if needed)
 * If the defition of element_t changes, then this code needs to change as well.
 */
void element_free(element_t *element){
  free((int*)*element);
}
