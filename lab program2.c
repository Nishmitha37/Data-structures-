#include <stdio.h>
#include <ctype.h>

void push(char stack[], int top, char ele) {
    stack[++top] = ele;
}

char pop(char stack[], int top) {
    return stack[top--];
}

int pr(char op) {
    switch (op) {
        case '#': return 0;
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 3;
        default: return 0;
    }
}

int main() {
    char infix[100], stack[100], postfix[100];
    int top = -1;  // Initialize top
    int i = 0, j = 0;
    char ch;

    printf("Enter your infix expression: ");
    scanf("%s", infix);

    stack[++top] = '#';  // Initialize stack with '#'

    while (infix[i] != '\0') {
        if (isalpha(infix[i])) {
            // If operand, add to postfix expression
            postfix[j++] = infix[i];
        } else if (infix[i] == '(') {
            stack[++top] = infix[i];
        } else if (infix[i] == ')') {
            // Pop and add to postfix until '(' is found
            while (stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            top--;  // Remove '(' from stack
        } else {
            // Operator encountered
            while (pr(infix[i]) <= pr(stack[top]) && stack[top] != '#') {
                postfix[j++] = stack[top--];
            }
            stack[++top] = infix[i];
        }
        i++;
    }

    // Pop remaining operators from the stack
    while (stack[top] != '#') {
        if (stack[top] == '(') {
            printf("\nThere was an issue with the expression...\n");
            return 1;  // Exit if unmatched '(' is found
        }
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0';  // Null-terminate the postfix expression

    printf("Postfix expression: %s\n", postfix);
    return 0;
    
}
 
