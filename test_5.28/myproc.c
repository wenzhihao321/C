#include<stdio.h> 
#include<unistd.h> 
int main() 
{ 
  while(1)
  {
    printf("hello word!!:pid:%d, ppid:%d\n",getpid(),getppid());
    sleep(1);
  }

//  printf("I am running!!!\n");
//  pid_t id = fork();
//  if(id == 0)
//  {//child
//    while(1){
//      printf("do something!\n");
//      sleep(1);
//    }
//  }
//  else if(id > 0)
//  {
//    while(1){//parent
//      printf("call child, do something!\n");
//      sleep(2);
//    }
//  }
//  else
//  {
//    //fork erroe!  
//  }
  //while(1)
  //{
  //  printf("#,pid:%d,ppid:%d\n",getpid(),getppid());
  //  sleep(1);
  //}
  return 0;
}
