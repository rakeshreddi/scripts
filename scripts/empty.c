#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<stdlib.h>
#include<sys/types.h>
int main(int argc ,char **argv)
{
 DIR *dp;
 struct dirent *dirp;
 char p[8];
 if(argc==1)
   strcpy(p,".");
else
{
 strcpy(p,argv[1]); 
}
   if((dp=opendir(p))==NULL)
   {
    printf("can't open directoey");
   exit(0);
    }
 while((dirp=readdir(dp))!=NULL)
 {
  printf("%s\n",dirp->d_name);
 }
 closedir(dp);
return 1;
}
