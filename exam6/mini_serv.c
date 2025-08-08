#include <string.h>     // for strlen, bzero, sprintf
#include <unistd.h>     // for write, close
#include <netdb.h>      // for networking definitions (not heavily used here)
#include <sys/socket.h> // for socket, bind, listen, accept, send, recv
#include <netinet/in.h> // for sockaddr_in, htons, htonl
#include <stdlib.h>     // for exit, atoi
#include <stdio.h>      // for sprintf

//Structure to store each client's ID and partial message buffer
typedef struct s_clients
{
    int id;         // Unique ID for the client
    char msg[1024]; // Buffer to accumulate incoming message until '\n'
}   t_clients;

//Declare variables

// Array of clients (indexed by file descriptor)
t_clients clients[1024];

// fd_set variables for select()
fd_set readfds, writefds, active;

// Track the highest file descriptor in use
// Track the next available client ID
int idMax = 0;
int idNext = 0;
