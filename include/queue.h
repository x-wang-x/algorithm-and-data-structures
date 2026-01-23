#ifndef QUEUE
#define QUEUE

typedef struct Queue{
    int data;
    struct Queue *next;
} Queue;

void enqueue(int data);
void dequeue();
void displayQueue();

#endif