#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
    int fd_one;
    int i = 0;
    char c;

    if(argc != 2){
     write(2, "error\n", 6);
     exit(1);
    }

    fd_one = open(argv[1], O_RDONLY);
    if(fd_one == -1){
    write(2, "File failed to open in write mode\n", 33);
      exit(1);
    }

    while(read(fd_one, &c, sizeof(c)) == sizeof(c)){
    if (c == '\n'){
     i = i + 1;
    }
    write(1, &c, 1);
    if (i == 10){
    break;
    }
    }
    close(fd_one);
    exit(0); 


}
