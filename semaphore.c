#include <stdio.h>
#include <stdlib.h>

int mutex = 1, full = 0, empty = 3, x = 0;

int wait(int);
int signal(int);
void producer();
void consumer();

int main() {
    int n;

    printf("1. Producer\n2. Consumer\n3. Exit\n");
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                if (mutex == 1 && empty != 0)
                    producer();
                else
                    printf("Buffer is full!\n");
                break;
            case 2:
                if (mutex == 1 && full != 0)
                    consumer();
                else
                    printf("Buffer is empty!\n");
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

int wait(int s) {
    return (--s);
}

int signal(int s) {
    return (++s);
}

void producer() {
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\nProducer produces item %d\n", x);
    mutex = signal(mutex);
}

void consumer() {
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumer consumes item %d\n", x);
    x--;
    mutex = signal(mutex);
}
// 1. Producer
// 2. Consumer
// 3. Exit

// Enter your choice: 1

// Producer produces item 1

// Enter your choice: 1

// Producer produces item 2

// Enter your choice: 1

// Producer produces item 3

// Enter your choice: 1
// Buffer is full!

// Enter your choice: 2

// Consumer consumes item 3

// Enter your choice: 2

// Consumer consumes item 2

// Enter your choice: 2

// Consumer consumes item 1

// Enter your choice: 2
// Buffer is empty!

// Enter your choice: 3
// [1] + Done         
