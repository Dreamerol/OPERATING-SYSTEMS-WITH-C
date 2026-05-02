#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <err.h>

int main(void){
int fd = open("pass", O_RDWR);
if(fd == -1){
err(2, "pass");
}
char c;
while(read(fd, &c, 1) == 1){
if(c == ':'){
int pos = lseek(fd,0 , SEEK_CUR);
if(lseek(fd, pos-1, SEEK_SET)==-1)
{
err(3,"Error while seeking");
}
char replace='?';
if(write(fd, &replace,1) != 1){
err(2, "Error while writing");
}
lseek(fd, pos, SEEK_SET);
}
}

close(fd);
exit(0);
}
