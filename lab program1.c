#include <stdio.h>
#include <stdlib.h>

int main() {
    int size;

    printf("Enter the size of the stack: ");
    scanf("%d", &size);

    int stack[size]; // Initialize the stack after getting the size
    int top = -1;

    // Function prototypes
    void push(int stack[], int *top, int size, int value);
    int pop(int stack[], int *top);
    void display(int stack[], int top);

    while (1) {
        int choice, value;
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(stack, &top, size, value);
                break;
            case 2:
                value = pop(stack, &top);
                if (value != -1) {
                    printf("Popped %d from the stack.\n", value);
                }
                break;
            case 3:
                display(stack, top);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0; // Return statement for main
}

void push(int stack[], int *top, int size, int value) {
    if (*top >= size - 1) {
        printf("Stack Overflow: Cannot push %d. The stack is full.\n", value);
    } else {
        (*top)++;
        stack[*top] = value;
        printf("Pushed %d onto the stack.\n", value);
    }
}

int pop(int stack[], int *top) {
    if (*top == -1) {
        printf("Stack Underflow: Cannot pop. The stack is empty.\n");
        return -1;
    } else {
        return stack[(*top)--];
    }
}

void display(int stack[], int top) {
    if (top == -1) {
        printf("The stack is empty.\n");
    } else {
        printf("Current Stack: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
