#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
 pid_t pid;
 pid=fork();
 if(pid<0)
 {
  perror("error in fork:");
 }
 if(pid==0)
{
 printf("\nchild process..");
}
if(pid>0)
{
 printf("\nparent process..");
}
}
