#include "config.h"
#include "sensor_db.h"
#include <my_global.h>
#include <mysql.h>
#include <time.h>


MYSQL *conn = NULL;

int main(int argc, char **argv){
  time_t curtime = time(NULL);
  conn = init_connection('0');
  insert_sensor(conn, 1, 23.12, curtime);
  return 0;
}
