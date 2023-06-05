#include<stdio.h>
#include<stdlib.h>
struct fcfs{
int pid;
int bt;
int at;
int ct;
int tat;
int wt;
}p[10];
void main(){
int n,i,s;
double total_tat=0,total_wt=0;
puts("Enter the details of processes for fcfs");
puts("Enter the no of processes");
scanf("%d",&n);
for(i=0;i<n;i++){
puts("Enter the processes no :");
scanf("%d",&p[i].pid);
puts("Enter the burst time of processes :");
scanf("%d",&p[i].bt);
puts("Enter the arival time of processes :");
scanf("%d",&p[i].at);
p[i].ct=p[i-1].ct+p[i].bt;
p[i].tat=p[i].ct-p[i].at;
total_tat=total_tat+p[i].tat;
p[i].wt=p[i].tat-p[i].bt;
total_wt=total_wt+p[i].wt;
}
puts("--------------------------------");
puts("p id |bt  |at  |ct  |tat  |wt  |");
puts("--------------------------------");
for(i=0;i<n;i++){
printf("P%d   |%d |%d   |%d   |%d   |%d |\n",p[i].pid,p[i].bt,p[i].at,p[i].ct,p[i].tat,p[i].wt);
}
puts("--------------------------------\n");
printf("Total turn around time : %f\n",total_tat/n);
printf("Total waiting time : %f",total_wt/n);
}
