#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<sys/utsname.h>

// ./unamex     
//  argv[0]    	 

// 	argv = 1

/*
    
    Call the System call uname
    print the information from utsname Structure

*/

int main(int argc, char *argv[])
{
    struct utsname obj;
    int iRet = 0;

    iRet = uname(&obj);

    if(iRet == -1)
    {
        printf("Error : Unable to fetch System Information\n");
        return -1;
    }

    printf("Operating system Name : %s\n",obj.sysname);
    printf("Node Name : %s\n",obj.nodename);
    printf("Operating System Version : %s\n",obj.release);

    return 0;
}

