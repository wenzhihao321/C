#include"comm.h"
#include <sys/wait.h>
#include <stdlib.h>

int main ()
{
  if (mkfifo(FILE_NAME, 0644)< 0)
  {
    perror( "mkfifo" );
    return 1;
  }
  int fd = open(FILE_NAME, O_RDONLY);
  if(fd<0)
  {
    perror("open error!\n");
    return 2;
  }
  char msg[128];
  while(1)
  {
    msg[0] = 0;
    ssize_t s = read(fd,msg,sizeof(msg)-1);
    if(s > 0)
    {
      msg[s] = 0;
      printf ( "client# %s\n" , msg);
      if(fork() == 0)
      {      //要执行谁，要怎么执行
        execlp(msg, msg ,NULL);
        exit(1);
      }
      waitpid(-1,NULL,0);
    }
    else if(s ==0)
    {
      printf ( "client quit! \n" );
      break;
    }
    else  
    {
      printf ( " read error! \n" );
      break;
    }
  }
  close(fd);
  return 0;
}
