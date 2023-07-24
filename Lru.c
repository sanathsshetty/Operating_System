#include <stdio.h>
#include <limits.h>

int checkhit(int incomingPage, int queue[], int occupied) {
    for (int i = 0; i < occupied; i++) {
        if (incomingPage == queue[i])
            return 1;
    }
    return 0; 
}

void printFrame(int queue[], int occupied) {
    for (int i = 0; i < occupied; i++) {
        printf("%d\t\t\t", queue[i]);
    }
}

int main() {
    int incomingStream[] = {1, 3, 0, 3, 5, 6, 3};
    int n = sizeof(incomingStream) / sizeof(incomingStream[0]);
    int frames = 3;
    int queue[frames]; 
    int occupied = 0; 
    int pagefault = 0;
    printf("Page\tFrame1\tFrame2\tFrame3\n");
    for (int i = 0; i < n; i++) {
        printf("%d:\t\t", incomingStream[i]);
        if (checkhit(incomingStream[i], queue, occupied)) {
            printFrame(queue, occupied);
        } else if (occupied < frames) {
            queue[occupied] = incomingStream[i];
            occupied++; 
            pagefault++;
            printFrame(queue, occupied); 
        } else {
            
            int j;
            for (j = 0; j < occupied - 1; j++) {
                queue[j] = queue[j + 1];
            }
            queue[j] = incomingStream[i];
            pagefault++;
            printFrame(queue, occupied);
        }
        printf("\n");
    }
    printf("Total Page Faults: %d\n", pagefault);
    return 0;
}
/*Page    Frame1  Frame2  Frame3
1:              1
3:              1                       3
0:              1                       3                       0
3:              1                       3                       0
5:              3                       0                       5
6:              0                       5                       6
3:              5                       6                       3
Total Page Faults: 6*/
