#include <linked_list.h>
#include <stdio.h>
#include <stdlib.h>

Node *initNode(int number)
{
    //alloc a memory size of a node
    Node *node = (Node *)malloc(sizeof(Node));
    if (node == NULL)
    {
        printf("Memory allocation failed. \n");
        return NULL;
    }
    //set next and prev to null as default
    node->prev = NULL;
    node->next = NULL;
    node->number = number;

    return node;
}
void addFirstNode(NodeList *list, int number)
{
    //initialize new default node
    Node *newNode = initNode(number);
    if (newNode == NULL)
        return;
    //if current head is not null, modify the new node *next to current head, and current head *prev to newnode
    if (list->head != NULL)
    {
        newNode->next = list->head;
        list->head->prev = newNode;
    }
    //if current head is null , set the new node as a head also tail
    else{
        list->tail = newNode;
    }
    //set the head to new created node
    list->head = newNode;
}
void addLastNode(NodeList *list, int number)
{
    //initialize new default node
    Node *newNode = initNode(number);
    if (newNode == NULL)
        return;
    //if tail is exist, set new created node *prev to current tail, and current tail *next to new created node
    if (list->tail != NULL && list->head != NULL)
    {
        newNode->prev = list->tail;
        list->tail->next = newNode;
    }
    //if tail is not exist, set new created node as tail also a head
    else {
        list->head = newNode;
    }
    list->tail = newNode;
}
void printNode(char *pre, Node *head, char *post)
{
    //print string before dispalying list
    printf("%s", pre);
    Node *p_temp = head;
    while (p_temp != NULL)
    {
        printf("node-address : %p | prev -> %p | value-> %d | next-> %p\n", p_temp, p_temp->prev, p_temp->number, p_temp->next);
        // set current list to next one
        p_temp = p_temp->next;
    }
    //print string after dispalying list
    printf("%s", post);
}