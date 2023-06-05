#include<stdio.h>
#include <stdlib.h>
#include<dirent.h>
struct dirent *dir;
void main(){
char name[100];
DIR *dirv;

puts("Enter the directory");
scanf("%s",name);
if((dirv=opendir(name))==NULL){
puts("Error");
exit(1);
}
while(dir=readdir(dirv)){
printf("%s\n",dir->d_name);
}
  
  #include<stdio.h>
#include<sys/stat.h>
void main(){
struct stat sfile;
stat("a.txt",&sfile);
printf("mode is %d\n",sfile.st_mode);
printf("user id is %d\n",sfile.st_uid);
printf("size is %ld",sfile.st_size);
}
