#include<stdio.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>
#include<dirent.h>
int main(int argc,char **argv)
{
DIR *dp;
struct stat buf;
ino_t ino;
struct dirent *dirp;
if(argc!=2)
 {
 printf("usage:dirname");
 exit(1);
}
 if((dp=opendir(argv[1]))==NULL)
    perror("open:");
 printf("\nfile_name  inode");
 printf("\n----------------");
while((dirp=readdir(dp))!=NULL)
{
 stat(dirp->d_name,&buf);
ino=buf.st_ino;           
printf("\n %ld  %s",ino,dirp->d_name);
}
return 1;
}
