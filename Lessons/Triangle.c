/*
Lesson 6 - Triangle

An array A consisting of N integers is given. A triplet (P, Q, R) is triangular if 0 ≤ P < Q < R < N and:

A[P] + A[Q] > A[R],
A[Q] + A[R] > A[P],
A[R] + A[P] > A[Q].
For example, consider array A such that:

  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 20
Triplet (0, 2, 4) is triangular.

Write a function:

int solution(int A[], int N);

that, given an array A consisting of N integers, returns 1 if there exists a triangular triplet for this array and returns 0 otherwise.

For example, given array A such that:

  A[0] = 10    A[1] = 2    A[2] = 5
  A[3] = 1     A[4] = 8    A[5] = 20
the function should return 1, as explained above. Given array A such that:

  A[0] = 10    A[1] = 50    A[2] = 5
  A[3] = 1
the function should return 0.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
*/

#include <stdio.h>
#include <stdlib.h>

int cmp (const void * a, const void * b)
{
  return *(int*)a - *(int*)b;
}
int solution(int A[], int N)
{
// 100%
  int res = 0;
  if (N < 3) return res;

  qsort(A, N, sizeof(A[0]), cmp);

  for (int i = 0; i < N-2; ++i)
  {
    int P = i;
    int Q = i + 1;
    int R = i + 2;

    if ( (A[P] > A[R] - A[Q]) && (A[Q] > A[P] - A[R]) && (A[R] > A[Q] - A[P])) return 1;
  }

  return 0;
}

int main(void)
{
  // int arr[] = {10, 2, 5, 1, 8, 20};
  // int arr[] = {10, 50, 5, 1};
  int arr[] = { 10, INT_MIN, INT_MIN };
  // int arr[] = { INT_MAX, INT_MAX, INT_MAX };
  
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("\n\nTriangular triplet: << %d >>", solution(arr, n));

  return 0;

}