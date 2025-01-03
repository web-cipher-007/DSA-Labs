/*Implementation of Circular Queue in C*/

#include <stdio.h>
#define MAX 5

struct CircularQueue {
    int FRONT;
    int REAR;
    int DATA[MAX];
};

typedef struct CircularQueue CQ; 

void enqueue(CQ *Q, int element) {
    if ((Q->REAR + 1) % MAX == Q->FRONT) {
        printf("Queue is full.\n");
    } else {
        Q->DATA[Q->REAR] = element;
        Q->REAR = (Q->REAR + 1) % MAX;
        printf("%d is enqueued.\n", element);
    }
}

int dequeue(CQ *Q) {
    int element = -1;
    if (Q->FRONT == Q->REAR) {
        printf("Queue is empty.\n");
    } else {
        element = Q->DATA[Q->FRONT];
        Q->FRONT = (Q->FRONT + 1) % MAX;
    }
    return element;
}

int main() {
    int choice, data;
    CQ Q = {0, 0};  // front and back initialize to zero

    do {
        printf("1. ENQUEUE\n2. DEQUEUE\n3. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter the element: ");
                scanf("%d", &data);
                enqueue(&Q, data);
                break;

            case 2:
                data = dequeue(&Q);
                if (data != -1) {
                    printf("Dequeued element is %d\n", data);
                }
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
