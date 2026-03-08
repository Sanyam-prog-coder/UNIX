#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>

void ShowProcessInformation(int pid)
{
    FILE *fp = NULL;
    char line[80];
    char fileName[100];

    sprintf(fileName,"/proc/%d/status",pid);

    printf("Accesing the file : %s\n",fileName);

    fp = fopen(fileName,"r");

    if(fp == NULL)
    {
        printf("Unable to access system file\n");
        return;
    }

    printf("------------------------------------------------\n");
    printf("------------- Process Information --------------\n");
    printf("------------------------------------------------\n");

    while(fgets(line,sizeof(line),fp) != NULL)
    {
        printf("%s\n",line);
    }

    printf("------------------------------------------------\n");

}

int main()
{
    int pid = 0;

    printf("------------------------------------------------\n");
    printf("--------- Marvellous Process Inspector ---------\n");
    printf("------------------------------------------------\n");

    printf("Enter the PID of a process that you want to inspect\n");
    scanf("%d",&pid);

    if(pid <= 0)
    {
        printf("Invalid PID\n");
        return -1;
    }

    ShowProcessInformation(pid);

    return 0;
}