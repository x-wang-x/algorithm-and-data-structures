#ifndef LINKED_L
#define LINKED_L

// create struct that have id and name size of 64, and pointer to next struct
typedef struct Node
{
    struct Node *prev;
    int number;
    struct Node *next;
} Node;
typedef struct NodeList
{
    Node *head;
    Node *tail;
} NodeList;

void addLastNode(NodeList *list, int number);
void addFirstNode(NodeList *list, int number);
void printNode();

#endif