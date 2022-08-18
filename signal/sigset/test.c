#include<stdio.h>
#include<unistd.h>
#include<signal.h>

void printPending (sigset_t *pending)
{
    int i= 1;
    for(; i <= 31; i++){
        if(sigismember(pending, i)){
            printf( "1 " );
        }
        else{
            printf( "0 " );
        }
    }
    printf ( " \n" );
}

void handler(int signo)
{
  printf("handler signo: %d\n",signo);
}

int main()
{
    signal(2, handler);  

    sigset_t set, oset; //用户空间定义的变量
    sigemptyset(&set);
    sigemptyset(&oset) ;
    
    sigaddset(&set,2);//SIGINT

    sigprocmask(SIG_SETMASK,&set,&oset);//阻塞了2号信号
    
    sigset_t pending;
    int count = 0;
    while(1){
        sigemptyset(&pending);
        sigpending(&pending);
        
        printPending(&pending);
        sleep(1);
        count++;
        if(count == 10)
        {
          sigprocmask(SIG_SETMASK, &oset, NULL);//恢复曾经的信号屏蔽字
          printf("恢复信号屏蔽字\n");
        }
    }
    
    return 0;
}
