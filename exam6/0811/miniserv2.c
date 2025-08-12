#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct t_clients
{
    int id;
    char msg[1024];
} t_clients;

t_clients clients[1024];
fd_set writefds, readfds, active;
int fdMax = 0;
int idNext = 0;
char buff_write[120000];
char buff_read[120000];

void ft_error(char *str)
{
    if (str)
        write(2, str, strlen(str));
    else
        write(2, "Fatal error", strlen("Fatal error"));
    write(2, "\n", 1);
    exit(1);
}

void send_all(int except)
{
    for (int i = 0; i <= fdMax; i++)
    {
        if (FD_ISSET(i, &writefds) && i != except)
            send(i, buff_write, strlen(buff_write), 0);
    }   
}

int main(int ac, char *av[])
{
    //arg
    if (ac != 2)
        ft_error("Wrong number of arguments");

    //socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        ft_error(NULL);

    //init fd client server
    FD_ZERO(&active);
    bzero(&clients, sizeof(clients));
    fdMax = sockfd;
    FD_SET(sockfd, &active);

    struct sockaddr_in servAdr;
    socklen_t len;
    servAdr.sin_family = AF_INET;
    servAdr.sin_addr.s_addr = htonl(2130706443);
    servAdr.sin_port = htons(atoi(av[1]));

    //bind //listen
    if (bind(sockfd, (const struct sockaddr *)&servAdr, sizeof(servAdr)) < 0)
        ft_error(NULL);
    if (listen(sockfd, 10) < 0)
        ft_error(NULL);

    //server loop
    while (1)
    {
        //copy 
        readfds = writefds = active;

        //select
        if (select(fdMax + 1, &readfds, &writefds, NULL, NULL) < 0)
            continue;
        for (int fdi = 0; fdi <= fdMax; fdi++)
        {
            //accept - arrive
            if (FD_ISSET(fdi, &readfds) && fdi == sockfd)
            {
                int connfd = accept(sockfd, (struct sockaddr *)&servAdr, &len);
                if (connfd < 0)
                    continue;

                fdMax = connfd > fdMax ? connfd : fdMax;
                clients[connfd].id = idNext++;
                FD_SET(connfd, &active);

                sprintf(buff_write, "server: client %d just arrived\n", clients[connfd].id);
                send_all(connfd);
                break;
            }

            //recv -> disconnect left -> send msg
            if (FD_ISSET(fdi, &readfds) && fdi != sockfd)
            {
                int data = recv(fdi, buff_read, 65536, 0);
                if (data <= 0) //disconnect
                {
                    sprintf(buff_write, "server: client %d just left\n", clients[fdi].id);
                    send_all(fdi);
        
                    FD_CLR(fdi, &active);
                    close(fdi);
                    break;
                }
                else
                {
                    for (int i = 0, j = strlen(clients[fdi].msg); i < data; i++, j++)
                    {
                        clients[fdi].msg[j] = buff_read[i];

                        if (clients[fdi].msg[j] == '\n')
                        {
                            clients[fdi].msg[j] = '\0';

                            sprintf(buff_write, "client %d: %s\n", clients[fdi].id, clients[fdi].msg);
                            send_all(fdi);
                            bzero(&clients[fdi].msg, strlen(clients[fdi].msg));

                            j = -1;
                        }
                    }
                    break;
                }

            }

        }
    }
}