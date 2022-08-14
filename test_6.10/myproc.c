#include<stdio.h>
#include<unistd.h>

int main()
{
  pid_t id = fork();
  if(id == 0)
  {
    //child
    while(1)
    {
       printf("child: pid : %d, ppid : %d\n",getpid(),getppid());
       sleep(2);
    }
  }
  else{
    //id > 0 father
    while(1)
    {
       printf("father: pid : %d, ppid : %d\n",getpid(),getppid());
       sleep(1);
    }
  }
  system("pause");
  return 0;
}
