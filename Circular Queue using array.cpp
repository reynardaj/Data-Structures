#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 3

int queue[MAX_LEN] = {0};

void enqueue(int x, int *rear, int *front)
{
    if (abs(*rear - *front + 1) > MAX_LEN)
    {
        puts("Cannot enqueue, queue is full");
        return;
    }

    *rear = x;
    rear = queue + 1;
}

void view_queue()
{
    for (int i = 0; i < MAX_LEN; i++)
    {
        printf("%d ", queue[i]);
    }
}

int main(int argc, char const *argv[])
{
    int *front = queue;
    int *rear = queue;
    enqueue(1, rear, front);
    printf("%d\n", rear);
    enqueue(2, rear, front);
    printf("%d\n", rear);
    view_queue();
    return 0;
}
