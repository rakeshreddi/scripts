#include <stdio.h>
#include <signal.h>
int i=1;

void handle(int sig)
{
        printf("%d\n",i);
        i++;
        alarm(1);
}

void main()
{
        signal(SIGALRM,handle);
        alarm(1);
        while(i<11)
        {
                sleep(1);
        }
}
