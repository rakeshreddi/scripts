#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int
main(void)
{
  int mq; /* the queue handler */
  /* create a key for the queue */
  key_t k = ftok("/var", 'c');
  if(k != -1) { /* did we succeed? */
    /* get the queue (create if it doesn't exist) */
    mq = msgget(k, 0644 | IPC_CREAT);
    if(mq != -1) { /* did we succeed */
      char b[256] = ""; /* a message buffer */
      size_t l; /* the length of the string from stdin */
      /* get some data from the command line */
      while(fgets(b, sizeof(b), stdin) != NULL) {
        if((l = strlen(b)) > 0) { /* did we get anything? */
          /* change the '\n' to a '\0' */
          if(b[l - 1] == '\n') { b[l - 1] = 0; l--; }
          /* is it the command to quit? */
          if(strcmp(b, "quit") == 0) break;
          /* send the message to the queue */
          if(msgsnd(mq, &b, l, 0) == -1) {
            perror("msgsnd()");
            break;
          }
        }
      }
    } else {
      perror("msgget()");
      return 2;
    }

    /* close the queue */
    if(msgctl(mq, 0, NULL) == -1) {
      perror("msgctl()");
      return 3;
    }
  } else {
    perror("ftok()");
    return 1;
  }

  return 0;
}
