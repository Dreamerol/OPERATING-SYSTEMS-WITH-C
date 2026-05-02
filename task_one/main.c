#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
   int fd_one;
   int fd_two;
   char c;

   fd_one = open("foo.txt", O_RDONLY);
   if(fd_one == -1){
     write(2, "File failed to open in read mode\n", 33);
     exit(1);

   }
   fd_two = open("newi.txt",O_CREAT|O_WRONLY,0644);
   if(fd_two == -1){
      write(2, "File failed to open in write mode\n", 34);
		exit(1);
 
     }

   while( read(fd_one, &c, 1) == 1){
    write(fd_two, &c, 1); 
   }

   close(fd_one);
   close(fd_two);
   exit(0); 



}
