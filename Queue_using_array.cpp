#include <stdio.h>

#define MAX 10

int queue[MAX];

void push(int x, int *rear)
{
    if (*rear < MAX)
    {
        queue[++(*rear)] = x;
    }
    else
    {
        puts("queue overflow");
    }
}

void pop(int *front, int rear)
{
    if (*front < rear)
        (*front)++;
    else
        puts("Queue is empty");
}

void front(int front, int rear)
{
    if (front == rear == 0)
    {
        puts("Queue is empty");
    }
    else
    {
        printf("%d\n", queue[front]);
    }
}

int main(int argc, char const *argv[])
{
    int frontNum, rearNum;
    frontNum = -1;
    rearNum = 0;

    push(1, &rearNum);
    front(frontNum, rearNum);
    return 0;
}
