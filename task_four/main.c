#include <stdio.h>
#include <err.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
        errx(1, "err");

    int fd_one = open(argv[1], O_RDWR);
    if (fd_one == -1)
        err(2, "%s", argv[1]);

    int fd_two = open(argv[2], O_RDWR);
    if (fd_two == -1)
        err(3, "%s", argv[2]);

    int fd_three = open("temp_file",
                   O_CREAT | O_RDWR | O_TRUNC,
                   0644);
    if(fd_three == -1)
         err(4, "%s", "temp_file");

    char c[4096];
    ssize_t readSize;

    while((readSize = read(fd_one, &c, sizeof(c))) > 0){
    if(write(fd_three, &c, readSize) != readSize){
     err(1, "err");
    }
    }
    if(readSize != 0){
     err(2, "err");

    }

    if(lseek(fd_one, 0, SEEK_SET) == -1){
     err(3, "err");

    }

    while((readSize = read(fd_two, &c, sizeof(c))) > 0){
      if(write(fd_one, &c,readSize) != readSize){
       err(1, "err");
      }
      }
      if(readSize != 0){
       err(2, "err");
 
     }
 
      if(lseek(fd_two, 0, SEEK_SET) == -1 || lseek(fd_three, 0, SEEK_SET) == -1){
       err(3, "err");
 
      }

    while((readSize = read(fd_three, &c, sizeof(c))) > 0){
        if(write(fd_two, &c,readSize) != readSize){
         err(1, "err");
        }
        }
        if(readSize != 0){
         err(2, "err");
 
       }
  close(fd_one);
  close(fd_two);
  close(fd_three);
  exit(0);
  }



