#include<stdio.h>
#include<stdlib.h>
int main()
{
 char src[10],dest[10],ch;
 FILE *fp1,*fp2;
 printf("enter the source file name:");
 scanf("%s",src);
 if((fp1=fopen(src,"r"))==0)
 {
   printf("error in opening src file");
  exit(0);
 }
 printf("enter the destination file name:");
 scanf("%s",dest);
 if((fp2=fopen(dest,"w"))==0)
 {
  printf("error in destination file");
 exit(1);
 }
 printf("%s contains:\n",src);
 while((ch=getc(fp1))!=EOF)
 {
  fputc(ch,fp2);
  printf("%c",ch);
 }
 printf("file is copied.");
fclose(fp1);
fclose(fp2);
return 1;
}

