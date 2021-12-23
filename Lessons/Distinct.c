/*
Leson 6 - distintc values 

Write a function

int solution(int A[], int N);

that, given an array A consisting of N integers, returns the number of distinct values in array A.

For example, given array A consisting of six elements such that:

 A[0] = 2    A[1] = 1    A[2] = 1
 A[3] = 2    A[4] = 3    A[5] = 1
the function should return 3, because there are 3 distinct values appearing in array A, namely 1, 2 and 3.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
*/

#include<stdio.h>
#include<stdlib.h>

int cmp(const void * a, const void * b)
{
    return *(int*)a - *(int*)b;
}

int solution(int A[], int N)
{
// 100%
    if (N == 0) return 0;

    int res = 1;

    qsort(A, N, sizeof(A[0]), cmp);

    for (int i = 1; i < N; ++i)
        if (A[i] != A[i-1]) ++res;

    return res;
}

int main(void)
{
    int arr[] = { 2, 1, 1, 2, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("\n\nNumber of distinct values is: %d", solution(arr, n));

    return 0;
}