#include "datamgr.h"

int main(void){

  list_ptr_t list = list_create();
  read_room_map(list);
  //list_print(list);
  //print_sensor_data();
  parse_sensor_data(list);
  return 0;
}
