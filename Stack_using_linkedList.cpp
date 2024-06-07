#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    Node *next;
} Node;

Node *top = NULL;

Node *create_new_node(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void push(int x)
{
    Node *new_node = create_new_node(x);
    if (top == NULL)
    {
        top = new_node;
    }
    else
    {
        Node *current = top;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

void pop()
{
    if (top == NULL)
    {
        puts("Stack is empty!");
        return;
    }
    else
    {
        Node *current = top;
        Node *del = current;

        while (current->next != NULL)
        {
            del = current;
            current = current->next;
        }
    }
}

int main(int argc, char const *argv[])
{

    return 0;
}
