//Author                      JENS VANGINDERTAEL

//preprocessor
#include <ctype.h>
#include <stdio.h>
#include <ctype.h>

#define BYTES_A_ROW         ((int)10)
#define ADDR_COLUMN_WIDTH   ((int)(2*sizeof(unsigned char *)))  //num bytes of a pointer * 2 char; (1 byte = hex 2 chars)
#define BYTE_COLUMN_WIDTH   ((int)(BYTES_A_ROW * 3)) // 1 bytes is 2 hex chars + some spaces
#define COLUMN_SEPARATOR    " "

typedef unsigned char byte_t;

//Prototypes
int to_print(int);


//determines which data gets dumped by manipulating bytes_to_dump
int to_print(int bytes_to_dump){

    if(bytes_to_dump > 10){
        return 10;
      }
    else {
        return bytes_to_dump;
    }
}

//Main
int main( int argc, char *argv[] )

{
        int first_var = 0xaaaaaaaa; // do not change this declaration!!!
        int i;
        byte_t *ptr;
        unsigned long start_addr;
        int sign = 1;
        signed int bytes_to_dump;

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
        for( i= 0; i < BYTES_A_ROW; i++) // number of chars is char-column is exactly BYTES_A_ROW
                printf("-");
        printf("\n");

        if(bytes_to_dump < 0){
            sign = -1;
            bytes_to_dump = bytes_to_dump*-1;
        }

        while(bytes_to_dump > 0) {

                printf("0x%-*lX",ADDR_COLUMN_WIDTH-2, start_addr);
                printf("%s", COLUMN_SEPARATOR);

                        //prints the hexadecimal representation of the value.
                        for(i = 0; i < to_print(bytes_to_dump); i++ ) {
                                ptr = (byte_t*)start_addr;
                                printf("%.2X ", *(ptr+i));
                                //if not a whole row, fill with spaces to align
                        }

                        for(i = 0; i < (BYTE_COLUMN_WIDTH - 3*to_print(bytes_to_dump)); i++){
                            if(bytes_to_dump < 10){
                                printf(" ");
                            }
                        }

                        printf("%s", COLUMN_SEPARATOR);

                        //prints the ascii equivalent of the hex value (if it exists)
                        //isprint(able) function from ctype.h
                        for(i = 0; i < to_print(bytes_to_dump); i++) {
                                char temp;
                                temp = '.';
                                ptr = (byte_t*)start_addr;
                                if(isprint(*(ptr+i))){
                                        temp = *(ptr+i);
                                        printf("%c", temp);
                                }
                                else{
                                        printf(".");
                                }
                        }

                        bytes_to_dump = bytes_to_dump - BYTES_A_ROW;
                        start_addr = start_addr + sign*BYTES_A_ROW;

                printf("\n");
              }




              return 0;
        }
