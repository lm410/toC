/*************************************************************************
	> File Name: nsTest.c
	> Author: 
	> Mail: 
	> Created Time: 二  6/26 22:19:28 2018
 ************************************************************************/

#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>
#include<stdio.h>

int main() 
{
    int childpid;  
int i;  
  
if ((i = fork()) == 0){  
    //child process  
    char * execv_str[] = {"echo", "executed by execv",NULL};  
    printf("child--%d", i);
    if (execv("/usr/bin/echo",execv_str) <0 ){  
        perror("error on exec");  
        exit(0);  
    }  
}else{  
    //parent process  
    wait(&childpid);  
    printf("execv done\n\n");  
}  
    return 0;
} 
