
#include <ctype.h>
#include <stdio.h>
#include <math.h>

#define BYTES_A_ROW         ((int)10)
#define ADDR_COLUMN_WIDTH   ((int)(2*sizeof(unsigned char *)))  //num bytes of a pointer * 2 char; (1 byte = hex 2 chars)
#define BYTE_COLUMN_WIDTH   ((int)(BYTES_A_ROW * 3)) // 1 bytes is 2 hex chars + some spaces
#define COLUMN_SEPARATOR    " "

typedef unsigned char byte_t;


int main( int argc, char *argv[] )

{
    int first_var = 0xaaaaaaaa; // do not change this declaration!!!
    int i;
    byte_t *ptr;
    unsigned long start_addr;
    signed int    bytes_to_dump;

    // print some reference addresses
    printf("FYI: address of main function in memory: %p\n", main );
    printf("FYI: address of argc: %p\n", &argc );
    printf("FYI: address of first local variable of main(): %p\n", &first_var );

    // read start address and memory size
    printf("\nEnter start address <hex-notation> of dump: " );
    scanf("%lX", start_addr);
    printf("\nEnter number of bytes to dump <negative or positive value>:");
    scanf("%d", bytes_to_dump);

    // print table header
    printf("\n%-*s", ADDR_COLUMN_WIDTH, "Address");
    printf("%s", COLUMN_SEPARATOR);
    printf("%-*s", BYTE_COLUMN_WIDTH, "Bytes");
    printf("%s", COLUMN_SEPARATOR);
    printf("%-*s\n", BYTES_A_ROW, "Chars");

    for( i= 0; i < ADDR_COLUMN_WIDTH; i++)
        printf("-");
    printf("%s", COLUMN_SEPARATOR);
    for( i= 0; i < BYTE_COLUMN_WIDTH; i++)
        printf("-");
    printf("%s", COLUMN_SEPARATOR);
    for( i= 0; i < BYTES_A_ROW; i++)    // number of chars is char-column is exactly BYTES_A_ROW
        printf("-");
    printf("\n");


    // memory dump code


    if(bytes_to_dump > 0){
      printf("0X%-*lX", ADDR_COLUMN_WIDTH, start_addr);
      *ptr = (start_addr);
      //printf("%02hhX",*ptr);
      }


    else{

    }



    // ...

    return 0;
}
