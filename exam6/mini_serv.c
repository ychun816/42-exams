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
    int id;          // Unique ID for this client
    char msg[1024];  // Buffer to accumulate incoming message until '\n'
} t_clients;

//Declare variables

// Array of clients (indexed by file descriptor)
t_clients clients[1024];

// fd_set variables for select()
fd_set readfds, writefds, active;

// Track the highest file descriptor in use
// Track the next available client ID
int idMax = 0;
int idNext = 0;

// Buffers for reading and sending data
char bufferRead[120000];   // to receive data from recv()
char bufferWrite[120000];  // to prepare broadcast message

////FUNC

//print error
// write the provided message to stderr
//exit with status 1
void ft_error(char *str)
{
    if (str)
        write(2, str, strlen(str));
    else
        write(2, "Fatal error", strlen("Fatal error")); //default
    write(2, "\n", 1);
    exit(1);
}

// send all msag
// Sends the contents of bufferWrite to all connected clients except 'not'
void send_all(int not)
{
    for (int i = 0; i <= idMax; i++)
    {
        if (FD_ISSET(i, &writefds) && i != not)
            send(i, bufferWrite, strlen(bufferWrite), 0); // send prepared message
    }
}


//main
/**
 * 1. check arg
 * 2. creat TCP socket
 * 3. initialize fd_set & client array
 * 4. 
 * 5. 
 */
int main(int ac, char* av[])
{
    //Check arg (must have exactly 1 argument: port)
    if (ac != 2)
        ft_error("Wrong number of arguments");
    
    //Create TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        ft_error(NULL);

    //Initialize fd_set & client array
    /*
        active: { 3 }
        fdMax = 3
        clients[] = empty
    */
    FD_ZERO(&active);
    bzero(&clients, sizeof(clients));
    fdMax = sockfd;  //at start, highest FD is the listening socket
    FD_SET(sockfd, &active); // mark listening socket as "active" → the server must monitor the listening socket to detect new connections.

    //Prepare the server address
    /*
        servaddr = {
            sin_family = AF_INET
            sin_addr   = 127.0.0.1
            sin_port   = <port passed by user>
        }
    */
    struct sockaddr_in servAddr;
    socklen_t   len;

    bzero(&servAddr, sizeof(servAddr));
    servAddr.sin_family = AF_INET;               //AF_INET = IPv4.
    servAddr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1 -> htonl(2130706433) → converts host integer 127.0.0.1 into network byte order.
    servAddr.sin_port = htons(atoi(av[1]));      //port from CLI arg

    //Binding
    /*
        Socket FD=3 bound to:
        IP: 127.0.0.1
        Port: e.g., 8080

        FD=3 now in LISTEN state:
        Incoming SYN packets -> connection queue
    */
    if ((bind(sockfd, (const struct sockAddr*)&servAddr, sizeof(servAddr))) < 0)
        ft_error(NULL);
    if (listen(sockfd, 10) < 0)  //10 = backlog queue length for pending connections
        ft_error(NULL);

    // MAIN SERVER LOOP (select-based)
    // The server:
    // 1. Copies active set to readfds & writefds
    // 2. Calls select() to wait until any FD is ready to read/write
    // 3. Iterates over all FDs to:
    //    - Accept new connections (if listening socket is ready)
    //    - Receive messages from clients
    //    - Handle disconnections
    //    - Broadcast messages via sendAll()
    While(1)
    {
        // Copy active set into readfds and writefds for select()
        readfds = writefds = active;

        // Wait for any socket to be ready for reading/writing
        if (select(fdMax + 1, &readfds, &writefds, NULL, NULL) < 0)
            continue; //ignore error frm select
        
        // Loop over all possible file descriptors
        for (int idI = 0; idI <= fdMax; idI++)
        {
            // If the listening socket is ready to read -> new connection
            if (FD_ISSET(fdI, &))


        }



    }


}