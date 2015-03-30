#include "ma_malloc.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define MEM_POOL_SIZE 500

static char memory_block[MEM_POOL_SIZE];
int i,j,k;
int *block_ptr;

struct header{
  char flag;
  unsigned int size;
};

void ma_init(){
  for(i = 0; i < MEM_POOL_SIZE; i++){ // initialize all positions in memory_block
    memory_block[i] = 0;              // to 0;
  }
  struct header init_header = {'F', MEM_POOL_SIZE-sizeof(init_header)};
  memory_block[0] = init_header.flag;
  printf("Flag = %c\n", memory_block[0]);
  char size_buffer[5];
  sprintf(size_buffer, init_header.size);
  printf("Size = %s\n", size_buffer);
}

void* ma_malloc(size tsize){
  //Check for header file (header struct), skip data chunk size and check again if full
  //header = char + int = 5 bytes
  i = 0;
  while(i < 500){
    if(memory_block[i] == 'F'){
      for(j = i+1; j < i+5; j++){         // k = size of data chunk
        k = 10 * k + memory_block[i];
      }
      i = i + k; //jump ahead chunck size (tsize) to next header.
    }

    else{
      //Moet wrs niet tsize zijn maar waarde van k
      //want tsize = nieuwe size
      memory_block[i] = 'F';
      memory_block[i+1] = tsize%10/1;
      tsize = tsize - tsize%10;
      memory_block[i+2] = tsize%100/10;
      tsize = tsize - tsize%100;
      memory_block[i+3] = tsize%1000/100;
      tsize = tsize - tsize%1000;
      memory_block[i+4] = tsize%10000/1000;
      tsize = tsize - tsize%10000;
    }
  }
}

void ma_free(void* ptr){
  //free the memory located at ptr
}

int main(){
  ma_init();
}
