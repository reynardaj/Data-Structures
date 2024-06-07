#include <stdio.h>
#include <stdlib.h>

#define MAX_CAPACITY 20
int heap[MAX_CAPACITY];
int size = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void downHeap(int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
    {
        smallest = left;
    }
    if (right < size && heap[right] < heap[smallest])
    {
        smallest = right;
    }

    if (smallest != index)
    {
        swap(&heap[smallest], &heap[index]);
        downHeap(smallest);
    }
}

void upHeap(int index)
{
    // int parent = (index - 1) / 2;
    // while (index != 0 && heap[index] < heap[parent])
    // {
    //     swap(&heap[index], &heap[parent]);
    //     index = parent;
    //     parent = (index - 1) / 2;
    // }

    while (index != 0 && heap[(index - 1) / 2] > heap[index])
    {
        swap(&heap[index], &heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void insert(int key)
{
    if (size == MAX_CAPACITY)
    {
        puts("Heap Overload");
        return;
    }

    int i = size++;
    heap[i] = key;
    upHeap(i);
}

int deleteMin()
{
    if (size == 0)
    {
        puts("Heap is empty");
        return -1;
    }
    if (size == 1)
    {
        size--;
        return heap[0];
    }

    int root = heap[0];
    heap[0] = heap[--size];

    downHeap(0);
    return root;
}

int findMin()
{
    return size == 0 ? -1 : heap[0];
}

void printHeap()
{
    for (int i = 0; i < size; i++)
        printf("%d ", heap[i]);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    insert(34);
    insert(23);
    insert(15);
    insert(45);
    insert(76);
    insert(4);
    insert(8);
    insert(9);
    insert(30);
    insert(55);
    insert(42);

    printf("Heap: ");
    printHeap();

    // printf("Min element: %d\n", findMin());

    deleteMin();
    printf("Heap after deleteMin: ");
    printHeap();
    return 0;
}
