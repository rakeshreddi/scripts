#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
 if(fork()>0)
 {
   printf("parent with %d",getpid());
  sleep(10);
 }
}
