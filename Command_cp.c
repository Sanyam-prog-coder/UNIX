#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

// ./cdx        Source.txt  Dest.txt
//  argv[0]    	argv[1]     argv[2]

// 	argv = 3

/*
  
  Open Source File for Reading
  Create Destination File
  Read The Data from Source
  Write it into Destination
  Close both Files
  
*/
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Error : Insufficient argument\n");
        printf("Use command as ./cpx SourceFileName DestinationFileName\n");
        return -1;
    }

    int fdSrc = 0, fdDest = 0, iRet = 0;
    char Buffer[MAX_BUFFER_SIZE];

    memset(Buffer, '\0', sizeof(Buffer));

    fdSrc = open(argv[1], O_RDONLY);
    if(fdSrc < 0)
    {
        printf("Error : Unable to open source file : %s\n", argv[1]);
        return -1;
    }

    fdDest = creat(argv[2], 0777);
    if(fdDest < 0)
    {
        printf("Error : Unable to create destination file : %s\n", argv[2]);
        close(fdSrc);
        return -1;
    }

    while((iRet = read(fdSrc, Buffer, sizeof(Buffer))) != 0)
    {
        if(write(fdDest, Buffer, iRet) != iRet)
        {
            printf("Error : Write failed\n");
            close(fdSrc);
            close(fdDest);
            return -1;
        }
    }

    printf("Success : Copy activity Done\n");

    close(fdSrc);
    close(fdDest);

    return 0;
}

