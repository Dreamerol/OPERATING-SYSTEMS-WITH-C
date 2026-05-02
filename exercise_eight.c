upr eight

char buffer[555] -> if we doenst want to iterate through all the bytes at once
write(dest,  &buf, readSize) -> we write exactly the bytes we have read

xxd -> gives us info for the files -g1 filename
xxd -g1 - puts empty space between each two bytes
offset on the most left
then we have firsy, second.... byte

565665: 5d a5 66 ... -> bytes of the file
working with binary files

int number = 5665;
write(dest,  &number, sizeof(number))
float dec;
write(dest,  &dec, sizeof(dec))
if we write 56 65 then it will be written in  Little-Endian
65 56

printf <-> std::cout

--zad 85
mkdir 85-task
eight bits =  byte
so four bytes will be uint_32t

#include <stdint.h>
#include <stdio.h>
#include <err.h>
#include <fcntl.h>
#include <sys/stat.h>

typedef struct Pair{
  uint_32t n_one;
  uint_32t n_two;
} Pair;


int main(int argc, char*  argv[]){
 if (argc != 4) { err(one, "bad_args");}
 int f_one = open(argv[1], O_RDONLY);
 if(f_one == -1) { err(one, "%s", argv[1]);}
 
 int f_two = open(argv[2], O_RDONLY);
 if(f_two == -1) { err(one, "%s", argv[2]);}

int f_three = open(argv[3], O_WRONLY | O_TRUNC );
 if(f_three == -1) { err(one, "%s", argv[3]);}

uint32_t n_one;
if(read(f_one, &n_one, sizeof(n_one)) == -1) {err(1, "%s", argv[1])}
uint32_t n_two;
if(read(f_one, &n_two, sizeof(n_two)) == -1) {err(1, "%s", argv[1])}

or we can
Pair pair;
if(read(f_one, &pair, sizeof(n_one)) == -1) {err(1, "%s", argv[1])}


printf("Pair <%d, %d>", n_one, n_two);
close(f_one);
close(f_two);
close(f_three);

--second way
Pair pair;
ssize_t readSize;
while(read(f_one, &pair, sizeof(n_one)) > 0){
printf("Pair", pair);
}
uint_32t arr[...]
for(int i = 0;i < yi; i++){
arr_three[] = arr_two[]
}
}

lseek -> file_descriptor -> frow where to where
if(lseek(f_two, 55 * sizeof(uint_32t), SEEK_SET) == -1) {err(one, "lseek")}-> we will read from the 55th byte

the 5th byte isn't the 5th element

man 2 fstat
man 3type stat

struct stat st;
if(fstat(f_one, &st) == -1) {err()}

--zad two zero seventeen - SE - one
--
#include <stdint.h>
#include <stdio.h>
#include <err.h>
#include <fcntl.h>
#include <sys/stat.h>

typedef struct Entry{
 uint16_t offset;
 uint8_t old;
 uint8_t new;
} Entry;

int main() {
//f_one size == f_two size
//open...

ssize_t readSize;
uint8_t byteOne;
while((readSize = read(f_one, &byteOne, 1))){
uint8_t byteTwo;
read(f_two, &byteTwo, 1));

if(byteOne != byteTwo){
Entry entry;


}

}

//close..
}


two zero seventeen - SE - three
two zero twenty five -> SE - two

--upr hubenov
01 00 00 00 -> equals one in little-endian

zad 
cp ~rado/Makefile myDir
-we are copying makefile
vim Makefile -> to compile the file
vim main.c

int main(int argc, char*  argv[]){
 if(argc != 4){
errx(1,"Invalid number of args");
}
int fd_one = open(argv[1],O_RDONLY);
if(fd_one == -1){
err(2,"Could not open for reading %s", argv[1]);
}
struct st_
int fd_two = open(argv[2],O_RDONLY);
if(fd_two == -1){
err(2,"Could not open for reading %s", argv[2]);
}
int fd_three = open(argv[3],O_WRONLY | O_CREAT | O_TRUNC, 0600);
if(fd_three == -1){
err(2,"Could not open for reading %s", argv[3]);
}

uint32_t pair[2];
int read_result = 0;
while(read(fd_one, &pair, sizeof(pair)) == sizeof(pair))

if(read_result == -1){
err(2, "Could not read from file")
}
uint32_t buf;


while((read_result = read(fd_one, &pair, sizeof(pair)) ==  sizeof(pair)){
->SEEK_SET -> from where to start reading, writing
if(lseek(fd_two, pair[0]*sizeof(pair[0]), SEEK_SET) == -1){
 err(3, "Could not read from file")
}
for(i = 0;i< pair[1];i++){
read
}
}

0600 in the open section-> permissions of the owner, group, others
the zero means octal 

return 0;


}
