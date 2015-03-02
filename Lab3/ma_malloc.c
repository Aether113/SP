#include "ma_malloc.h"
#include <stdlib.h>

#define INITIAL_MEM_SIZE 500

static char memory_block[INITIAL_MEM_SIZE];
int i;

struct header{
  char flag;
  unsigned int size;
};

void ma_init(){
  for(i = 0; i < INITIAL_MEM_SIZE; i++){
    memory_block[i] = 0; // initialize all positions in memory_block
                         // to 0;
  }
}

void* ma_malloc(size tsize){
  short free = 1;
  while(free)
  {
    int *ptr = &memory_block[0];
  }
}

void ma_free(void* ptr){
  //free the memory located at ptr
}
