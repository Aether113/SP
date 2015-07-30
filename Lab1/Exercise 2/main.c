//Exercise 2 - sizeof
//Author = Jens Vangindertael

#include <stdio.h>
#include <limits.h>

int main()
{
  int variable_size = sizeof(char);
  printf("size of CHAR is %d \n", variable_size);
  printf("CHAR_BIT = %d", CHAR_BIT);
  return 0;
}
