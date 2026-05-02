[USERLAND/
APPLAYER/
/US]
 | interaction
 V
[OS]

[HARDWARE]

zero -> open
one -> read
two -> write

no more working processes then number of kernels
Little/Big Endian -> Little Endial -> reverse -> the sequence of the bytes/bits
Big Endian -> normal
0xFFFF -> sixteen hex number
FF - 255 - is the last number
FFFF - 65535 -> F.16^three + F=fifteen.sixteen^two...
DEC - decrement
xxd file -> gives the result of the file
ffff - one -> feff -> little Endian actual number is fffe -> we reverse the bytes so we get fe ff
0xCAFEBABE - magic numbers JAVA

open(path, flags, mode)
success file descriptor
error -> -1, errro

OS
[PID |FD |RealFile |Meta Data |offset
 170 |5  |tmp.txt             |0
 171 |6  |lolo.txt
 170 |0 -> stdin, 1 -> stdout, 2 -> stderr

open -> system call
read(fd, address, count)
if the file for reading is empty -> returns 0
else returns the numbers if read bytes

read..
offset: 0
read....
offset: 5
read....
offset: 5 -> 56....
when the file is read we will get zero
offset increments only with the count of successfully read bytes
write - analogical to read

LINUX -> EVERYTHING IS A FILE
context switch -> when from process we go to kernel

mkdir my-first-c
cd my-first-c
touch my-first-c-file.c
--in the file
int main(void){
     return 0
}
Makefile
make -> compiles the file
file main -> executable -> accepts and compiles only main.c
one directory per task -> we write the code for the task in the main.c
touch main.c
./main - we call the file

man string.h

// :(
#include <stdio.h> ->we are not allowed to use it
#include <cstring.h>
#include <stdbool.h>
#include <stdint.h>
#include <stduni.h>

strlen, strcat...
//avoid dynamic memory -> new, delete
int main(void){
     int number = 555;
     int* array = malloc(5 * sizeof(int))
     bool flag = false; // must include stdbool.h -> no Booleans in C
     //platform-independent types
      int8_t a;
      uint8_t b;
      uint
      size_t... [type][count of bytes]

     //System calls
     //communication with the OS
     int myUser = getuid();
     printf("Myuser: %d\n", myUser);
     geteuid
 
     FILE <-> equivalent to ifstream, ofstream
     printf("Hello, world\n");
     printf("number %d\n");
     return 0
}

//zad two
-> copy fileone content in filetwo
implementing cp fileone filetwo

main.c
[fileone] -> [main] -> [filetwo]

#include <fcntl.h> // file control
#include <stdio.h>
#include <unistd.h>
int main(void){
    // O_WRONLY, O_RDWR, O_TRUNC, O_CREAT
    // RD_ONLY -> READ ONLY
    int src = open("fileone", O_RDONLY); //fd -> file descriptor
    int dest = open("fileone", O_WRONLY | O_TRUNC | O_CREAT, 0666);
    // O_CREAT -> if the file doesnt exist, because we cant write in a unexisting file
    //0666 -> permissions for the file
    //truncate to add content in the file

    printf("src = %d\n", fd);
 
    char buff;
    read(fd, &buf, sizeof("fileone", O_RDONLY))
 
    char letter = 65;
    write(1, &letter, sizeof(letter))
    write(1, &buff, sizeof(buff)) // output the content from the file

    // reads the n bytes n = 5
    for(int i = 0;i < 5; i++){
    int result = read(fd, &buff, sizeof("fileone", O_RDONLY))
    write(1, &buff, sizeof(buff))

    //implementing cat
    while(read(fd, &buff, sizeof("fileone", O_RDONLY)) != 0){
       write(1, &buff, sizeof(buff))
    }
     int* array = malloc()
     free()
     close(src)
   //result = 0 - means end of file
}
    return 0;
}
[main]
[0,...n] -> table of file descriptors -> pointing to the files
open -> find the wanted file
the file dscriptors make the connection/enables/ to the main and the files in th memory
fd -> number for the kernel

//#include <windows.h>
//handles -> the analogue of fd

fd
0 -> stdin
1 -> stdout
./main > output.txt

int src =
main accepts arguments
int main(int argc, char* argv[]){
    for(int i = 0;i<argc;i++){
printf("arg %d: %s\n", i, argv[i]);
    }
}
argc -> number of args
argv are the arguments
main function accepts ./main as the zeroth argument

./main fileone filetwo
int src = open(argv[1], O_RDONLY);
if (src == -1) {err("Cannot open file")} // if the src is -1 -> cannot open
int dest = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0666);
AFTER EVERY SYSTEM CALL WE MUST CHECK FOR ERRORS

//READ
read() > 0 -> number of bytes
read == 0 -> EOF end of file
read == -1 -> error

size_t readSize;
 while(readSize = read((fd, &buff, sizeof("fileone", O_RDONLY))) > 0){
...
if readSize == -
}
make - returns a command to execute the main.c file like a compiler
