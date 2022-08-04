#include "comm.h"

int main()
{
  int fd = open (FILE_NAME, O_WRONLY);
  if(fd < 0){
      printf ( "open error!\n" );
      return 1;
    }
  char msg[128];
  while(1){
      msg[0] = 0;
      printf ("Please Enter# ");
      fflush(stdout);
      ssize_t s = read (0,msg, sizeof(msg));
      if(s > 0){
          msg[s - 1] = 0;
          write( fd, msg, strlen(msg));
      }
    }
  close(fd);
  return 0;
}
