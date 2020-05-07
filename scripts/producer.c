#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#define MAXSIZE 10
#define FIFO_NAME "myfifo"
main()
{
int fifoid;
int fd, n;
char *w;
system("clear");
w=(char *)malloc(sizeof(char)*MAXSIZE);
int open_mode=O_WRONLY;
fifoid=mkfifo(FIFO_NAME, 0755);
if(fifoid==-1)
{
printf("\nError: Named pipe cannot be Created\n");
54
exit(0);
}
if( (fd=open(FIFO_NAME, open_mode)) < 0 )
{
printf("\nError: Named pipe cannot be opened\n");
exit(0);
}
while(1)
{
 printf("\nProducer :");
 fflush(stdin);
 read(0, w, MAXSIZE);
 n=write(fd, w, MAXSIZE);
 if(n > 0)
 printf("\nProducer sent: %s", w);
}
} /*main close*/
