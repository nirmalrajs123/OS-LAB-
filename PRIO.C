#include<stdio.h>
#include<stdlib.h>
struct sjf{
int pid;
int bt;
int at;
int ct;
int tat;
int wt;
int pt;
}p[10];
void main(){
struct sjf temp;
int n,i,j,s;
double total_tat=0,total_wt=0;
puts("Enter the details of processes for sjf");
puts("Enter the no of processes");
scanf("%d",&n);
for(i=0;i<n;i++){
puts("Enter the processes no :");
scanf("%d",&p[i].pid);
puts("Enter the burst time of processes :");
scanf("%d",&p[i].bt);
puts("Enter the arival time of processes :");
scanf("%d",&p[i].at);
puts("Enter the priority of processes :");
scanf("%d",&p[i].pt);
}
p[0].ct=p[0].bt;
p[0].tat=p[0].ct-p[0].at;
p[0].wt=p[0].tat-p[0].bt;
for(i=1;i<n-1;i++){
for(j=i+1;j<n;j++){
if(p[i].pt>p[j].pt){
temp=p[i];
p[i]=p[j];
p[j]=temp;
}
}
}
for(i=1;i<n;i++){
p[i].ct=p[i-1].ct+p[i].bt;
p[i].tat=p[i].ct-p[i].at;
p[i].wt=p[i].tat-p[i].bt;
}
puts("--------------------------------");
puts("p id |bt  |at  |pt  |ct  |tat  |wt  |");
puts("--------------------------------");
for(i=0;i<n;i++){
total_tat=total_tat+p[i].tat;
total_wt=total_wt+p[i].wt;
printf("P%d   |%d |%d   |%d   |%d   |%d   |%d |\n",p[i].pid,p[i].bt,p[i].at,p[i].pt,p[i].ct,p[i].tat,p[i].wt);
}
puts("--------------------------------\n");
printf("Total turn around time : %f\n",total_tat/n);
printf("Total waiting time : %f",total_wt/n);
}
