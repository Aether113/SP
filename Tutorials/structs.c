#include <stdio.h>

struct database {
  int id_number;
  int age;
  float salary;
};

int main()
{
  struct database employee;  /* There is now an employee variable that has
                              modifiable variables inside it.*/
  employee.age = 22;
  employee.id_number = 1;
  employee.salary = 12000.21;

  int *ptr;
  float *fptr;

  ptr = &employee.age;
  printf("age: %d\n", *ptr);

  ptr = &employee.id_number;
  printf("id_number: %d\n", *ptr);

  fptr = &employee.salary;
  printf("salary: %f \n", *fptr);

  printf("float size: %lu", sizeof(float));
  printf("int size: %lu", sizeof(int));
}
