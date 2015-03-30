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
  element_t *arr;    // dynamic array containing data elements
  int current_size;   // Counts number of elements in the queue
  int front, rear;   // Remark for later: extra fields need to be added here to make it a thread-safe queue as needed for the assigment
};


queue_t* queue_create(){
  struct queue *my_queue = malloc(sizeof(struct queue));

  if(my_queue == 0){  //check if memory available
    printf("Out of memory\n");
    return NULL;
  }

  my_queue -> current_size = 0;
  my_queue -> front = -1;
  my_queue -> rear = -1;
  my_queue -> arr = malloc(QUEUE_SIZE*sizeof(element_t));
  return my_queue;
}

void queue_free(queue_t** queue){
  free(*queue);
}

void queue_enqueue(queue_t* queue, element_t element)
{
  if(queue->current_size == QUEUE_SIZE){
    printf("Queue is full, cannot add element [%d]\n", element);
  }

  else{
    queue->current_size++;
    queue->rear++;
    queue->arr[queue->rear] = element;
    if(queue->front == -1){
      queue->front = 0;
    }
  }
}

int queue_size(queue_t* queue){
  return queue->current_size;
}

element_t* queue_top(queue_t* queue){
  element_t *top_element = &queue->arr[queue->front];
  return top_element;
}

void queue_dequeue(queue_t* queue){
  if(queue->current_size == 0){
    printf("No elements currently in queue\n");
  }
}

void queue_print(queue_t *queue){
  int i;
  if(queue->current_size == 0){
    printf("There are currently no elements in the queue\n");
  }

  else{
    for(i = 0; i < queue->current_size; i++){
      printf("Element #%d: %d\n", i, queue->arr[i]);
    }
  }
}
