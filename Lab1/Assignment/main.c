//Author: Jens Vangindertael
//Systeemprogrammatuur
//Assignment 1

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main()
{
  srand(time(NULL));

  while(1)
  {

    double rand_temp = ((double)rand()/(double)RAND_MAX)*60-20;
    printf("Temperature = %.2f @ ", rand_temp);
    fflush(stdout);
    system("date\n");
    sleep(5);
  }
  return 0;
}
