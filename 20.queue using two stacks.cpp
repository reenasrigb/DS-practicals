#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* arr;
    int top;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->arr = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity - 1;
}

void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->arr[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->arr[stack->top--];
}

typedef struct {
    Stack* stack1;
    Stack* stack2;
} Queue;

Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->stack1 = createStack(capacity);
    queue->stack2 = createStack(capacity);
    return queue;
}

void enqueue(Queue* queue, int item) {
    while (!isEmpty(queue->stack1)) {
        push(queue->stack2, pop(queue->stack1));
    }
    push(queue->stack1, item);
    while (!isEmpty(queue->stack2)) {
        push(queue->stack1, pop(queue->stack2));
    }
}

int dequeue(Queue* queue) {
    if (isEmpty(queue->stack1)) {
        printf("Queue Underflow\n");
        return -1;
    }
    return pop(queue->stack1);
}

int front(Queue* queue) {
    if (isEmpty(queue->stack1)) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue->stack1->arr[queue->stack1->top];
}

int isQueueEmpty(Queue* queue) {
    return isEmpty(queue->stack1);
}

int isQueueFull(Queue* queue, int capacity) {
    return isFull(queue->stack1);
}

int main() {
    int capacity = 5;
    Queue* queue = createQueue(capacity);

    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);

    printf("Front element of the queue: %d\n", front(queue));

    dequeue(queue);
    dequeue(queue);

    printf("Front element of the queue: %d\n", front(queue));

    enqueue(queue, 6);
    enqueue(queue, 7);

    printf("Front element of the queue: %d\n", front(queue));

    return 0;
}

