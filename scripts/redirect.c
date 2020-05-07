#include<stdio.h>
int main()
{
int n,f1;
FILE *fd;
char line[200],buff[200];
fd=popen("ls -l","r");
while((fgets(line,200,fd))!=NULL)
printf("%s\n",line);
if((f1=creat("xx.txt",0644))<0)
printf("ERROR IN CREATING");
while((n=read(line,buff,sizeof(buff)))>0)
write(f1,line,n);
//printf("WRITE ERROR");
close(f1);
return 0;
}
