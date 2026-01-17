#define _CRT_SECURE_NO_WARNINGS
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#define MAX_SIZE 100
typedef struct {
    int data[MAX_SIZE];
    int front,rear;
} Queue;
void init(Queue* q) {
    q->front = 1;
    q->rear = 0;
}
void insert(Queue* q, int value) {
    if (q->rear < MAX_SIZE - 1) {
        q->rear++;
        q->data[q->rear] = value;
    }
    else
        exit(1);
    return;
}
int isEmpty(Queue* q) {
    return q->rear < q->front;
}
int remove(Queue* q) {
    int x, h;
    if (isEmpty(q) == 1) {
        exit(1);
    }
    x = q->data[q->front];
    for (h = q->front; h < q->rear; h++) {
        q->data[h] = q->data[h + 1];
    }
    q->rear--;
    return x;
}
int main()
{
    Queue q;
    init(&q);
    insert(&q, 12);
    insert(&q, 18);
    printf("%d\n", isEmpty(&q));
    printf("%d\n", remove(&q));
    printf("%d\n", remove(&q));
    printf("%d\n", isEmpty(&q));
}
