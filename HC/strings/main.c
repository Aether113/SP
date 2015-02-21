#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LENGTH 80

int main( void )
{
  // string initialization
  char str[LENGTH];
  char str2[LENGTH];
  char sample[] = "his, a sample string.";
  char name[4] = "luc";
  // char name[] = {'l', 'u', 'c', '\0' };
  
  char ch;
  int i;
  double x; 
  int result;
  
  // examples of string functions
  
  printf("string length = %d\n", (int)strlen(sample) );
  
  if ( strcmp( name, "luc" ) == 0 )	// NOT CORRECT: name == "luc" !
  {
    printf("equal!\n");
  } 
  else 
  {
    printf("not equal!\n");
  }
  
  strcpy( str, sample );
  printf("copy = %s\n", str);
  // but UNSAFE: enough memory should be allocated to str to avoid memory errors
  strncpy( str, sample, LENGTH-1 );
  // ! No \0 is appended at the end of 'str' if 'sample' is longer than LENGTH-1 
  printf("copy = %s\n", str);
  
  // scan formatted input from stdin (standard input)
  printf("enter int and double:\n");
  result = scanf("%d %lf", &i, &x);  
  // scanf returns #args read
  printf("result = %d\n", result);
  
  // print formatted output to stdout (standard output)
  result = printf( "%-20i-----%2.3f\n", i, x);
  // printf returns #chars printed
  printf("result = %d\n", result);
  
  // read/write a string
  fgets(str, LENGTH, stdin); // read previous \n
  printf("Input a floating point number: ");
  while ( fgets (str, LENGTH, stdin) == NULL );
  // Reads str until either LENGTH–1 chars or a newline char is read, whichever occurs first
  // Returns pointer to str or NULL if end of file or an error occurs
  
  puts (str);
  // remark: reading a string with gets(str) is considered as unsafe!!
  
  // string-to-number conversions
  x = atof(str);		// convert alpha to float (others: atoi, atol)
  sprintf( str, "number = %lf\n", x); // convert float to alpha
  // sprintf: same as printf() but everything is printed to the string str
  // sprintf is considered unsafe: enough memory should be allocated to str to avoid memory errors
  sscanf (str, "%79s %lf", str2, &x );	// parse formatted string
  // sscanf: same as scanf() but input is scanned from string str
  printf("%s %f\n", str2, x);
  
  // read/write a char
  printf("give a char: ");
  ch = getchar();
  putchar(ch);
  putchar('\n');
  
  return 0;
}
