/*
Lesson 2 - Odd Occurencies in Array

A non-empty array A consisting of N integers is given. The array contains an odd number of elements, 
and each element of the array can be paired with another element that has the same value, except for one element that is left unpaired.

For example, in array A such that:

  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9
the elements at indexes 0 and 2 have value 9,
the elements at indexes 1 and 3 have value 3,
the elements at indexes 4 and 6 have value 9,
the element at index 5 has value 7 and is unpaired.
Write a function:

int solution(int A[], int N);

that, given an array A consisting of N integers fulfilling the above conditions, returns the value of the unpaired element.

For example, given array A such that:

  A[0] = 9  A[1] = 3  A[2] = 9
  A[3] = 3  A[4] = 9  A[5] = 7
  A[6] = 9
the function should return 7, as explained in the example above.

Write an efficient algorithm for the following assumptions:

N is an odd integer within the range [1..1,000,000];
each element of array A is an integer within the range [1..1,000,000,000];
all but one of the values in A occur an even number of times.
*/
#include<stdio.h>
#include<stdlib.h>

int solution(int A[], int N)
{
// 66% - time complexit and some boundary cases
    
    int index = 0;
    //int has_pair = 0;
    int arr[N];
    
    for (int i = 0; i < N; i++) arr[i] = 0;
    
    for (int i = 0; i < N; i++)
        for (int j = i+1; j < N; j++)
            if (( arr[i] == 0 ) && (A[i] == A[j])) { arr[i] = 1; arr[j] = 1; }
    
    for(int i = 0; i < N; i++) printf("%d ", A[i]);
    
    printf("\n");
    for(int i = 0; i < N; i++) printf("%d ", arr[i]);
    
    for (int i = 0; i < N; i++)
        if (!arr[i]) index = i;
        
    return A[index];
}

int cmp(const void *a, const void *b)
{
  return *(int*)a - *(int*)b;
}

int solution_2(int *arr, int n)
{ 
// 100%

  printf("\n-> initial:\t"); for (int i=0; i<n; ++i) printf(" %d", arr[i]);
  qsort(arr, n, sizeof(arr[0]), cmp);

  printf("\n-> sorted:\t"); for (int i=0; i<n; ++i) printf(" %d", arr[i]);

  for (int i=0; i<n; i+=2)
    if (arr[i] != arr[i+1]) return arr[i];

  return -1;
}

int main(void)
{
  int arr[] = {9, 3, 9, 3, 9, 7, 9};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("\nOdd element is: %d", solution_2(arr, n));

  return 0;
}