#include <stdlib.h>
#include <err.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char* argv[]){
if (argc == 1) {
		errx(1, "err");
	}
int fd = open(argv[1],O_RDONLY);
if(fd == -1) {
		err(2, "%s", argv[1]);
	}
for(int i = 2;i < argc; i++){
int read_size;
int cur_fd = open(argv[i],O_WRONLY|O_CREAT, 0644);
 if(cur_fd == -1) {
            err(2, "%s", argv[i]);
        }

char c;
while((read_size = read(fd, &c, sizeof(c))) > 0){
if (write(cur_fd, &c, read_size) != read_size ) {
			err(1, "Error while writing");
		}
}
close(cur_fd);
if(lseek(fd, 0, SEEK_SET)==-1){
err(3,"Error while seeking");
}
}
close(fd);
exit(0);

}
