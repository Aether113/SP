#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <assert.h>
#include "tcpsocket.h"
#include <sys/poll.h>
#include <time.h>

#define PORT 1234

#ifndef SET_TIMEOUT
#error Your forgot to set the TIMEOUT
#endif

int main( void )
{
  Socket server, client;
  uint16_t sensor_id;
  double temperature;
  time_t timestamp;
  int bytes;
  //int struct pollfd pfds[1];
  int amount_of_clients = 0;
  struct pollfd *pfds;
  
  pfds = malloc(sizeof(struct pollfd));
  Socket *socket_array = malloc(sizeof(Socket));

  // open server socket
  server = tcp_passive_open( PORT );
  
  pfds[0].fd = get_socket_descriptor(server);
  pfds[0].events = POLLIN;
  
  while(1)
  {
    poll(pfds, 1+ amount_of_clients, 500);	//will check file descripter
  
    if(pfds[0].revents == POLLIN)
    {
      client = tcp_wait_for_connection( server );
      printf("incoming client connection\n");
      amount_of_clients++;
      
      socket_array = realloc(socket_array, sizeof(Socket)*(amount_of_clients));
      socket_array[amount_of_clients -1] = client;
      
      pfds = realloc(pfds, sizeof(struct pollfd)*(amount_of_clients +1));
      pfds[amount_of_clients].fd = get_socket_descriptor(client);
      pfds[amount_of_clients].events = POLLIN;
    }
    for(int client_number = 1; client_number <= amount_of_clients; client_number++)
    {
      if(pfds[client_number].revents == POLLIN)
      {
	client = socket_array[client_number -1];
	
	bytes = tcp_receive( client, (void *)&sensor_id, sizeof(sensor_id));
	// bytes == 0 indicates tcp connection teardown
	assert( (bytes == sizeof(sensor_id)) || (bytes == 0) );	
	bytes = tcp_receive( client, (void *)&temperature, sizeof(temperature));
	assert( (bytes == sizeof(temperature)) || (bytes == 0) );
	bytes = tcp_receive( client, (void *)&timestamp, sizeof(timestamp));
	assert( (bytes == sizeof(timestamp)) || (bytes == 0) );    
	if (bytes) 
	{
	  printf("sensor id = %" PRIu16 " - temperature = %g - timestamp = %ld\n", sensor_id, temperature, (long int)timestamp );
	}
      }
    }
  }

  //sleep(1);	/* to allow socket to drain */
  for(int client_number = 1; client_number <= amount_of_clients; client_number++)
  {
    client = socket_array[client_number -1];
    tcp_close(&client);
  }
  //tcp_close(&socket_array);
  tcp_close(&client);
  tcp_close(&server);
  
  //free(socket_array);
  free(pfds);
  
  return 0;
}

