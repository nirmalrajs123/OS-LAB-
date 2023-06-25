#include<stdio.h>
void main (){
int process[10],block[10],flag[10],allocation[10],pno,bno,i,j;
for(i=0;i<10;i++){
allocation[i]=-1;
flag[i]=0;
}
puts("Enter the total size of block");
scanf("%d",&bno);
puts("Enter the size of blocks");
for(i=0;i<bno;i++){
scanf("%d",&block[i]);
}
puts("Enter the total size of process");
scanf("%d",&pno);
puts("Enter the size of process");
for(i=0;i<pno;i++){
scanf("%d",&process[i]);
}
for(i=0;i<pno;i++){
for(j=0;j<bno;j++){
if(block[j]>=process[i]&&flag[j]!=j){
allocation[i]=j;
block[j]=process[i];
flag[j]=j;
break;
}
}
}
printf("Memory management\n");
printf("Process no\tprocess size\tblock no\n");
for(i=0;i<pno;i++){
printf("%d\t\t%d\t\t",i+1,process[i]);
if(allocation[i]!=-1){
printf("%d\n",allocation[i]+1);
}else{
puts("Not allocated");
}
}
}
