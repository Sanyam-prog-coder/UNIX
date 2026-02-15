#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>

// ./statx     FileName
//  argv[0]    	argv[1] 

// 	argv = 2

/*
    
    Accept file Name from Command Line
    Call access to check existance of file
    Call stat System call to get files metadata
    Display the metadata

*/

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Error : Insufficient argument\n");
        printf("Use command as ./statx FileName\n");

        return -1;
    }

    if(access(argv[1] , F_OK) == 0)
    {
        struct stat sobj;
        int iRet = 0;

        iRet = stat(argv[1],&sobj);

        if(iRet == -1)
        {
            printf("Error : Unable to fetch Statistical information\n");

            return -1;
        }

        printf("File Name : %s\n",argv[1]);
        printf("File Size : %ld\n",(long)sobj.st_size);
        printf("Inode Number : %ld\n",(long)sobj.st_ino);
        
    }
    else
    {
        printf("Error : File Not Found\n");
        return -1;
    }

    return 0;
}

