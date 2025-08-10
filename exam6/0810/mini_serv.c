#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

//STRUCT
typedef struct s_clients
{
    int id;
    char msg[1024];
} t_clients;

//VARIABLE
t_clients clients[1024];
fd_set readfds, writefds, active;
int fdMax = 0;
int idNext =0;
char bufferRead[120000];
char bufferWrite[1200000];

//FUNC

//ft_error
void ft_error(char *str)
{
    if (str)
        write(2, str, strlen(str));
    else
        write(2, "Fatal error", strlen("Fatal error"));
    write(2, "\n", 1);
    exit(1);
}

//send_all
//int FD_ISSET(int fd, fd_set *set);  //set: pointer to the fd_set you want to check.
//extern ssize_t send (int __fd, const void *__buf, size_t __n, int __flags);
void send_all(int except) //do not send to this client 
{
    for (int i = 0; i <= fdMax; i++)
    {
        if (FD_ISSET(i, &writefds) && i != except)
            send(i, bufferWrite, strlen(bufferWrite), 0);
    }
}



//MAN
int main(int ac, char *av[])
{
    //check arg
    if (ac != 2)
        ft_error("Wrong number of arguments");
    
    //TCP socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        ft_error(NULL);

    //init all fds & clients 
    FD_ZERO(&active);
    bzero(&clients, sizeof(clients));
    fdMax = sockfd; //at start, highest FD is the listening socket
    FD_SET(sockfd, &active);
    
    //init server addr
    struct sockaddr_in servAdr;
    socklen_t len;

    bzero(&servAdr, sizeof(servAdr));
    servAdr.sin_family = AF_INET; //IPv4
    servAdr.sin_addr.s_addr = htonl(2130706433); //127.0.0.1 
    servAdr.sin_port = htons(atoi(av[1]));

    //bind
    //listen -> allow 10 pending connections in the queue before refusing new ones
    if (bind(sockfd, (const struct sockaddr *)&servAdr, sizeof(servAdr)) < 0)
        ft_error(NULL);
    if (listen(sockfd, 10) < 0)
        ft_error(NULL);

    //server loop
    while (1)
    {
        //copy active content
        readfds = writefds = active;

        //select
        if (select(fdMax + 1, &readfds, &writefds, NULL, NULL) < 0)
            continue; //ignore erro frm select
        
        //loop thru all fds
        for (int fdi = 0; fdi <= fdMax; fdi++)
        {
            //if listening socket ready to read
            if (FD_ISSET(fdi, &readfds) && fdi == sockfd)
            {
                int connfd = accept(sockfd, (struct sockaddr *)&servAdr, &len);
                if (connfd < 0)
                    continue; //ignore if accept fail
                // Update max FD
                fdMax = connfd > fdMax ? connfd : fdMax;

                clients[connfd].id = idNext++;
                FD_SET(connfd, &active); //add to active set

                sprintf(bufferWrite, "server: client %d just arrived\n", clients[connfd].id);
                send_all(connfd);

                break; //go back to select()
            }  


            //if client sent data
            if (FD_ISSET(fdi, &readfds) && fdi != sockfd)
            {
                int data = recv(fdi, bufferRead, 65536, 0);

                if (data <= 0) //the client disconnected -> notify all other clients
                {
                    sprintf(bufferWrite, "server: client %d just left\n", clients[fdi].id);
                    send_all(fdi);
                    FD_CLR(fdi, &active);
                    close(fdi);
                    break;
                }
                else //if not disconnect -> send out msg
                {
                    //append byte to client msg buffer
                    for (int i = 0, j = strlen(clients[fdi].msg); i < data; i++, j++)
                    {
                        clients[fdi].msg[j] = bufferRead[i];

                        //complete line
                        if (clients[fdi].msg[j] == '\n')
                        {
                            clients[fdi].msg[j] = '\0'; //terminate str

                            sprintf(bufferWrite, "client %d: %s\n", clients[fdi].id, clients[fdi].msg);
                            send_all(fdi);
                            bzero(&clients[fdi].msg, strlen(clients[fdi].msg));

                            j = -1; //reset
                        }
                    }
                    break; 
    
                }
            }

        }

    }
}

/*
+-------------------+         +-------------------+         +-------------------+
|    Client 1       |         |    Client 2       |         |    Client 3       |
+-------------------+         +-------------------+         +-------------------+
         |                             |                             |
         |------"hello\n"------------->|                             |
         |                             |                             |
         |                             |                             |
         |<-----"client 0: hello\n"----|<-----"client 0: hello\n"----|
         |                             |                             |
         |                             |                             |
         |---(disconnects)------------>|                             |
         |                             |                             |
         |<--"server: client 0 just left\n"--------------------------|
         |                             |                             |

*/