#include <linked_list.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

linkedlist* create(int id, char name[64]){
    //allocate memory of a list (struct)
    linkedlist *newlink = (linkedlist*)malloc(sizeof(linkedlist));
    if (newlink == NULL) {
        printf("Memory allocation failed. \n");
        return NULL;
    }
    // copy memory buffer of a name ( because is an array , cannot be assigned directly)
    memcpy(newlink->name,name,64*sizeof(char));
    newlink->id = id;
    newlink->next = NULL;

    return newlink;
}
void add(linkedlist **head,int id, char name[64]){
    linkedlist *newlink = create(id, name);
    if (newlink == NULL) return;
    //set the head of linkedlist to new created list
    //for example if the current head is NULL , it's gonna set this function to add new list and set it as head
    //and put NULL to current next
    //but if current head  it's a valid head, it's set 'next' of a new inputed list to current head (the head when function called)
    //so basically the current head is always the new created list and point down until the NULL pointer
    newlink->next = *head;
    *head = newlink;
    printf("Adding id->%d name->%s next_pointer->%p\n",newlink->id,newlink->name,newlink->next);

}
void print_list(linkedlist *head){
    linkedlist *temp = head;
    while (temp !=NULL)
    {
        printf("-> %d, %s <-\n",temp->id,temp->name);
        //set current list to next one
        temp= temp->next;
    }
}