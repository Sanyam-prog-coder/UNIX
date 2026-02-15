#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

// ./cdx        DirectoryPath
//  argv[0]     argv[1] 

// 	argv = 2

/*
   
    Accept new directiry path 
    Call chdir with that path
    Call getcwd To check the Changed path

*/

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Error : Insufficient argument\n");
        printf("Use command as ./cdx DirectoryPath\n");

        return -1;
    }

    if(chdir(argv[1]) == -1)
    {
        printf("Error : Unable to change current Directory\n");

        return -1;
    }

    char Buffer[256] = {'\0'};
    
    getcwd(Buffer,sizeof(Buffer)-1);

    printf("Current Directory Change To %s\n",Buffer);

    return 0;
}

