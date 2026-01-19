#ifndef LINKED_L
#define LINKED_L


//create struct that have id and name size of 64, and pointer to next struct
typedef struct linkedlist
{
    int id;
    char name[64];
    struct linkedlist *next;
} linkedlist;

struct linkedlist* create(int id, char name[64]);
void add(linkedlist **head, int id, char name[64]);
void print_list();

#endif