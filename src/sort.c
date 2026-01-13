#include "sort.h"
// swap value between variable
void swap(int *a, int *b){
  int temp = 0;
  temp = *a;
  *a = *b;
  *b = temp;
}
void sort(int *arr, int *n){
  //iterate all array indexes, this become a current index, later on gone compare to current + 1 (right current index)
  // iterate only until n-1 because the last array (n) not gonna compared to anyhting (dont have right value)
  for (int i = 0; i < *n-1; i++)
  {
    // for every array , compare if n less than n+1 swap value, so the higher value placed on left
    // keep comparing current index with current index +1 until end of array 
    for (int y=i+1; y < *n; y ++){
      if (arr[i]<arr[y]){
        swap(&arr[i],&arr[y]);
      }
    }
  }
  
}