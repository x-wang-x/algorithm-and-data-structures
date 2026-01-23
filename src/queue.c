#include <stdio.h>
#include <queue.h>
#include <stdlib.h>
//initialize head and tail as null
Queue *head=NULL;
Queue *tail=NULL;

void enqueue(int data){
    //alloc memory a size of queue
    Queue *new = malloc(sizeof(Queue));
    if (new==NULL) return;
    new->data = data;
    new->next = NULL;

    //if no tail (null) set head and tail to new created queue
    if (tail==NULL){
        head = tail = new;
    }
    //if tail exist, set current tail *next to new created queue, and then make new queue as new "tail"
    else{
        tail->next = new;
        tail = new;
    }
    printf("Queued %d, ",data);
}
void dequeue(){
    //self explanatory
    if (head==NULL){
        printf("Queue is empty\n");
        return;
    }
    //set head as tmp var
    Queue *tmp = head;
    printf("Dequeued %d, ",tmp->data);
    //set head (new head) to whatever in head *next
    head=tmp->next;
    //free memory
    free(tmp);
}
void displayQueue(){
    //save head as tmp
    struct Queue *tmp = head;
    printf("Current queue -> ");
    //iterate every nodes of queue
    while (tmp != NULL) {
        printf("%d ", tmp->data);
        //set tmp as whatever pointer in *next (so it goes from the head to tail)
        tmp = tmp->next;
    }

    printf("\n");
}