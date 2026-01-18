#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sort.h"
#include "search.h"

void print_array(char *msg, int *arr, int *size);
int* create_array(int n){
    // allocate memory size of an integer * n
    int *array = malloc(sizeof(unsigned int) * n);
    if (array == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < n; i++)
    {
        printf("Array for index[%i] : ", i);
        scanf_s("%i", &array[i]);
    }
    print_array("\nInputed array -> ", array, &n);
    return array;
}
void l_search()
{
    int n;
    printf("Number (n) of an array ? ");
    // input array size
    scanf_s("%i", &n);
    // allocate memory size of an integer * n
    int *array = create_array(n);
    if (array == NULL)
    {
        return;
    }
    int tofind;
    printf("\nSearching for ? ");
    scanf("%i", &tofind);
    int find = linear_search(array, &n, tofind);
    printf("Result : ");
    if (-1 != find)
    {
        printf("Found at index [%i]", find);
    }
    else
    {
        printf("Not found.");
    }
    free(array);

}
void q_sort(){
    int n;
    printf("Number (n) of an array ? ");
    // input array size
    scanf_s("%i", &n);
    // allocate memory size of an integer * n
    int *array = create_array(n);
    if (array == NULL)
    {
        return;
    }
    sort(array, &n);
    print_array("\nSorted array -> ", array, &n);
    free(array);
}
int main(int argc, char **argv)
{

    if (argc < 2)
    {
        printf("Please input operation !");
        return 1;
    }
    if (strcmp(argv[1], "search") == 0)
    {
        l_search();
    }
    if (strcmp(argv[1], "sort") == 0){
        q_sort();
    }
}
// printing array
void print_array(char *msg, int *arr, int *size)
{
    // start with open bracket
    printf("%s[", msg);
    // print eacg element of array in horizontal
    for (int i = 0; i < *size; i++)
    {
        // only first until n-1 element that have comma
        if (i < *size - 1)
        {
            printf("%i, ", arr[i]);
        }
        // last element only print value, no comma included
        else
        {
            printf("%i", arr[i]);
        }
    }
    // print closed bracket
    printf("]\n");
}