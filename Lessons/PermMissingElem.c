/*

Lesson 3 - Find the missing element

An array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

Your goal is to find that missing element.

Write a function:

int solution(int A[], int N);

that, given an array A, returns the value of the missing element.

For example, given array A such that:

  A[0] = 2
  A[1] = 3
  A[2] = 1
  A[3] = 5
the function should return 4, as it is the missing element.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
the elements of A are all distinct;
each element of array A is an integer within the range [1..(N + 1)].
*/

int solution(int A[], int N)
{
// 100%
    int sum1 = 0, sum2 = 0;
    
    for (int i=0; i<N; i++) sum1 += A[i];
    for (int i=1; i<=N+1; i++) sum2 += i;
    
    return sum2 - sum1;

}