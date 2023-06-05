#include<stdio.h>
#include<stdlib.h>
int flag=0,t,i,n;
struct sjf{
int pid;
int bt;
int at;
int ct;
int tat;
int wt;
int rt;
}p[10];
void main(){
struct sjf temp;
int j,s,y;
double total_tat=0,total_wt=0;
puts("Enter the details of processes for RR");
puts("Enter the no of processes");
scanf("%d",&n);
y=n;
puts("Enter the time silece");
scanf("%d",&t);
for(i=0;i<n;i++){
puts("Enter the processes no :");
scanf("%d",&p[i].pid);
puts("Enter the burst time of processes :");
scanf("%d",&p[i].bt);
puts("Enter the arival time of processes :");
scanf("%d",&p[i].at);
p[i].rt=p[i].bt;
}
int sum;
for(sum=0,i=0;y!=0;){
if(p[i].rt<=t && p[i].rt>0){
sum=sum+p[i].rt;
p[i].ct=sum;
p[i].rt=0;
y--;
}else if(p[i].rt>0){
p[i].rt=p[i].rt-t;
sum=sum+t;
p[i].ct=sum;
}
if(i==n-1){
i=0;
}else if(p[i+1].at<=sum){
i++;
}else{
i=0;
}
}
for(i=0;i<n;i++){
p[i].tat=p[i].ct-p[i].at;
p[i].wt=p[i].tat-p[i].bt;
}
puts("--------------------------------");
puts("p id |bt  |at  |ct  |tat  |wt  |");
puts("--------------------------------");
for(i=0;i<n;i++){
total_tat=total_tat+p[i].tat;
total_wt=total_wt+p[i].wt;
printf("P%d   |%d |%d   |%d   |%d   |%d |\n",p[i].pid,p[i].bt,p[i].at,p[i].ct,p[i].tat,p[i].wt);
}
puts("--------------------------------\n");
printf("Total turn around time : %f\n",total_tat/n);
printf("Total waiting time : %f",total_wt/n);
}
