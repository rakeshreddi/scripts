#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
 pid_t pid;
 pid=fork();
 if(pid==0)
 {
  printf("child process...");
  printf("process id=%d,parentid=%d",getpid(),getppid());
  sleep(15);
  printf("termination of child");
 }
 if(pid>0)
 { 
   printf("parent process:%d",getpid());
   printf("termination of parent.");
}
}
