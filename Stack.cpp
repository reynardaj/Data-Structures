#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int value;
    struct Node *next, *prev;
} Node;

Node *head, *tail;

Node *create_new_node(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = new_node->prev = NULL;
    return new_node;
}

void push(int value)
{
    Node *new_node = create_new_node(value);
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
    }
}

void pop()
{
    if (head == NULL)
    {
        puts("Stack underflow");
        return;
    }
    else
    {
        Node *del = head;
        head = head->next;
        head->prev = NULL;
        free(del);
        if (head == NULL)
        {
            tail = NULL;
        }
    }
}

void display()
{
    Node *current = tail;
    if (current == NULL)
    {
        puts("Stack is empty");
    }
    else
    {
        puts("Top");
        while (current != NULL)
        {
            printf("%d\n", current->value);
            current = current->prev;
        }
        puts("Bottom");
    }
}

int main(int argc, char const *argv[])
{
    push(10);
    push(20);
    push(30);
    push(40);
    display();
    puts("op1");
    pop();
    display();
    return 0;
}
