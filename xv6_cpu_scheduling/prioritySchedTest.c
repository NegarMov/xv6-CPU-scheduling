#include "types.h"
#include "stat.h"
#include "user.h"


#define CHILDREN 30
#define LIMIT 250

int main() {
    changePolicy(1);
    
   
    for(int n = 0; n < CHILDREN; n++){
      int pid = fork();
      if(pid < 0)
        break;

      if(pid == 0){
     
        if(n < 5){
            setPriority(6, pid);
        }
        else if(n >= 5 && n < 10){
            setPriority(5, pid);
        }
        else if(n >= 10 && n < 15){
            setPriority(4, pid);
        }
        else if(n >= 15 && n < 20){
            setPriority(3, pid);
        }
        else if(n >= 20 && n < 25){
            setPriority(2, pid);
        }
        else if(n >= 25 && n < 30){
            setPriority(1, pid);
        }
        for(int i=1 ; i<=250 ; i++){
            printf(1, "/%d/ : /%d/\n", pid, i);
        }
         
        exit();
      }
    }

    int TATSum[7];
    int WTSum[7];
    int CBTSum[7];

    //TAT = turnaround time
    //WT = waiting time
    //CBT = cpu burst time

    for (int i = 0; i < CHILDREN; i++) {
        int ctime;
        int ttime;
        int rntime;
        int rdtime;
        int priority;

       
        int pid = waitWithStatus(&ctime, &ttime, &rntime, &rdtime, &priority);

        
        int TAT = ttime - ctime;
        int WT  = rdtime;
        int CBT = rntime;
        //int ST  = stime;


        TATSum[priority]+= TAT;
        WTSum[priority]+= WT;
        CBTSum[priority]+= CBT;


        printf(1, "> pid: %d\n", pid);
        printf(1, "  creation time = %d - ", ctime);
        printf(1, "termination time = %d - ", ttime);
        printf(1, "turnaround time = %d - ", TAT);
        printf(1, "waiting time = %d - ", WT);
        printf(1, "CPU burst = %d", CBT);
        //printf(1, "sleeping time = %d - ", ST);
        printf(1,"\n\n");
    }


    int someOfAllTAT = 0;
    int sumOfAllWT = 0;
    int sumOfAllCBT = 0;

    for (int i = 1; i < 7; i++)
    {
        someOfAllTAT += TATSum[i];
        sumOfAllWT += WTSum[i];
        sumOfAllCBT += CBTSum[i];

        printf(1, "\n\n> Priority = %d -> average turnaround time: %d\n",i, TATSum[i] / 6);
        printf(1, "> Priority = %d -> average waiting time: %d\n", i, WTSum[i] / 6);
        printf(1, "> Priority = %d -> average CPU burst time: %d\n",i , CBTSum[i] / 6);
    }

        printf(1, "\n***********************************************************");
        printf(1, "\n>average turnaround time of all process: %d\n",someOfAllTAT /CHILDREN);
        printf(1, ">average waiting time of all process: %d\n", sumOfAllWT /CHILDREN);
        printf(1, ">average CPU burst time of all process: %d\n",sumOfAllCBT/CHILDREN );

   

    exit();
}




