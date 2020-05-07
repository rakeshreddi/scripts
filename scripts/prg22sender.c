#include <stdio.h>
#include <sys/ipc.h>
#include <fcntl.h>
#define MAX 255
        struct mesg
        {
              long type;
              char mtext[MAX];
        }  *mesg;
        char buff[MAX];
main()
{
        int mid,fd,n,count=0;;
        if((mid=msgget(1006,IPC_CREAT | 0666))<0)
        {
                printf(“\n Can’t create Message Q”);
                exit(1);
        }
        printf(“\n Queue id:%d”, mid);
        mesg=(struct mesg *)malloc(sizeof(struct mesg));
        mesg ->type=6;
        fd=open(“fact”,O_RDONLY);
        while(read(fd,buff,25)>0)
        {
                strcpy(mesg ->mtext,buff);
                if(msgsnd(mid,mesg,strlen(mesg ->mtext),0)== -1)
                     printf(“\n Message Write Error”);
        }

        if((mid=msgget(1006,0))<0)
        {
                printf(“\n Can’t create Message Q”);
                exit(1);
        }
        while((n=msgrcv(mid,&mesg,MAX,6,IPC_NOWAIT))>0)
                write(1,mesg.mtext,n);
                count  ;
        if((n= = -1)&(count= =0))
                printf(“\n No Message Queue on Queue:%d”,mid);

}
