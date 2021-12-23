/*
Lesson 6 - Maximum product of three

A non-empty array A consisting of N integers is given. The product of triplet (P, Q, R) equates to A[P] * A[Q] * A[R] (0 ≤ P < Q < R < N).

For example, array A such that:

  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[3] = -2
  A[4] = 5
  A[5] = 6
contains the following example triplets:

(0, 1, 2), product is −3 * 1 * 2 = −6
(1, 2, 4), product is 1 * 2 * 5 = 10
(2, 4, 5), product is 2 * 5 * 6 = 60
Your goal is to find the maximal product of any triplet.

Write a function:

int solution(int A[], int N);

that, given a non-empty array A, returns the value of the maximal product of any triplet.

For example, given array A such that:

  A[0] = -3
  A[1] = 1
  A[2] = 2
  A[3] = -2
  A[4] = 5
  A[5] = 6
the function should return 60, as the product of triplet (2, 4, 5) is maximal.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [3..100,000];
each element of array A is an integer within the range [−1,000..1,000].
*/

#include<stdio.h>
#include<stdlib.h>

int cmp(const void * a, const void * b)
{
  return *(int *)a - *(int *)b;
}

int solution__old(int A[], int N)
{
// 100%, nut too many A[N-1] * A[N-2] * A[N-3]
  int res = 1;

  if (N < 3) return 0;
  qsort(A, N, sizeof(A[0]), cmp);
  // for (int i=0; i<N; ++i) printf("%d ", A[i]);
  
  if (A[0] >= 0)
  {
    res = A[N-1] * A[N-2] * A[N-3];
    return res;
  }
  else if (A[0] < 0 && A[1] >= 0)
  {
    res = A[N-1] * A[N-2] * A[N-3];
    return res;
  }
  else if (A[N-1] <= 0)
  {
    res = A[N-1] * A[N-2] * A[N-3];
    return res; 
  }
  else
  {
    if (A[0] * A[1] * A[N-1] > A[N-1] * A[N-2] * A[N-3])
    {
      res = A[0] * A[1] * A[N-1];
      return res;
    }
    else
    {
      res = A[N-1] * A[N-2] * A[N-3];
      return res;
    }
  }

  return res;
}

int solution(int A[], int N) 
{
    // write your code in C
    qsort(A, N, sizeof(A[0]), cmp);
    int res1 = A[0] * A[1] * A[N - 1];
    int res2 = A[N - 3] * A[N - 2] * A[N - 1];
    return res1 > res2 ? res1 : res2;
}

int main(void)
{

  // int arr[] = {-3, 1, 2, -2, 5, 6};
  int arr[] = { 4, 7, 3, 2, 1, -3, -5 };
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("\n\nMaximal product f triplets is: %d", solution(arr, n));

  return 0;
}