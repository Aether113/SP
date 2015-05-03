#include "config.h"
#include "sensor_db.h"
#include <my_global.h>
#include <mysql.h>
#include <time.h>
#include <stdlib.h>

FILE *fp;
MYSQL *conn = NULL;

int main(int argc, char **argv){
  //time_t curtime = time(NULL);
  conn = init_connection('1');

  fp = fopen("sensor_data", "rb");
  insert_sensor_from_file(conn, fp);
  //printf("%d", check);
  MYSQL_RES *result;
  result = find_sensor_exceed_value(conn, 0);
  print_result(result);
  return 0;
}
