#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    Node *prev;
    Node *next;
} Node;

Node *head = NULL, *tail = NULL;

Node *createNewNode(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = new_node->prev = NULL;
    return new_node;
}

void pushTail(int value)
{
    Node *new_node = createNewNode(value);
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = new_node;
        new_node->prev = curr;
    }
    tail = new_node;
}

void pushHead(int value)
{
    Node *new_node = createNewNode(value);
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

void pushMid(int value)
{
    Node *new_node = createNewNode(value);

    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else if (head->next == NULL)
    {
        head->next = new_node;
        new_node->prev = head;
        tail = new_node;
    }
    else
    {
        int len = 0;
        Node *curr = head;
        while (curr != NULL)
        {
            len++;
            curr = curr->next;
        }
        curr = head;
        int mid = len / 2;
        for (int i = 0; i < mid - 1; i++)
        {
            curr = curr->next;
        }
        new_node->next = curr->next;
        curr->next->prev = new_node;
        new_node->prev = curr;
        curr->next = new_node;
    }
}

void viewAll()
{
    Node *curr = head;
    while (curr != NULL)
    {
        printf("[%d]->", curr->value);
        curr = curr->next;
    }
}
void popHead()
{
    Node *del = head;
    head = head->next;
    head->prev = NULL;
    free(del);
}
void popTail()
{
    Node *del = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(del);
}

void freeList()
{
    if (head == tail)
    {
        puts("Linked list is empty");
    }
    else
    {
        Node *curr = head;
        while (curr)
        {
            free(curr->prev);
        }
        free(curr);
        head = tail = NULL;
    }
}

int main(int argc, char const *argv[])
{
    pushMid(1);
    pushMid(2);
    pushMid(3);
    pushMid(4);
    pushMid(5);
    // popHead();
    popTail();
    viewAll();
    freeList();
    return 0;
}
