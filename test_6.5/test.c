#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

int g_unval;
int g_val = 100;
int main(int argc, char *argv[], char *envp[])
{
  printf("code addr: %p\n", main);
  char *str = "hello world";
  printf("read only addr: %p\n", str);
  printf("init addr: %p\n", &g_val);
  printf("uninit addr: %p\n", &g_unval);
  
  int *p = malloc(10);
  printf("heap addr: %p\n", p);
  
  printf("stack addr: %p\n", &str);
  printf("stack addr: %p\n", &p);
  
  for(int i = 0; i < argc; i++)
  {
    printf("args addr: %p\n", argv[i]);
  }
  int i = 0;
  while(envp[i])
  {
    printf("envp addr: %p\n", envp[i]);
    i++;
  }
  //printf("%s\n", getenv("PATH"));
  //extern char **environ;
  //for(int i = 0; environ[i]; i++)
  //{
  //  printf("%s\n", environ[i]);
  //}
  //return 0;
}
