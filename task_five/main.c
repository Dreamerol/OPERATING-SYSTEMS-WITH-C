#include <fcntl.h>
#include <err.h>
#include <unistd.h>
#include <stdlib.h>


int main (int argc,char* argv[]){
if(argc != 3){
errx(1, "err");
}
int fd_one = open(argv[1], O_RDONLY);
if(fd_one == -1){
err(2, "%s", argv[1]);
}
int fd_two = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0644);
if(fd_two == -1){
  err(2, "%s", argv[2]);
  }
char c;
int readSize;
while((readSize = read(fd_one, &c,  sizeof(c)))>  0){
if(write(fd_two, &c,  readSize) != readSize){
err(1, "Error while writing");
}

}
close(fd_one);
close(fd_two);
exit(0);


}
