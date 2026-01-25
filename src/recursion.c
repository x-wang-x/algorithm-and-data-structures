#include "recursion.h"

int sumArray(int *number,int n){
    if (n == 0)
        return 0;
    return number[n - 1] + sumArray(number, n - 1);
}
//call stack happen:
/*
example array of = [5,6,7,8]
base case is ,  n == 0 , mean that is there 0 element of array the sum is 0
sumArray(number,4) = 8 + (sumArray(number,3))
v
sumArray(number,3) = 7 + (sumArray(number,2))
v
sumArray(number,2) = 6 + (sumArray(number,1))
v
sumArray(number,1) = 5 + (sumArray(number,0))
v
sumArray(number,0) = 0 <-- Base case

so, return goes up :
sumArray(number,1) = 0 (base) + 5 = 5
sumArray(number,2) = 5+6 = 11
sumArray(number,3) = 11+7 = 18
sumArray(number,4) = 18 + 8 = 26
final --> 26
*/