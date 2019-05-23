#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/times.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 49153
#define hostNameLength 50
#define messageLength  256
#define MAXMSG 512
#define message 10
#define WAIT_SYN 1
#define WAIT_ACK 2
#define WAIT_SYNACK 3
#define INIT 0

struct sockaddr_in clientName;
int windowSize;
int state;
int sequenceNum;
fd_set activeFdSet, readFdSet;


struct socketlist{
    int Socket;
    struct socketlist *next;
}socklist;

/* makeSocket
 * Creates and names a socket in the Internet
 * name-space. The socket created exists
 * on the machine from which the function is 
 * called. Instead of finding and using the
 * machine's Internet address, the function
 * specifies INADDR_ANY as the host address;
 * the system replaces that with the machine's
 * actual address.
 */


int makeBindSocket(unsigned short int port) {
  int sock;
  struct sockaddr_in name;

  sock = socket(PF_INET, SOCK_DGRAM, 0);
  if(sock < 0) {
    perror("Could not create a socket\n");
    exit(EXIT_FAILURE);
  }
  /* Give the socket a name. */
  /* Socket address format set to AF_INET for Internet use. */
  name.sin_family = AF_INET;
  /* Set port number. The function htons converts from host byte order to network byte order.*/
  name.sin_port = htons(port);
  /* Set the Internet address of the host the function is called from. */
  name.sin_addr.s_addr = htonl(INADDR_ANY);
  /* Assign an address to the socket by calling bind. */
  if(bind(sock, (struct sockaddr *)&name, sizeof(name)) < 0) {

    perror("Could not bind a name to the socket\n");

    exit(EXIT_FAILURE);
  }
  return(sock);
}



void sendMSG(int targetSock, Struct ????? MSG, socklen_t size)
{

}



int receiveMSG()
{

}



int handShake(int sock)
{
    struct timeval timeout;

    while(42!=43)
    {

    }
}





int main(int argc, char *argv[]) {
  int sock;
  int clientSocket;
  socklen_t size = sizeof(struct sockaddr_in);
  state = WAIT_SYN;

 
  /* Create a socket and set it up to accept connections */
  sock = makeBindSocket(PORT);
  /* Initialize the set of active sockets */
  FD_ZERO(&activeFdSet);
  FD_SET(sock, &activeFdSet);
  
  printf("\n[waiting for connections...]\n");

  while(1) {
    if(select(FD_SETSIZE, &readFdSet, NULL, NULL, NULL) < 0) {
      perror("Select failed\n");
      exit(EXIT_FAILURE);
    }

  }
}
