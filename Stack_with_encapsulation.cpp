#include <stdio.h>
#include <stdlib.h>

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

int main(int argc, char const *argv[])
{
    Stack s1;
    init(&s1);
    push(&s1, 1);
    push(&s1, 2);
    push(&s1, 3);

    while (!isEmpty(&s1))
    {
        int value = pop(&s1);
        printf("%d ", value);
    }
    return 0;
}
