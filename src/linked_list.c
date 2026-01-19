#include <linked_list.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

linkedlist* create(int id, char name[64]){
    linkedlist *newlink = (linkedlist*)malloc(sizeof(linkedlist));
    if (newlink == NULL) {
        printf("Memory allocation failed. \n");
        return NULL;
    }
    // newlink->name = ;
    memcpy(newlink->name,name,64*sizeof(char));
    newlink->id = id;
    newlink->next = NULL;

    return newlink;
}
void add(linkedlist **head,int id, char name[64]){
    linkedlist *newlink = create(id, name);
    if (newlink == NULL) return;
    newlink->next = *head;
    *head = newlink;
    printf("Adding id->%d name->%s next_pointer->%p\n",newlink->id,newlink->name,newlink->next);

}
void print_list(linkedlist *head){
    linkedlist *temp = head;
    while (temp !=NULL)
    {
        printf("-> %d, %s <-\n",temp->id,temp->name);
        temp= temp->next;
    }
}