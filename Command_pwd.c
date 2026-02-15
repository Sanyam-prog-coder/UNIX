#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

// ./pwdx     
//  argv[0]    	 

// 	argv = 1

/*
    
    Call the system call getcwd
    Print the Result of getcwd

*/

int main(int argc, char *argv[])
{
    char Buffer[1024] = {'\0'};

    getcwd(Buffer, sizeof(Buffer));

    printf("%s",Buffer);

    return 0;
}

