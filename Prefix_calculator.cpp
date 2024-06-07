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

int calculatePrefix(char prefix[])
{
    Stack stack;
    init(&stack);
    char prefixCopy[50];
    strcpy(prefixCopy, prefix);
    strrev(prefixCopy);

    int len = strlen(prefixCopy);
    for (int i = 0; i < len; i++)
    {
        char c = prefixCopy[i];
        if (isOp(c))
        {
            int num1, num2;
            num1 = pop(&stack);
            num2 = pop(&stack);
            push(&stack, operate(c, num1, num2));
        }
        else
        {
            push(&stack, c - '0');
        }
    }
    int result = pop(&stack);
    return result;
}

int calculatePostfix(char postfix[])
{
    Stack stack;
    init(&stack);

    int len = strlen(postfix);
    for (int i = 0; i < len; i++)
    {
        char c = postfix[i];
        if (isOp(c))
        {
            int num1, num2;
            num1 = pop(&stack);
            num2 = pop(&stack);
            push(&stack, operate(c, num1, num2));
        }
        else
        {
            push(&stack, c - '0');
        }
    }
    int result = pop(&stack);
    return result;
}

int main(int argc, char const *argv[])
{
    char prefix[] = "+*314";
    char postfix[] = "31+4*";
    int pre = calculatePrefix(prefix);
    int post = calculatePostfix(postfix);
    printf("pre : %d , post : %d\n", pre, post);
    return 0;
}
