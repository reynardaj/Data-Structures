#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Stack implementation and associated function
typedef struct Node
{
    char data[50];
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

char *getTop(Stack *s)
{
    return s->top->data;
}

void push(Stack *s, char value[])
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    // malloc error handling
    if (!newNode)
    {
        puts("Memory allocation failed");
        return;
    }

    strcpy(newNode->data, value);
    newNode->next = s->top;
    s->top = newNode;
}

char *pop(Stack *s)
{
    if (isEmpty(s))
    {
        puts("Stack is empty");
        return NULL;
    }

    Node *del = s->top;
    char *temp;
    temp = del->data;
    s->top = s->top->next;
    free(del);
    return temp;
}

// Evaluate expressions related functions

int isNumber(char *str)
{
    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
    }
    return 1;
}
int getPrecedence(char *op)
{
    switch (op[0])
    {
    case '-':
        return 1;
    case '+':
        return 1;
    case '/':
        return 2;
    case '*':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}

int main(int argc, char const *argv[])
{
    Stack s1;
    init(&s1);
    char expression[] = "1";
    char *token;
    char *delim = " ";
    token = strtok(expression, delim);

    char output[100] = {0};

    while (token)
    {
        if (isNumber(token) || strcmp(token, ")") == 0)
        {
            push(&s1, token);
        }
        else if (getPrecedence(token) > getPrecedence(getTop(&s1)))
        {
            push(&s1, token);
        }
        else if (strcmp(token, ")") == 0)
        {
            char *temp;
            while (temp[0] != '(')
            {
                temp = pop(&s1);
                strcat(output, temp);
            }
            pop(&s1);
        }
        else
        {
            while (getPrecedence(token) <= getPrecedence(getTop(&s1)))
            {
                strcat(output, pop(&s1));
            }
            push(&s1, token);
        }
        token = strtok(NULL, delim);
    }
    // while (!isEmpty(&s1))
    // {
    //     // printf("%s ", pop(&s1));
    //     strcat(output, pop(&s1));
    //     strcat(output, " ");
    // }
    // strcat(output, "\0");
    // printf("%s\n", output);
}
