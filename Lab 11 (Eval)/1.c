// 1) Given a queue of integers, Reverse the q without using any other data structures.

#include <stdio.h>

#define SIZE 100

int q[SIZE];
int front = -1, rear = -1;

void enq(int data) {
    if (rear == SIZE - 1) return;  // Full q

    if (front == -1) front = 0;
    q[++rear] = data;
}

int deq() {
    if (front == -1 || front > rear) return -1;  // Empty q

    int x = q[front++];
    if (front > rear) front = rear = -1;  // Reset if last element removed
    return x;
}

void rev_q() {
    int data = deq();
    if (data == -1) return;

    rev_q();
    enq(data);
}

void disp() {
    if (front == -1) return;

    for (int i = front; i <= rear; i++) {
        printf("%d ", q[i]);
    }
}

int main() {
    int t, data;

    printf("Enter number of elements: ");
    scanf("%d", &t);

    printf("Enter elements: ");
    for (int i = 0; i < t; i++) {
        scanf("%d", &data);
        enq(data);
    }

    printf("Before Reversing: ");
    disp();

    rev_q();

    printf("\nAfter Reversing: ");
    disp();

    return 0;
}

/*
Output:
Enter number of elements: 7
Enter elements: 2 5 6 7 4 3 9  
Before Reversing: 2 5 6 7 4 3 9 
After Reversing: 9 3 4 7 6 5 2
*/