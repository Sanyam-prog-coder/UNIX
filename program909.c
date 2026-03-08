#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    setenv("LANGUAGE","C Programming", 1);

    printf("Langauge is : %s\n",getenv("LANGUAGE"));

    return 0;
}