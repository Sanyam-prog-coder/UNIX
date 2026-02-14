// CLIENT CODE

#include<stdio.h>           // printf, scanf
#include<stdlib.h>          // malloc, free
#include<string.h>          // memset, memcmp

#include<unistd.h>          // close, write, read
#include<fcntl.h>           // creat, ulink

#include<sys/socket.h>      // socket, bind, listen, accept, conect
#include<netinet/in.h>      // sockaddr_in, htons

#include<arpa/inet.h>       // inet_pton

int main()
{
    int ServerSocketFD = 0;
    int iRet = 0;
    int port = 11000;

    struct sockaddr_in ServerAddr;

    // STEP 1 : Creat TCP socket

    ServerSocketFD = socket(AF_INET, SOCK_STREAM, 0);

    if(ServerSocketFD < 0)
    {
        printf("Unable to create socket\n");
        return -1;
    }

    printf("Socket gets Created Succefully with fd : %d\n",ServerSocketFD);

    // STEP 2 : Connect with the server

    memset(&ServerAddr, 0, sizeof(ServerAddr));

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_port = htons(port);
    
    // 127.0.0.1 -> Binary form
    inet_pton(AF_INET, "127.0.0.1", &ServerAddr.sin_addr);
    
    iRet = connect(ServerSocketFD, (struct sockaddr *) &ServerAddr, sizeof(ServerAddr));

    if(iRet == -1)
    {
        printf("Unable to connect with server\n");
        return -1;
    }

    printf("Client succesfully connected with server\n");

    return 0;
}