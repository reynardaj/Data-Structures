#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int value;
    Node *next;
} Node;

Node *head;

Node *create_new_node(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void push(int value)
{
    Node *new_node = create_new_node(value);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
}

void pop()
{
    if (head == NULL)
    {
        puts("Stack underflow");
    }
    else
    {
        Node *del = head;
        head = head->next;
        free(del);
    }
}
void display()
{
    if (head != NULL)
    {
        Node *current = head;
        while (current != NULL)
        {
            printf("%d\n", current->value);
            current = current->next;
        }
    }
    else
    {
        puts("Stack is empty");
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
    pop();
    pop();
    pop();
    pop();
    display();
    return 0;
}
