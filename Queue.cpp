#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    Node *next;
} Node;

Node *head;

Node *create_new_node(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->value = value;
    return new_node;
}

void enqueue(int value)
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

void dequeue()
{
    if (head == NULL)
    {
        puts("Queue underflow!");
        return;
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }

    else
    {
        Node *current = head;
        Node *temp = current;
        while (current->next != NULL)
        {
            temp = current;
            current = current->next;
        }
        free(current);
        temp->next = NULL;
    }
}

void display()
{
    if (head == NULL)
    {
        puts("Queue is empty!");
    }
    else
    {
        Node *current = head;
        while (current != NULL)
        {
            printf("%d\n", current->value);
            puts("v");
            current = current->next;
        }
    }
}

int main(int argc, char const *argv[])
{

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    puts("op1");
    dequeue();
    dequeue();
    display();

    return 0;
}
