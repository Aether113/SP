#include "ma_malloc.h"
#include <stdio.h>

int main (int argc, char* argv[]){
	printf("Malloc Demo \n");
	ma_init();
	//int* num = ma_malloc(sizeof(int));
	//*num = 7;
	//ma_free(num);
	return 0;
}
