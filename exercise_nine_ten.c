upr nine
--109
/srv/sample-data/03-c/2025-SE-02

#include <err.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>

typedef struct Node{
uint64_t next;
uint8_t user_data[504];
}

int main(int argc, char* argv[]){
if(argc != 2){
errx(1, "Error");
}

int fd = open(argv[1], O_RDWR);
if(fd == -1){
err(2, "%s", argv[1]);
}
//check if the file size can be divided on 512
//we can create an array with Booleans if it is visited then we set it to true
//Node* node
//while(node){
//visited[node.next] = true;
//node = node.next;
//}
//for(int i = 0;i < file.size/struct_size;i++){
//if(!visited[i]){
//structsize * 0
//}
//make temp file -> mkstemp
char tempname[] ="./tempXXXX";
int temp = mkstemp(tempname);

uint64_t nodeIndex = 0;
do {
lseek(temp, nodeIndex, SEEK_SET);
bool found = true;
write(temp, found, 1);
Node node;
lseek(fd, nodeIndex * sizeof(Node), SEEK_SET);
read(fd, &node, sizeof(Node))
nodeIdx = node.next;
}
while(nodeIdx != 0);

ssize_t readSize;
bool found;

uint64_t idx = 0;
uint8_t zeros[sizeof(Node)];
while(readSize = read(temp, &found, 1) > 0){
if(!found){
lseek(fd, idx *sizeof(Node), SEEK_SET);
write(fd, zeros, sizeof(Node));
}
}
close(fd);
return 0;
}

zero is the most left bit
nibble - half byte
to get two sequent bytes we get | with three cause it is like 11 -> 3
(num >> 1) & 0b11
num = num | 0b1000 -> or (3 << 1)
~(3 << 1) -> when we want to convert the mask or we want to set the bit to zero

--
#include <err.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <string.h>


int main(int argc, char* argv[]){
if(argc != 4){
errx(1, "Error");
}

int index = open(argv[1], O_RDWR);
if(index == -1){
err(2, "%s", argv[1]);
}

int values = open(argv[2], O_RDWR);
if(index == -1){
err(2, "%s", argv[2]);
}
uint8_t byte;
ssize_t readSize;
while(readSize = read(index, &byte, 1) > 0)
uint8_t typebit = byte & (1 << 7);
uint8_t nameSize = byte & ~(1 << 7);
--> we get from zeroth to the sixth bit
char name[555];
name[nameSize] = '\0'; -> always put terminating zero
read(index, name, nameSize);
if(strcmp(argv[3], name) == 0){
lseek(values, index*4, SEEK_SET);
break;
//if
}
close(index);
close(values);
char name[UINT8_MAX + 1];

close(fd);
return 0;
}

--while read byte
    for bit in byte
uint8_t bit = byte & (1 << i);
--sto i edna i zad sto
i sto i dvanajset
nine nine

-exec{list, vector, path, environment}
-execl(path, arg_one, arg_two,...)
-execv(path, arg_one, argv[]) - gets the parameters in an array
-processes
 -> exec -> runs another subprogram in the program

fork -> creates a copy of the process that we have called fork with / PC -> program counter
context switching -> when we execute another thread/process/ and stop the first one
int pid = fork
if pid == -1

--upr ten
upr ten
pid - positive -> means it's the parent
int main(void){
for(int i = 0; i< N;i++){
int pid = fork(); -> creates subprocess/ child process
} -> fork cycle
}
N is two
first we create process two on zeroth iteration
then we create a child to two and and one so we get three and four child on the first iteration
so fork copies the current processes so it will be two power by N - 2^N

so if N is three - we get three processes for the first process
      [one]
      / | \
  [two] [three] [four]
   /\       \
[five][six] [eight] 
  /
[seven]

exit - the program stops running
if we write exit after we call the child process then the childs wont fork
new childs and we will have a tree with [one] -> [two] [three] [four]

Pipes
pipes - used for communication between processes 
int main(void){
int pfd[2];
if(pipe(pfd) == -1){err(1, "pipe")...};
//pfd[0] -> reads stdin 
//pfd[1] -> writes stdout 
int pid = fork();
if(pid == 0){
doWork(0);
exit(0);
//child
}
close(pfd[0]);
write(pfd[1], argv[1], strlen(argv[1]));
close(pfd[1]);
wait(NULL);
}
//parent

SIGPIPE - read ends are closed and we cannot write
slow command | head -n 5

--zad sto-dvajset-chetiri

prints DING [parent]
prints DONG [child]
P      C
print  wait
signal print
parent prints before child -> it signals to the child when printed
pipes -> unidirectional
atoi function  -> from string to integer


void doParent[int fromChild]{

for ...N{
write[1, "DING ", 5]
write[toChild, buf, 1]
}

void doChild[int fromParent, int toParent]{
if[WIFEXITED]

wait[D]
}

int main.....
int N = atoi(argv[0]);
int D = atoi(argv[1]);

int parentToChild[2];
//creates a pipe with two integers -> end and start
if(pipe(parentToChild) == -1){
error..
}

int childToParent[2];
//creates a pipe with two integers -> end and start
if(pipe(childToParent) == -1){
error..
}


--zad -onehundred-twenty-six
void processFile{

int pfd[two]
int pd = fork[];
if[pid == zero]{
close[pfd[zero]];
dup[one, pfd[one]]
execl["usr/bin/md5sum", "md5sum", file, NULL];
err[1, "exec"];
close[pfd[one]];
//for conhurrency
int pid = fork[];
if[pid == zero]{
processFile[];
exit[]
}
}

}
fork -> exec
if the parent process is killed then the new parent
of the child process will be the init process - 1
