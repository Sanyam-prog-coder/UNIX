#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    FILE *fp = NULL;
    char buffer[256];

    fp = fopen("/proc/meminfo","r");

    if(fp == NULL)
    {
        printf("Unable to open file ");
        return -1;
    }
    
    printf("--------------------------------------------\n");
    printf("----------Marvellous Memory scanner---------\n");
    printf("--------------------------------------------\n");

    while(fgets(buffer,sizeof(buffer), fp) != NULL)
    {
        printf("%s\n",buffer);
    }

    printf("--------------------------------------------\n");
    
    fclose(fp);

    return 0;
}