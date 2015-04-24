#include "config.h"
#include "sensor_db.h"
#include <my_global.h>
#include <mysql.h>

int main(int argc, char **argv)
{
  MYSQL *con = mysql_init(NULL);

  if (con == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      exit(1);
  }

  if (mysql_real_connect(con, "127.0.0.1", "root", "pwd",
          "systeemprogrammatuur", 0, NULL, 0) == NULL)
  {
      fprintf(stderr, "%s\n", mysql_error(con));
      mysql_close(con);
      exit(1);
  }

  if (mysql_query(con, "CREATE TABLE jens_vangindertael(id INT UNIQUE AUTO_INCREMENT, sensor_id INT, sensor_value DECIMAL(4,2),timestamp TIMESTAMP);"))
  {
      fprintf(stderr, "%s\n", mysql_error(con));
  }

  if (mysql_query(con, "INSERT INTO jens_vangindertael(sensor_id,sensor_value) VALUES(7, 23.5)"))
  {
    fprintf(stderr, "%s\n", mysql_error(con));
    mysql_close(con);
    exit(1);
  }

  mysql_close(con);
  exit(0);
}
