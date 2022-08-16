#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include <iostream>
int main()
{
   close(1);
   umask(0);
   int fd = open("log.txt",O_WRONLY|O_CREAT, 0666);
   if(fd < 0)
   {
     return 1;
   }
   fputs("hello world",stdout);
   fputs("hello world",stdout);
   fputs("hello world",stdout);
   fputs("hello world",stdout);
   fflush(stdout);
   
   return 0;
}
