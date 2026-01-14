#include "search.h"

int linear_search(int *arr, int *n, int tofind)
{
    for (int i = 0; i < *n; i++)
    {
        if (arr[i] == tofind)
        {
            return i;
        }
    }
    return -1;
}