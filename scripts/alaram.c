#include <stdlib.h>
#include <signal.h>

typedef struct File
{
  int pid;
  struct File *pids;
} *file;

file file1 = NULL;

//this fonction is to suspend a process using its pid number
int V(int pid_num)
{
  //does the kill fonction just kill the process or will it take into account the signal argument?
  kill(pid_num, SIGSTOP);
  file1 = ajouter(file1, pid_num);
  return 0;
}

//this is to restart the process
int C()
{
  if (file1 != NULL)
  {
    //I know the kill fonction is not the right one but I just don't know any other to take as argument the pid of a process to restart it
    kill(file1->pid, SIGCONT);
  }
  return 0;
}

//this fontion adds pid number to our structure
file ajouter(file file_n, int pid)
{
  file nouveau = malloc(sizeof(file));
  nouveau->pid = pid;
  nouveau->pids = file_n;
  return nouveau;
}
