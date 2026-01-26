#include "sort.h"
#include "stdio.h"
#include <unistd.h>

// swap value between variable
void swap(int *a, int *b)
{
    printf("Swapping %d and %d\n",*a,*b);
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
    sleep(1);
}
/*
selection sort basicaaly iterate each element of array
finding max/min element then swap it
Time comp : O(n^2)
Space comp : O(n)
*/
void selection(int *arr, int *n)
{
    // iterate all array indexes, this become a current index, later on gone compare to current + 1 (right current index)
    //  iterate only until n-1 because the last array (n) not gonna compared to anyhting (dont have right value)
    for (int i = 0; i < *n - 1; i++)
    {
        // for every array , compare if n less than n+1 swap value, so the higher value placed on left
        // keep comparing current index with current index +1 until end of array
        for (int y = i + 1; y < *n; y++)
        {
            if (arr[i] < arr[y])
            {
                swap(&arr[i], &arr[y]);
            }
        }
    }
}
/*
it's basically similiar to selection
it begin put a pointer to array[1], compare it to left value
swap it if it less, then put pointer to next index
asumming left index is sorted, so current pointer comparing to the left sorted element
swap through iterated sorted left element until current pointer is the smallest value (between each element
on sorted left side) then stop.
Continue next index as new pointer, doin it until last element
Time comp : O(n^2)
Space comp : O(n)
*/
void insertion(int *arr, int *n){
    //iterate trough array
    for (int i = 0; i < *n-1; i++){
        //j is a pointer , it's start to point at arr[1] not [0] because it gonna compare to value from the left
        //if pointer in index[0] , it got no left side value
        int j = i+1;
        //check if array in pointer is less than left side , if it does swap it.
        //then if done swap, change pointer to index[n-1] , mean that if current iterate in [3] switch pointer to [2]
        //after that, do comparation again, swap & switch pointer again if meet condition
        //why wee need to put j>=0 ? it's make sure that loop doesn't go out of bound when switching pointer to left(decreasing its order, possible beyond 0)
        while (j>=0 && arr[j-1]>arr[j])
         {
            swap(&arr[j],&arr[j-1]);
            j-=1;
        }
         
    }
}