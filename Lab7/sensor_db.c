#include "config.h"
#include "sensor_db.h"
#include <my_global.h>
#include <mysql.h>
#include <stdio.h>


/*
 * Make a connection to MySQL database
 * Create a table named 'yourname' if the table does not exist
 * If the table existed, clear up the existing data if clear_up_flag is set to 1
 * return the connection for success, NULL if an error occurs
 */

MYSQL *init_connection(char clear_up_flag){
  MYSQL *conn = mysql_init(NULL);
  if (conn == NULL){
    fprintf(stderr, "%s\n", mysql_error(conn));
  }

  if(mysql_real_connect(conn, "127.0.0.1", "root", "pwd","systeemprogrammatuur", 0, NULL, 0) == NULL){
    fprintf(stderr, "%s\n", mysql_error(conn));
  }

  if(clear_up_flag == '1'){
    if(mysql_query(conn, "DROP TABLE systeemprogrammatuur.jens_vangindertael;")){
        fprintf(stderr, "%s\n", mysql_error(conn));
    }

    if(mysql_query(conn, "CREATE TABLE jens_vangindertael(id INT UNIQUE AUTO_INCREMENT, sensor_id INT, sensor_value DECIMAL(4,2),timestamp TIMESTAMP);")){
      fprintf(stderr, "%s\n", mysql_error(conn));
    }
  }

  if(clear_up_flag != '1'){
    if(mysql_query(conn, "CREATE TABLE IF NOT EXISTS jens_vangindertael(id INT UNIQUE AUTO_INCREMENT, sensor_id INT, sensor_value DECIMAL(4,2),timestamp TIMESTAMP);")){
      fprintf(stderr, "%s\n", mysql_error(conn));
    }
  }
  return conn;
}

/*
 * Disconnect MySQL database
 */
void disconnect(MYSQL *conn){
  mysql_close(conn);
}

/*
 * Write an INSERT query to insert a single sensor measurement
 * return zero for success, and non-zero if an error occurs
 */

int insert_sensor(MYSQL *conn, sensor_id_t id, sensor_value_t value, sensor_ts_t ts){
  char buffer[512];
  char date_buffer[26];
  struct tm* tm_info;

  strftime(date_buffer, 26, "%Y-%m-%d %H:%M:%S", localtime(&ts));
  sprintf(buffer, "INSERT INTO jens_vangindertael(sensor_id, sensor_value, timestamp) VALUES(%d, %e, '%s')", id, value, date_buffer);
  if(mysql_query(conn, buffer)){
    fprintf(stderr, "%s\n", mysql_error(conn));
    return 1;
  }
  return 0;
}

/*
 * Write an INSERT query to insert all sensor measurements existed in the file pointed by sensor_data
 * return zero for success, and non-zero if an error occurs
 */

int insert_sensor_from_file(MYSQL *conn, FILE *sensor_data){
  return 0;
}

/*
 * Write a SELECT query to return all sensor measurements existed in the table
 * return MYSQL_RES with all the results
 */

MYSQL_RES *find_sensor_all(MYSQL *conn){
  MYSQL_RES *data;
  if(mysql_query(conn, "SELECT * FROM jens_vangindertael;" )){
    fprintf(stderr, "%s\n", mysql_error(conn));
    return NULL;
  }
  data = mysql_store_result(conn);
  return data;
}

/*
 * Write a SELECT query to return all sensor measurements containing 'value_t'
 * return MYSQL_RES with all the results
 */

MYSQL_RES *find_sensor_by_value(MYSQL *conn, sensor_value_t value_t){
  char buffer[512];
  MYSQL_RES *data;
  sprintf(buffer, "SELECT * FROM jens_vangindertael WHERE sensor_value = '%f';", value_t);
  if(mysql_query(conn, buffer )){
    fprintf(stderr, "%s\n", mysql_error(conn));
    return NULL;
  }
  data = mysql_store_result(conn);
  return data;
}

/*
 * Write a SELECT query to return all sensor measurement that its value exceeds 'value_t'
 * return MYSQL_RES with all the results
 */
MYSQL_RES *find_sensor_exceed_value(MYSQL *conn, sensor_value_t value_t){
  char buffer[512];
  MYSQL_RES *data;
  sprintf(buffer, "SELECT * FROM jens_vangindertael WHERE sensor_value > '%f';", value_t);
  if(mysql_query(conn, buffer )){
    fprintf(stderr, "%s\n", mysql_error(conn));
    return NULL;
  }
  data = mysql_store_result(conn);
  return data;
}

/*
 * Write a SELECT query to return all sensor measurement containing timestamp 'ts_t'
 * return MYSQL_RES with all the results
 */
MYSQL_RES *find_sensor_by_timestamp(MYSQL *conn, sensor_ts_t ts_t){
  char buffer[512];
  char date_buffer[26];
  MYSQL_RES *data;
  strftime(date_buffer, 26, "%Y-%m-%d %H:%M:%S", localtime(&ts_t));
  sprintf(buffer, "SELECT * FROM jens_vangindertael WHERE timestamp = '%s'", date_buffer);
  if(mysql_query(conn, buffer)){
    fprintf(stderr, "%s\n", mysql_error(conn));
    return NULL;
  }
  data = mysql_store_result(conn);
  return data;
}

/*
 * Write a SELECT query to return all sensor measurement recorded later than timestamp 'ts_t'
 * return MYSQL_RES with all the results
 */
MYSQL_RES *find_sensor_later_timestamp(MYSQL *conn, sensor_ts_t ts_t){
  char buffer[512];
  char date_buffer[26];
  MYSQL_RES *data;
  strftime(date_buffer, 26, "%Y-%m-%d %H:%M:%S", localtime(&ts_t));
  sprintf(buffer, "SELECT * FROM jens_vangindertael WHERE timestamp > '%s'", date_buffer);
  if(mysql_query(conn, buffer)){
    fprintf(stderr, "%s\n", mysql_error(conn));
    return NULL;
  }
  data = mysql_store_result(conn);
  return data;}

/*
 * Return the number of records contained in the result
 */

int get_result_size(MYSQL_RES *result){
  return mysql_num_rows(result);
}

/*
 * Print all the records contained in the result
 */
void print_result(MYSQL_RES *result){

}
