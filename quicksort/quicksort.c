#include <stdio.h>
#include "lib.h" 

/*
    Implement the Quicksort algorithm. You'll likely want to re-use the
    `swap` function you implemented in the pointers module (which is
    already being included for you in this file).

    The `low` and `high` parameters indicate the lowest and highest indices
    of the array that is getting passed in. This is necessary because the 
    function is being passed a pointer to the array, not the contents of the
    array. We can't easily figure out the length of the array through the 
    pointer, so the function receives the highest and lowest indices as
    parameters to circumvent this issue.
    
    Do not just use the `qsort` function from the standard library.
*/

int sortHelper (int arr[], int l, int h)
{
  //gets us our pivot element
  int pivot = arr[h];
  //get us the index of the smaller element
  int i = (l - 1);
  for (int j = l; j <= h - 1; j++)
  {
    //if the element is smaller than or equal to
    //the current pivot I swap the values
    if(arr[j] <= pivot)
    {
      //here I increment the 
      //index of the smaller elemnt by 1
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[h]);
  return (i + 1);
}


void quicksort(int *arr, int l, int h)
{
  if (l < h)
  {
    //makes sure my index is at the currect place
    int p = sortHelper(arr, l, h);

    quicksort(arr, l, p - 1); //after
    quicksort(arr, p + 1, h); //before
  }
}

#ifndef TESTING
int main(void)
{
    int arr1[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    quicksort(arr1, 0, n-1);

    for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }

    printf("\n");

    return 0;
}
#endif
