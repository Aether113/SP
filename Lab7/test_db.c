#include "config.h"
#include "sensor_db.h"
#include <my_global.h>
#include <mysql.h>
#include <time.h>


MYSQL *conn = NULL;

int main(int argc, char **argv){
  time_t curtime = time(NULL);
  conn = init_connection('0');
  insert_sensor(conn, 1, 5.13, curtime);
  insert_sensor(conn, 1, 13.43, curtime);
  insert_sensor(conn, 1, 343.3, curtime);

  MYSQL_RES *result;
  result = find_sensor_exceed_value(conn, 0);
  printf("%d", get_result_size(result));
  return 0;
}
