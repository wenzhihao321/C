#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>

void handler(int signo)
{
    printf("got a singal！ signo: %d\n", signo);
    signal(signo, handler);
}

int main()
{
    for(int signo=1; signo<32; signo++){
        signal(signo, handler);
      }

    while(1){
        sleep(1);
    }
  
  
  
 //    if(fork() == 0){      
 //    //child printf ( "I am child, pid: %d\n" , getpid( ));
 //       sleep( 3);
 //      // int a = 1/0;
 //       int *p = NULL;
 //       *p = 2;
 //       exit(0);
 //   }
 //   int status = 0;
 //   waitpid( -1, &status,0);
 //   //0000 0000 0000 0000
 //   //0000 0000 1000 0000
 //   printf ( "exit code: %d,coredump: %d , signal %d\n",
 //           (status>>8)&0xff, (status>>7)&1 ,status&0x7f);
 //             //退出码                      信号编号
  return 0;
}
