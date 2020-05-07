#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
 char src[10],dest[10],ch[2];
 int fd1,fd2,c;
 printf("enter the source file name:");
 scanf("%s",src);
 if((fd1=open(src,O_RDONLY))==-1)
 {
   printf("error in opening src file");
   exit(0);
 }
 printf("enter the destination file:");
 scanf("%s",dest);
 if((fd2=open(dest,O_CREAT|O_WRONLY,0700))==-1)
 {
  printf("error in destination file");
  exit(0);
 }
printf("%s contains:\n",src);
while(read(fd1,ch,1)==1)
{
 write(1,ch,1);
 write(fd2,ch,1);
}
 printf("file is copied");
 close(fd1);
 close(fd2);
 return 1;
}
