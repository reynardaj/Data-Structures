#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    Node *next;
} Node;

Node *head;

Node *createNewNode(int value)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}

void pushTail(int value)
{
    if (head == NULL)
    {
        Node *new_node = createNewNode(value);
        head = new_node;
    }
    else
    {
        Node *new_node = createNewNode(value);
        Node *curr = head;
        while (curr->next != NULL)
        {
            curr = curr->next;
        }
        curr->next = new_node;
    }
}

void pushHead(int value)
{
    if (head == NULL)
    {
        Node *new_node = createNewNode(value);
        head = new_node;
    }
    else
    {
        Node *new_node = createNewNode(value);
        new_node->next = head;
        head = new_node;
    }
}

void pushMid(int value)
{
    if (head == NULL)
    {
        head = createNewNode(value);
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
        int count = len % 2 == 0 ? len / 2 : (len - 1) / 2;
        curr = head;
        for (int i = 0; i < count - 1; i++)
        {
            curr = curr->next;
        }
        Node *new_node = createNewNode(value);
        new_node->next = curr->next;
        curr->next = new_node;
    }
}

void deleteNode(int value)
{
    Node *curr = head;
    if (head->value == value)
    {
        head = head->next;
        free(curr);
    }
    else
    {
        while (curr->next->value != value)
        {
            curr = curr->next;
        }
        Node *del = curr->next;
        curr->next = del->next;
        free(del);
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
    if (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }
}

Node *search(int key)
{
    Node *curr = head;
    if (head == NULL)
    {
        return NULL;
    }

    while (curr != NULL)
    {
        curr = curr->next;
        if (curr->value == key)
        {
            return curr;
        }
    }
    return NULL;
}

int main(int argc, char const *argv[])
{
    pushTail(1);
    pushTail(2);
    pushTail(3);
    pushTail(4);
    pushTail(4);
    pushTail(5);

    // pushHead(0);
    // pushHead(-1);
    // pushHead(-2);
    // pushHead(-3);
    deleteNode(4);
    // pushMid(100);
    Node *found = search(3);
    puts("");
    printf("%d\n", found->value);
    viewAll();
    return 0;
}
