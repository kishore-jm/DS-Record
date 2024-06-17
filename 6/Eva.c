#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 100

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else
        return 0;
}

void infixToPostfix(char *infix, char *postfix) {
    int i = 0, j = 0;
    char stack[MAX_SIZE];
    int top = -1;

    while (infix[i] != '\0') {
        if (isalnum(infix[i]))
            postfix[j++] = infix[i++];
        else if (infix[i] == '(')
            stack[++top] = infix[i++];
        else if (infix[i] == ')') {
            while (stack[top] != '(')
                postfix[j++] = stack[top--];
            top--;
            i++;
        } else if (isOperator(infix[i])) {
            while (top != -1 && precedence(stack[top]) >= precedence(infix[i]))
                postfix[j++] = stack[top--];
            stack[++top] = infix[i++];
        }
    }

    while (top != -1)
        postfix[j++] = stack[top--];

    postfix[j] = '\0';
}
void evaluate(char *postfix) {
    int top = -1, i = 0;
    int stack[MAX_SIZE];

    while (postfix[i] != '\0') {
        if (isdigit(postfix[i])) {
            stack[++top] = postfix[i] - '0'; // Convert char to int
        } else if (isOperator(postfix[i])) {
            int operand2 = stack[top--];
            int operand1 = stack[top--];
            
            switch (postfix[i]) {
                case '+':
                    stack[++top] = operand1 + operand2;
                    break;
                case '-':
                    stack[++top] = operand1 - operand2;
                    break;
                case '*':
                    stack[++top] = operand1 * operand2;
                    break;
                case '/':
                    stack[++top] = operand1 / operand2;
                    break;
            }
        }
        i++;
    }

    printf("Result of evaluation: %d\n", stack[top]);
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);
    evaluate(postfix);
    return 0;
}
output:
Enter infix expression: (3+4)*5-6/2
Postfix expression: 34+5*62/-
Result of evaluation: 29
