#include <linked_list.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Node* create(int number){
    Node *node = (Node*)malloc(sizeof(Node));
    if (node == NULL){
        printf("Memory allocation failed. \n");
        return NULL;
    }
    node->prev = NULL;
    node->next = NULL;
    node->number = number;

    return node;
}
void addNode(Node **tail, int number){
    Node *newNode = create(number);
    printf("Creating %d to %p\n",number,newNode);

    if (newNode==NULL) return;
    if ((*tail)!=NULL){
        newNode->prev = *tail;
        (*tail)->next = newNode;
        newNode->number = number;
    }
    *tail = newNode;
    printf("prev -> %p | value-> %d | next-> %p\n",(*tail)->prev,(*tail)->number,(*tail)->next);
}
void reverse(Node **head)
{
    Node *prev = NULL;
    Node *next = NULL;
    Node *curr = *head;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
void printNode(char *pre,Node *head,char *post)
{
    printf("%s",pre);
    Node *temp = head;
    while (temp != NULL)
    {
        printf("-> %d <-\n", temp->number);
        // set current list to next one
        temp = temp->next;
    }
    printf("%s",post);

}