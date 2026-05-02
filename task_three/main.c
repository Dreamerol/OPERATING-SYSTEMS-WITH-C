#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>

int main (int argc, char* argv[]){
int fd_one;
char c;
int lines = 0;
int words = 0;
int chars = 0;

if(argc != 2){

write(2, "Invalid num args\n", 17);
exit(1);
}
fd_one = open(argv[1], O_RDONLY);
if(fd_one == -1){

 write(2, "Cannot open file for reading\n", 29);
 exit(1);
 }
bool word = false;

while(read(fd_one, &c, sizeof(c)) == sizeof(c)){
chars++;
if(c == '\n'){
lines++;
if(word){
words++;
word = false;
}
}
else if(c == ' '){
if(word){
  words++;
  word = false;
  }
}
else{
word = true;
}
}
printf("FIle %s has\n%d number of lines\n%d number of words\n%d number of chars\n",
argv[1], lines, words, chars);
close(fd_one);
}


