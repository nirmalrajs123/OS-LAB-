#include<sys/ipc.h>
#include<sys/shm.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main(){
void *shared_memory;
char buffer[100];
int shmid;
shmid=shmget((key_t)1222,1024,0666|IPC_CREAT);
printf("shared memory key %d\n",shmid);
shared_memory=shmat(shmid,NULL,0);
puts("Enter the data to shared");
read(0,buffer,100);
strcpy(shared_memory,buffer);
printf("process attached at shared memory %p\n",shared_memory);
printf("data written in shared memory by sender:%s",(char *)shared_memory);
}
