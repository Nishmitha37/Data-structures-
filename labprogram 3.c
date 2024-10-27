#include <stdio.h>
#include <stdlib.h>

int main() {
    const int SIZE = 5; // Set the size of the queue
    int arr[SIZE];
    int front = -1;
    int rare = -1;

    void Display(int arr[], int front, int rare) {
        if (front == -1 || front > rare) {
            printf("Queue is Empty\n");
            return;
        }
        printf("Queue elements:\n");
        for (int i = front; i <= rare; i++) {
            printf("%d\n", arr[i]);
        }
    }

    int Dequeue(int arr[], int front, int rare) {
        if (front == -1 || front > rare) {
            printf("Queue underflow\n");
            return -1; // Indicate that the queue is empty
        } else {
            int deletedValue = arr[front];
            printf("Deleted element is: %d\n", deletedValue);
            front++;
            // Reset front and rare if the queue is now empty
            if (front > rare) {
                front = rare = -1;
            }
            return front; // Return the updated front
        }
    }

    int Enqueue(int arr[], int front, int rare, int item) {
        if (rare == (SIZE - 1)) {
            printf("Queue Overflow\n");
            return rare; // Return unchanged rare
        } else {
            arr[++rare] = item; // Insert item at rare and increment rare
            if (front == -1) front = 0; // Set front to 0 if it was -1
            return rare; // Return the updated rare
        }
    }

    int Peek(int arr[], int front) {
        if (front != -1) {
            return arr[front];
        }
        return -1; // Indicate the queue is empty
    }

    while (1) {
        int choice;
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int item;
                printf("Enter the element to be inserted: ");
                scanf("%d", &item);
                rare = Enqueue(arr, front, rare, item);
                if (front == -1) front = 0; // Update front if necessary
                break;
            }
            case 2:
                front = Dequeue(arr, front, rare);
                break;
            case 3:
                Display(arr, front, rare);
                break;
            case 4:
                {
                    int peekValue = Peek(arr, front);
                    if (peekValue != -1) {
                        printf("Peek element: %d\n", peekValue);
                    } else {
                        printf("Queue is empty\n");
                    }
                }
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid input\n");
        }
    }

    return 0;
}
