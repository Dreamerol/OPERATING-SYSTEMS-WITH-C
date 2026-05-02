#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <err.h>

int main (int argc, char*  argv[]){
if(argc == 1){
errx(1, "err");
}

for(int i = 1;i < argc;i++){
int fd = open(argv[i],O_RDONLY);
if(fd == -1){
err(2, "%s", argv[1]);
}
int readSize;
char c;
while((readSize = read(fd, &c, sizeof(c))) > 0){
if (write(1, &c, readSize) != readSize ){
err(1, "Error");
}
}
close(fd);

}
exit(0);
}
