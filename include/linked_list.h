#ifndef LINKED_L
#define LINKED_L

// create struct that have id and name size of 64, and pointer to next struct
typedef struct Node
{
    struct Node *prev;
    int number;
    struct Node *next;
} Node;
typedef struct NodeStuct {
    struct Node *head;
    struct Node *tail;
} NodeStuct;

struct Node* create(int number);
void reverse(Node **head);
void addNode(Node **tail, int id);
void printNode();

#endif