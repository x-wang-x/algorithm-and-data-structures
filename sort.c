#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int print_array(char *msg,int *arr, int *size);
void sort(int *arr, int *n);
void swap(int *a,int *b);
int main(void)
{
  int n;
  printf("Number of array ? ");
  //input array size
  scanf_s("%i", &n);
  //allocate memory size of an integer * n
  int *array = malloc(sizeof(unsigned int) * n);
  printf("%i",2);
  if (array == NULL)
  {
    return 1;
  }
  for (int i = 0; i < n; i++)
  {
    printf("Array for index[%i] : ", i);
    scanf_s("%i", &array[i]);
  }

  print_array("Inputed array -> ",array, &n);
  sort(array,&n);
  print_array("Sorted array -> ",array, &n);
  free(array);
  return 0;
}
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
//printing array
int print_array(char *msg,int *arr, int *size)
{
  //start with open bracket
  printf("%s[",msg);
  // print eacg element of array in horizontal
  for (int i = 0; i < *size; i++)
  {
    //only first until n-1 element that have comma
    if (i < *size - 1)
    {
      printf("%i, ", arr[i]);
    }
    //last element only print value, no comma included
    else
    {
      printf("%i", arr[i]);
    }
  }
  //print closed bracket
  printf("]\n");
}