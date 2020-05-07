#include
#include
#include
main()
{
int msqid,t;
int key,r;
struct mymsg
{
long type;
char mtext[512];
}msg;
key=ftok("arth.sh",78);
printf("Enter the type of the message :\n");
scanf("%ld",&msg.type);
msqid=msgget(key,IPC_CREAT|0666);
r=msgrcv(msqid,&msg,sizeof(msg),msg.type,IPC_NOWAIT);
if(r==-1)
{
printf("Message received failed\n");
}
else
{
printf("Message received successively\n");
printf("Message = %s",msg.mtext);
}
}
