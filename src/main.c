#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sort.h"
#include "search.h"

void print_array(char *msg, int *arr, int *size);
void choose_mode(int *mode);
int main(void)
{
    int mode;
    choose_mode(&mode);
    int n;
    printf("Number (n) of an array ? ");
    // input array size
    scanf_s("%i", &n);
    // allocate memory size of an integer * n
    int *array = malloc(sizeof(unsigned int) * n);
    if (array == NULL)
    {
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("Array for index[%i] : ", i);
        scanf_s("%i", &array[i]);
    }
    print_array("\nInputed array -> \n", array, &n);


    switch (mode)
    {
    case 1:
        int tofind;
        printf("Searching for ? ");
        scanf("%i",&tofind);
        int find = linear_search(array,&n,tofind);
        if (-1!=find){
            printf("\nFound at index-%i.",find);
        }
        else {
            printf("\nNot found.");
        }
        break;
    case 2:
        sort(array, &n);
        print_array("\nSorted array -> ", array, &n);
        break;
    default:
        return 1;
    }

    free(array);
    return 0;
}
void choose_mode(int *mode)
{
    printf("===============\n1.Search\n2.Sort\n===============\nWhat to do ? ");
    scanf("%i", mode);
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