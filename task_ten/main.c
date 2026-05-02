 #include <stdio.h>
#include <fcntl.h>
#include <stdint.h>
#include <unistd.h>
#include <err.h>
#include <fcntl.h>
#include <string.h>


   int main (void)
  {
      int fo = open("numbers.bin", O_WRONLY | O_CREAT| O_TRUNC,0644);
      uint16_t numbers[] = {55,5,555};
      ssize_t count = write(fo, numbers, sizeof(numbers));
     if(count != sizeof(numbers)){
      err(2, "write failed");
      }
      close(fo);
 

      int fd = open("numbers.bin", O_RDONLY);
      uint8_t num;
      uint8_t maxi = 0;

     while(read(fd, &num, sizeof(uint8_t)) > 0) {
     if(num > maxi) maxi = num;
     }

     printf("max byte: %d\n", maxi);
     close(fd);
     return 0;
}
