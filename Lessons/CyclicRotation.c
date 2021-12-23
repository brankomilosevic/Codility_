/*

Lesson2 - Cyclic Rotation

An array A consisting of N integers is given. 
Rotation of the array means that each element is shifted right by one index, and the last element of the array is moved to the first place. 
For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7] (elements are shifted right by one index and 6 is moved to the first place).

The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.

Assume that the following declarations are given:

struct Results {
  int * A;
  int N; // Length of the array
};

Write a function:

struct Results solution(int A[], int N, int K);

that, given an array A consisting of N integers and an integer K, returns the array A rotated K times.

For example, given

    A = [3, 8, 9, 7, 6]
    K = 3
the function should return [9, 7, 6, 3, 8]. Three rotations were made:

    [3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
    [6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
    [7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]
For another example, given

    A = [0, 0, 0]
    K = 1
the function should return [0, 0, 0]

Given

    A = [1, 2, 3, 4]
    K = 4
the function should return [1, 2, 3, 4]

Assume that:

N and K are integers within the range [0..100];
each element of array A is an integer within the range [−1,000..1,000].
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.
*/

#include<stdio.h>
#include<stdlib.h>

struct Results {
  int * A;
  int N; // Length of the array
};

struct Results solution(int A[], int N, int K)
{
// 100%   
    struct Results B;
    B.N = N;
    B.A = (int *) malloc(N * sizeof(int));

    for (int i=0; i<N; i++) B.A[i] = A[i];
        
    int tmp; 
    
    for (int j=0; j<K; j++)
    {
        tmp = B.A[N-1];
        for (int i=N-1; i>0; i--)
        {
            B.A[i] = B.A[i-1];
        }
        B.A[0] = tmp;
    }
    return B;
}

int main(void)
{
    int A[] = { 1, 2, 3, 4 };
    int N = 4;
    int K = 2;

    printf("\nBefore rotation:\n");
    for (int i = 0; i < N; ++i) printf("%d ", A[i]);
    
    struct Results res = solution(A, N, K);
    
    printf("\nAfter rotation of %d times:\n", K);
    for (int i = 0; i < N; ++i) printf("%d ", res.A[i]);
    
    return 0;
}
