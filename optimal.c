#include<stdio.h>
#include<stdbool.h>

int findIndex(int frames[], int n, int page)
{
    for(int i=0;i<n;i++)
    {
        if(frames[i]==page)
        return i;
    }
    return -1;
}

void printFrame(int frames[], int n)
{
    for (int i=0;i<n;i++)
    {
        if(frames[i]==-1)
        printf(" ");
        else
        printf("\t%d",frames[i]);
    }
    printf("\n");
}

void optimal(int pages[], int n, int capacity){
    int frames[capacity];
    int pageFaults=0;
    int index, farthest, futureIndex;
    for(int i=0;i<capacity;i++)
    frames[i]=-1;
    for(int i=0;i<n;i++)
    {
        int page=pages[i];
        index = findIndex(frames, capacity, page);
        if (index==-1)
        {
            int emptyIndex = findIndex(frames, capacity, -1);
        if (emptyIndex!=-1)
        {
            frames[emptyIndex]=page;
        }
        else
        {
            farthest = i+1;
            futureIndex= -1;
            for(int j=0;j<capacity;j++)
            {
                int currentFrame = frames[j];
                int k;
            for (k=i+1;k<n;k++)
            {
                if(currentFrame==pages[k])
                {
                    if(k>farthest)
                    {
                        farthest=k;
                        futureIndex=j;
                    }
                    break;
                }
            }
            if(k==n)
            {
                futureIndex=j;
                break;
            }
            }
            frames[futureIndex]=page;
            }
            pageFaults++;
        }
        printFrame(frames, capacity);
        }
        printf("Page Faults: %d\n",pageFaults);
    }

int main(){
    int pages[]={1,2,3,4,1,5,6,7,8,7,8,9,7,8,9,5,4,5,4,2};
    int capacity=3;
    int n=sizeof(pages)/sizeof(pages[0]);
printf("Pages reference sequence:\n");
for(int i=0;i<n;i++)
{
    printf("%d ",pages[i]);
}
printf("\n\n");
printf("\n");
printf("Optimal Algortihm:\n");
optimal(pages,n,capacity);
printf("\n");
return 0;
}

/*
Pages reference sequence:
1 2 3 4 1 5 6 7 8 7 8 9 7 8 9 5 4 5 4 2 


Optimal Algortihm:
	1  
	1	2 
	1	2	3
	1	2	4
	1	2	4
	5	2	4
	5	6	4
	5	7	4
	5	7	8
	5	7	8
	5	7	8
	9	7	8
	9	7	8
	9	7	8
	9	7	8
	5	7	8
	5	4	8
	5	4	8
	5	4	8
	2	4	8
Page Faults: 12

*/
