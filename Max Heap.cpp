#include <stdio.h>

#define MAX_CAPACITY 20
int size = 0;

int heap[MAX_CAPACITY];

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void upHeap(int index)
{
    while (index != 0 && heap[(index - 1) / 2] < heap[index])
    {
        swap(&heap[index], &heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void downHeap(int index)
{
    int largest = index;
    int left = index * 2 + 1;
    int right = index * 2 + 2;

    if (left <= size && heap[left] > heap[largest])
    {
        largest = left;
    }
    if (right <= size && heap[right] > heap[largest])
    {
        largest = right;
    }

    if (index != largest)
    {
        swap(&heap[index], &heap[largest]);
        downHeap(largest);
    }
}

void insert(int key)
{
    if (size == MAX_CAPACITY)
    {
        puts("Heap Overflow");
    }

    int i = size++;
    heap[i] = key;
    upHeap(i);
}

int getMax()
{
    return size ? heap[0] : -1;
}

void deleteMax()
{
    if (!size)
    {
        return;
    }

    if (size == 1)
    {
        size--;
        return;
    }

    heap[0] = heap[size - 1];
    size--;
    downHeap(0);
}

void printHeap()
{
    printf("Heap: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", heap[i]);
    }
    puts("");
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

    printHeap();

    // printf("Max element: %d\n", getMax());

    deleteMax();
    printf("Heap after deleteMax: ");
    printHeap();

    // deleteMax();
    // printf("Heap after deleteMax: ");
    // printHeap();

    // deleteMax();
    // printf("Heap after deleteMax: ");
    // printHeap();
    return 0;
}
