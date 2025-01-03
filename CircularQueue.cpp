#include <iostream>
#define MAX 5

struct CircularQueue {
    int FRONT;
    int REAR;
    int DATA[MAX];
};

typedef struct CircularQueue CQ;  // Alias for CircularQueue

void enqueue(CQ* Q, int element) {
    // Check if the queue is full
    if ((Q->REAR + 1) % MAX == Q->FRONT) {
        std::cout << "Queue is full\n";
    } else {
        Q->DATA[Q->REAR] = element;
        Q->REAR = (Q->REAR + 1) % MAX;
        std::cout << element << " is enqueued\n";
    }
}

int dequeue(CQ* Q) {
    int element = -1;
    // Check if the queue is empty
    if (Q->FRONT == Q->REAR) {
        std::cout << "Queue is empty.\n";
    } else {
        element = Q->DATA[Q->FRONT];
        Q->FRONT = (Q->FRONT + 1) % MAX;
    }
    return element;
}

int main() {
    int choice, data;

    CQ Q = {0, 0}; // Initialization of FRONT and REAR

    do {
        std::cout << "1. ENQUEUE\n2. DEQUEUE\n3. EXIT\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Element: ";
                std::cin >> data;
                enqueue(&Q, data);
                break;

            case 2:
                data = dequeue(&Q);
                if (data != -1)
                    std::cout << "DEQUEUED element is " << data << "\n";
                break;

            case 3:
                std::cout << "BYE\n";
                break;

            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}
