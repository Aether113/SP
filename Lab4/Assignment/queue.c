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
  struct queue *queue = malloc(sizeof(struct queue));

  if(queue == 0){  //check if memory available
    printf("Out of memory\n");
    return NULL;
  }

  queue -> current_size = 0;
  queue -> front = -1;
  queue -> rear = -1;
  queue -> arr = malloc(QUEUE_SIZE*sizeof(element_t));
  return queue;
}

void queue_free(queue_t** queue){
  free(*queue);
}

void queue_enqueue(queue_t* queue, element_t element)     // inspiration for algorithm: http://scanftree.com/Data_Structure/circular-queue
{
  if(((queue->front == 0) && (queue->rear == QUEUE_SIZE - 1)) || (queue->front == (queue->rear+1))){
    printf("Queue is full, cannot add element: %d", element);
  }

  else{
    if((queue->rear == -1) && (queue->front) == -1){
      queue->rear = 0;
      queue->front = 0;
    }

    else if(queue->rear == QUEUE_SIZE - 1){
      queue->rear = 0;
    }

    else{
      queue->rear++;
    }

    queue->arr[queue->rear] = element;
    queue->current_size++;
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

  if(queue->front == -1){
    printf("No elements in queue to dequeue");
  }

  else{
    queue->current_size--;
    if(queue->front == queue->rear){      // all elements are gone, reinitialise
      queue->front = -1;
      queue->rear = -1;
      queue->current_size = 0;
    }

    else if(queue->front == QUEUE_SIZE - 1){ //IF front at end --> 0
      queue->front = 0;
    }

    else{
      queue->front++;
    }
  }
}

void queue_print(queue_t *queue){
  int i, index;

  if(queue->current_size ==  0){
    printf("No elements in queue to print\n");
  }

  for(i = 0; i < queue->current_size; i++){

    if(queue->front == QUEUE_SIZE -1){
      index = -1;
    }

    else{
      index = index + 1;
    }
    printf("Element [%d]: %d\n", index, queue->arr[index]);
  }
  printf("\nQueue size: %d\tFront: %d\tRear: %d\n\n", queue->current_size, queue->front, queue->rear);
}
