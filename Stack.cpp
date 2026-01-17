#define _CRT_SECURE_NO_WARNINGS
#include <limits.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#define MAX_SIZE 100
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;
void init(Stack* s) {
    s->top = -1;
}
int isEmpty(Stack* s) {
    return s->top == -1;
}
int isFull(Stack* s) {
    return s->top == MAX_SIZE - 1;
}
void push(Stack* s,int value) {
    if (isFull(s))
    {
        exit(1);
    }
    else
    {
        s->data[++(s->top)] = value;
    }
}
int pop(Stack *s)
{
    if (isEmpty(s)) {
        exit(1);
    }
    else {
        return s->data[(s->top)--];
    }
}
int peek(Stack* s) {
    if (isEmpty(s)) {
        exit(1);
    }
    else {
        return s->data[(s->top)];
    }
}
int main()
{
    Stack a;
    init(&a);          
    push(&a, 13);    
    push(&a, 22);
    printf("%d\n", peek(&a));  
    printf("%d\n", pop(&a));  
    printf("%d\n", peek(&a));
    printf("%d\n", pop(&a));

    return 0;
}
