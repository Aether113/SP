#include <stdio.h>

//Structuur voor een datum, juist.
typedef struct
{
  short day, month;
  unsigned year;
} date_t;


void date_struct( int day, int month, int year, date_t *date) {
  date_t dummy;
  dummy.day = (short)day;
  dummy.month = (short)month;
  dummy.year = (unsigned)year;
  date = &dummy;
}

int main( void ) {

  date_t d;
  printf("\nGive day, month, year:");
  scanf("%hd %hd %d", &d.day, &d.month, &d.year);
  date_struct( d.day, d.month, d.year, &d);
  printf("\ndate struct values: %hu-%hu-%u\n", d.day, d.month, d.year);
  return 0;
}
