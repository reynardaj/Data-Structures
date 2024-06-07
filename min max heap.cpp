#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

// Max heap
int heap[SIZE] = {0};

int leftChild(int i)
{
    return i * 2 + 1;
}

int rightChild(int i)
{
    return i * 2 + 2;
}

int parent(int i)
{
    return i / 2;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify()
{
}

void insert(int value)
{
}

int removeMax()
{
}

int getMax()
{
}

int main(int argc, char const *argv[])
{

    return 0;
}
