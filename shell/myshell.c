#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

#define LEN 1024
#define NUM 32

int main()
{
  int type = 0; // 0 >,1 >> 2 <
  char cmd[LEN];
  char *myarg [NUM];
  while(1)
  {
      printf( "[wzh@my-centos_mc dir]# " );
      fgets (cmd, LEN, stdin);
      cmd[strlen(cmd)-1] = '\0';
      
      char *start = cmd ;
      while(*start != '\0' )
      {
          if(*start == '>')
          {
              type = 0;
             *start = '\0';
              start++;
              if(*start == '>')
              {
                type = 1;
                start++;
              }
              break;
          }
          if(*start == '<')
          {
            type = 2;
            *start = '\0';
            start++;
            break;
          }
            start++;
      }
      if(*start != '\0')
      {
        while(isspace(*start))
        {
          start++;
        }
       // printf("%s\n", start);
      }
      else{
        start = NULL;
      }
      myarg[0] = strtok (cmd ," ");
      int i = 1;
      while(myarg[i] = strtok(NULL, " "))
      {
         i++;
      }
      //printf("%s", cmd);
      pid_t id = fork();
      if(id == 0)
      {
        //child
        if(start != NULL)
        {
          if(type == 0)
          {
            int fd = open(start,O_WRONLY|O_CREAT,0644);
            if(fd < 0)
            {
              perror("open");
              exit(2);
            }
            dup2(fd,1);
          }
          else if(type == 1)
          {

          }
          else if(type == 2)
          {
            int fd = open(start,O_RDONLY);
            dup2(fd,0);
          }
          else
          {

          }
        }
        execvp(myarg[0],myarg);
        exit(0);
      }
      int status = 0;
      pid_t ret = waitpid(id, &status, 0);
      if(ret > 0)
      {
        printf("exit code: %d\n", WEXITSTATUS(status));
      }
  }
  return 0;
}
