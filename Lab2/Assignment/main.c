
#include <ctype.h>
#include <stdio.h>

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

    printf("\nEnter start address <hex-notation> of dump: " );
    scanf(" %lX", &start_addr);
    printf("\nEnter number of bytes to dump <negative or positive value>:");
    scanf(" %d", &bytes_to_dump);

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

    // read start address and memory size

    if(bytes_to_dump > 0){
      while(bytes_to_dump > 0){
        printf("%-*lX",ADDR_COLUMN_WIDTH, start_addr);
        printf("%s", COLUMN_SEPARATOR);
        if(bytes_to_dump > 10){
          for(i = 0; i < 10; i++ ){
            ptr = (byte_t*)start_addr;
            printf("%.2X ", *(ptr+i));
          }

          printf("%s", COLUMN_SEPARATOR);
          for(i = 0; i < 10; i++){
            char temp[1];
            ptr = (byte_t*)start_addr;
            if(*(ptr+i) < 128){
            sprintf(temp, "%c", *(ptr+i));
            printf("%s", temp);
            }
            else{
              printf(".");
            }
          }

          bytes_to_dump = bytes_to_dump -10;
          start_addr = start_addr + 10;
        }

        else
        {
          for(i = 0; i < bytes_to_dump; i++){
            ptr = (byte_t*)start_addr;
            printf("%X ", *(ptr+i));
          }
          printf("%s", COLUMN_SEPARATOR);
          for(i = 0; i < bytes_to_dump; i++){
            char temp[1];
            ptr = (byte_t*)start_addr;
            if(*(ptr+i) < 128){
            sprintf(temp, "%c", *(ptr+i));
            printf("%s", temp);
            }
            else{
              printf(".");
            }
          }

          break;
        }
        printf("\n");
      }
    }


    else{
    }

    // memory dump code


    // ...

    return 0;
}
