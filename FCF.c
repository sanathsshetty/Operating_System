#include <stdio.h>

int main() {
    char pn[10];
    int arr[10], bur[10], star[10], finish[10], tat[10], wt[10], i, n;
    int totwt = 0, tottat = 0;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the Process Name, Arrival Time & Burst Time: ");
        scanf("%s%d%d", pn[i], &arr[i], &bur[i]);
    }

    for (i = 0; i < n; i++) {
        if (i == 0) {
            star[i] = arr[i];
            wt[i] = star[i] - arr[i];
            finish[i] = star[i] + bur[i];
            tat[i] = finish[i] - arr[i];
        } else {
            star[i] = finish[i - 1];
            wt[i] = star[i] - arr[i];
            finish[i] = star[i] + bur[i];
            tat[i] = finish[i] - arr[i];
        }
    }

    printf("\nPName\tArrtime\tBurtime\tStart\tTAT\tFinish\n");
    for (i = 0; i < n; i++) {
        printf("%s\t%6d\t%6d\t%6d\t%6d\t%6d\n", pn[i], arr[i], bur[i], star[i], tat[i], finish[i]);
        totwt += wt[i];
        tottat += tat[i];
    }

    printf("\nAverage Waiting time: %f", (float)totwt / n);
    printf("\nAverage Turn Around Time: %f", (float)tottat / n);

    return 0;
}
