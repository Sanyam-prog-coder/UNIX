#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

// ./mvx        SourcePAth   DestPath
//  argv[0]    	argv[1]      argv[2]

// 	argv = 3

/*
  
  Open Source File for Reading
  Create Destination File
  Read The Data from Source
  Write it into Destination
  Close both Files
  
*/

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("Error : Insufficient argument\n");
        printf("Use command as ./mvx SourcePath DestinationPath\n");
        return -1;
    }

    if(rename(argv[1],argv[2]) == -1)
    {
        printf("Error : Unable to move\n");
        return -1;
    }
    return 0;
}

