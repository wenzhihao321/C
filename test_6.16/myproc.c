#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
  pid_t id =fork();
  if(id == 0)
  {
    //child
    int count = 0;
    while(count < 10)
    {
      printf("I am child, pid: %d, ppid: %d\n",getpid(),getppid());
      sleep(3);
      count++;
    }
    exit(1);
  }
  while(1)
  {
    int status = 0;
    pid_t ret = waitpid(id, &status, WNOHANG);
    if(ret > 0)
    {
      printf("wait success!\n"); 
      printf("exit code: %d\n",WEXITSTATUS(status));
      break;
    }
    else if(ret == 0)
    {
      printf("father do other things!\n");
      sleep(1);
    }
    else
    {
      printf("waitpid error!\n");
      break;
    }
  }
  char *myargv[] = { "ls", "-a","-i","-l", NULL};
  execl("/usr/bin/ls","ls","-a","-i","-l",NULL);
  execl("/usr/bin/top","top",NULL);
  execlp("ls","ls","-a","-i","-l",NULL);
  execvp("ls",myargv);
  execv("/usr/bin/ls",myargv);
  execv("/usr/bin/ls",myargv);
  return 0;
}
