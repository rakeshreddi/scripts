#include<stdio.h> 
#include<stdlib.h> 
#include<fcntl.h> 
#include<unistd.h> 
int main(int argc,char* argv[]) 
{ 
struct flock f1={f_wrlck,seek_set,0,0,0); 
int fd; 
f1.l_type=f_rdlck; 
if((fd=open(‘rr.txt”,o_rdwr))==-1) 
{ 
perror(“open”); 
exit(1); 
} 
printf(“press<return> to try to get lock:”); 
getchar(); 
printf(“trying to get lock”): 
if(fnctl(fd,f_setlkw,&f1)==-1) 
{ 
perror(“fcntl”); 
exit(1); 
} 
printf(“got lock \n”); 
printf(“press <return> to release lock:”); 
getchar( ); 
f1.l_type=f_unlck; 
if(fcntl(fd,f_setlk,&f1)==-1) 
{ 
perror(“fcntl”); 
exit(1); 
} 
printf(“unlocked\n”); 
close(fd); 
}
