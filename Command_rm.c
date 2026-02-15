#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/utsname.h>

// ./rmx    FileName 
//  argv[0] argv[1]    	 

// 	argc = 2

/*
    
    Call the System call uname
    print the information from utsname Structure

*/

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        printf("Error : Insufficient argument\n");
        printf("Use as : ./rmx Path\n");

        return -1;
    }

    if(access(argv[1], F_OK) == 0)
    {
        if(unlink(argv[1]) == -1)
        {
            printf("Error : Unable to delete\n");
            return -1;
        }
        else
        {
            printf("Success : File gets Deleted\n");
        }
    }
    else
    {
        printf("Error : Unable to Delete as File");
        return -1;
    }


    return 0;
}

