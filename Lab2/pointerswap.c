#include <stdio.h>

void swap_pointers(int **p, int **q)
{
  int *dummy_ptr = *p;

  *p = *q;
  *q = dummy_ptr;
}


int main ()
{
  int a = 1;
  int b = 2;

  int *p = &a;
  int *q = &b;

  printf("address of p = %p and q = %p\n", p, q);
  swap_pointers(&p,&q);
  printf("address of p = %p and q = %p\n", p, q);
  return 0;
}
