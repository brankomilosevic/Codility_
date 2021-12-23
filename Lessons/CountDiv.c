
/*
Lesson 5 - Count Div

Write a function:

int solution(int A, int B, int K);

that, given three integers A, B and K, returns the number of integers within the range [A..B] that are divisible by K, i.e.:

{ i : A ≤ i ≤ B, i mod K = 0 }

For example, for A = 6, B = 11 and K = 2, your function should return 3, because there are three numbers divisible by 2 within the range [6..11], namely 6, 8 and 10.

Write an efficient algorithm for the following assumptions:

A and B are integers within the range [0..2,000,000,000];
K is an integer within the range [1..2,000,000,000];
A ≤ B.
*/
#include<stdio.h>
int solution(int A, int B, int K)
{
// 100%
    int a = A/K + 1; //printf("|a: %d", a);
    int b = B/K + 1; //printf("|b: %d", b);
    
    int res = b - a; //printf("|r: %d", res);
    
    if (!(A%K)) ++res;
    
    return res;
}

int main(void)
{
    int A = 6;
    int B = 11;
    int K = 2;

    printf("\nNumber of integers between %d and %d divisible by %d is: %d", A, B, K, solution(A, B, K));
}