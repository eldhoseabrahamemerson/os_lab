#include <stdio.h>

int main() {
    int n;
    int pid[20], at[20], bt[20], ct[20], tat[20], wt[20];
    float avg_wt = 0, avg_tat = 0, total_tat=0, total_wt=0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("Enter Arrival Time and Burst Time for P%d: ", pid[i]);
        scanf("%d %d", &at[i], &bt[i]);
    }

    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(at[i] > at[j]) {
                // swap arrival time
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                // swap burst time
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                // swap process id
                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    // Calculate Completion Time
    ct[0] = at[0] + bt[0];
    for(int i = 1; i < n; i++) {
        if(ct[i-1] < at[i]){
            ct[i] = at[i] + bt[i];
        }
        else{
            ct[i] = ct[i-1] + bt[i];
        }
    }

    // Calculate TAT and WT
    for(int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        total_wt += wt[i];
        total_tat += tat[i];
    }

    avg_wt = total_wt/n;
    avg_tat = total_tat/n;

    // Display Table
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    // Display Averages
    printf("\nAverage Waiting Time = %.2f", avg_wt);
    printf("\nAverage Turnaround Time = %.2f\n", avg_tat);

    // Gantt Chart
    printf("\nGantt Chart:\n|");
    for(int i = 0; i < n; i++) {
        printf(" P%d |", pid[i]);
    }

    printf("\n%d", at[0]);
    for(int i = 0; i < n; i++) {
        printf("   %d", ct[i]);
    }

    return 0;
}
