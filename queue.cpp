#define _CRT_SECURE_NO_WARNINGS
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#define MAX_SIZE 100
typedef struct Node {
    int data;
    struct Node* next;
} Node;
typedef struct {

    Node* front;
    Node* rear;
}Queue;
void init(Queue* q)
{
    q->front = NULL;
    q->rear = NULL;

}
int isEmpty(Queue* q)
{
    return q->front == NULL;
}
void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(1*sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}
int dequeue(Queue* q)
{
    if (isEmpty(q))
    {
        exit(1);
    }
    Node* t = q->front;
    int value = t->data;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(t);
    return value;
    
    
}
int peek(Queue* q) {
    if (isEmpty(q))
    {
        exit(1);
    }
    return q->front -> data;
}
int main()
{
    Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printf("%d\n", peek(&q));        // 10
    printf("%d\n", dequeue(&q));  // 10
    printf("%d\n", dequeue(&q));  // 20
    enqueue(&q, 40);
    printf("%d\n", peek(&q));        // 30
    printf("%d\n", dequeue(&q));  // 30
    printf("%d\n", dequeue(&q));  // 40

    return 0;
}
