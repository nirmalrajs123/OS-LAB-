#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
void main(){
int pid;
pid=fork();
if(pid<0){
puts("fork failed");
exit(1);
}else if(pid==0){
execlp("/bin/data","data",NULL);
printf("process id of child- %d\n",getpid());
exit(0);
}else{
printf("process id of parent- %d\n",getpid());
wait(NULL);
exit(0);
}
}
