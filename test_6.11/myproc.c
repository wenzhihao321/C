#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int show()
{
  printf("hello show()!\n");
  exit(12);
}
int main()
{
  for(int i=0; i < 150; i++)
  {
    printf("%d: %s\n", i, strerror(i));
  }
  show();

  printf("myproc is not done!\n");

  return 11;
}
