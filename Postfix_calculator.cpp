#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Stack implementation and associated function
typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;

void init(Stack *s)
{
    s->top = NULL;
}

int isEmpty(Stack *s)
{
    return s->top == NULL;
}

void push(Stack *s, int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    // malloc error handling
    if (!newNode)
    {
        puts("Memory allocation failed");
        return;
    }

    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack *s)
{
    if (isEmpty(s))
    {
        puts("Stack is empty");
        return -1;
    }

    Node *del = s->top;
    int temp = del->data;
    s->top = s->top->next;
    free(del);
    return temp;
}

// Evaluate expressions related functions

int isOp(char eq)
{
    return !isdigit(eq);
}

int operate(char op, int num1, int num2)
{
    switch (op)
    {
    case '-':
        return num2 - num1;
        break;
    case '+':
        return num2 + num1;
        break;
    case '/':
        return num2 / num1;
        break;
    case '*':
        return num2 * num1;
        break;
    default:
        return -1;
        break;
    }
}

int main(int argc, char const *argv[])
{
    char expression[] = "3 1 + 3 * 5 * 10 / 18 -";
    Stack s1;
    init(&s1);
    char *token;
    char *delim = " ";

    token = strtok(expression, delim);

    // calculate expression
    while (token != NULL)
    {
        if (isOp(*token))
        {
            int num1, num2;
            num1 = pop(&s1);
            num2 = pop(&s1);
            push(&s1, operate(*token, num1, num2));
        }
        else
        {
            push(&s1, atoi(token));
        }
        token = strtok(NULL, delim);
    }
    int result = pop(&s1);
    printf("%d\n", result);
    return 0;
}
