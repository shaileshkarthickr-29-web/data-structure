#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char c) {
    if (top >= MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (top < 0) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

int isBalanced(char *expr) {
    int i;
    int len = strlen(expr);
    
    for (i = 0; i < len; i++) {
        char ch = expr[i];
        
        if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            if (isEmpty()) {
                return 0;  
            }
            pop();
        }
        
    }
    
    return isEmpty(); 
    
}

int main() {
    char expr[100];
    
    printf("Enter an expression: ");
    scanf("%s", expr);
    
    if (isBalanced(expr)) {
        printf("Balanced Expression\n");
    } else {
        printf("Not Balanced\n");
    }
    
    return 0;
}