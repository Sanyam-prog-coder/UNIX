#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>

// ./lsx       
//  argv[0]    

// 	argv = 1

/*

	Open the Current Directory(".")
	read all aentries from that directory
	print the name of file
	close the directory  
  
*/


int main(int argc, char *argv[])
{
	char *path = ".";
	
	DIR *dp = NULL;
	
	dp = opendir(path);
	if(dp == NULL)
	{
	printf("Error : Unable to ioen Directory\n");
	return -1;	
	}
	
	struct dirent *dobj;

    while((dobj = readdir(dp)) != NULL)
    {
        printf("%s\n",dobj->d_name);
    }
    closedir(dp);
    
    return 0;
}
