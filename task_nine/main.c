#include <stdio.h>
#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>
#include <err.h>
#include <fcntl.h>
#include <string.h>

int main (int argc, char* argv[])
{
	int fo = open("numbers.bin", O_WRONLY | O_CREAT| O_TRUNC,0644);
	uint16_t numbers[] = {55,5,555};
	ssize_t count = write(fo, numbers, sizeof(numbers));
	if(count != sizeof(numbers)){
    err(2, "write failed");
	}
	close(fo);

	if (argc != 2) {
		errx(1, "err");
	}
	int fd = open("numbers.bin", O_RDONLY);
    uint16_t num;
    uint16_t mini = 555;
    uint16_t maxi = 0;
    if(strcmp(argv[1],"--min")==0){
    while(read(fd,  &num, sizeof(num)) > 0){
    if(num < mini){
    mini = num;
    }
    }
        printf("Min number %d\n",mini);


    }
     else if(strcmp(argv[1],"--max")==0){
      while(read(fd,  &num, sizeof(num)) > 0){
      if(num > maxi){
      maxi = num;
      }
      }
        printf("Max number %d\n",maxi);

      }
      else if(strcmp(argv[1],"--printf")==0){
        while(read(fd,  &num, sizeof(num)) > 0){
    printf("number %d\n",num);

        }
        }

    close(fd);
    return 0;
}
