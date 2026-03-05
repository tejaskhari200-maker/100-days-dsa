#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

// push into stack
void push(char x)
{
    stack[++top] = x;
}

// pop from stack
char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

// check precedence
int precedence(char x)
{
    if(x == '+' || x == '-')
        return 1;

    if(x == '*' || x == '/')
        return 2;

    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i = 0, j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while(infix[i] != '\0')
    {
        // if operand, add to postfix
        if(isalnum(infix[i]))
        {
            postfix[j++] = infix[i];
        }

        // if operator
        else
        {
            while(top != -1 && precedence(stack[top]) >= precedence(infix[i]))
            {
                postfix[j++] = pop();
            }

            push(infix[i]);
        }

        i++;
    }

    // pop remaining operators
    while(top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix expression: %s", postfix);

    return 0;
}