// SERVER CODE

#include<stdio.h>           // printf, scanf
#include<stdlib.h>          // malloc, free
#include<string.h>          // memset, memcmp

#include<unistd.h>          // close, write, read
#include<fcntl.h>           // creat, ulink

#include<sys/socket.h>      // socket, bind, listen, accept, conect
#include<netinet/in.h>      // sockaddr_in, htons

/*
struct sockaddr 
{
    sa_family_t sa_family;
    char sa_data[14];
};
*/
int main()
{
    int ServerSocket = 0;
    int iRet = 0;
    int port = 11000;

    struct sockaddr_in ServerAddr;

    // STEP 1 : Create TCP socket 

    ServerSocket = socket(AF_INET, SOCK_STREAM, 0);

    if(ServerSocket < 0)
    {
        printf("Unable to creat Socket\n");
        return -1;
    }

    printf("Socket gets Created Succefully with fd : %d\n",ServerSocket);

    // STEP 2 : Attach the socket to IP address & port number

    // set memory with 0
    memset(&ServerAddr, 0, sizeof(ServerAddr));

    ServerAddr.sin_family = AF_INET;
    ServerAddr.sin_addr.s_addr = INADDR_ANY;
    ServerAddr.sin_port = htons(port);

    iRet = bind(ServerSocket, (struct sockaddr*) &ServerAddr, sizeof(ServerAddr));

    if(iRet == -1)
    {
        printf("Bind System call Failed\n");
        close(ServerSocket);
        return -1;
    }

    printf("Bind Operation With Socket is Succeful\n");

    return 0;
}