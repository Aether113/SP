#include <stdio.h>
#include "myqueue.h"
#include <stdlib.h>

#define DEBUG_PRINTF /* define here a debug macro */

/* The caller of the queue is responsible for implementing the functions below */
extern void element_print(element_t element);
extern void element_copy(element_t *dest_element, element_t src_element);
extern void element_free(element_t *element);

/*
 * The real definition of 'struct queue'
 */
struct queue {
  element_t *arr; // dynamic array containing data elements
  int current_size; // Counts number of elements in the queue
  int front, rear;
  // Remark for later: extra fields need to be added here to make it a thread-safe queue as needed for the assigment
};


queue_t* queue_create()
{
  queue_t q;
  q.current_size = 0;
  q.front = 0;
  q.rear = 0;
}

void queue_free(queue_t** queue)
{
  free(q);
}

void queue_enqueue(queue_t* queue, element_t element)
{
  if(queue->current_size < QUEUE_SIZE){

  }
}

int queue_size(queue_t* queue)
{
  printf("The current size of the queue equals: %d", queue.current_size);
}

element_t* queue_top(queue_t* queue){
  // implementation goes here
}

void queue_dequeue(queue_t* queue)
{
  // implementation goes here
}

void queue_print(queue_t *queue)
{
  // implementation goes here
}
