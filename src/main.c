#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linked_list.h>

int main(void)
{
    linkedlist *head = NULL;
    printf("pointer = %p\n",&head);
    char name[64] = "test";
    add(&head, 10, name);
    strcpy(name,"wkwkwk");
    add(&head, 20,name);
    print_list(head);
}