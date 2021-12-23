/*
A positive integer N is given. The goal is to find the highest power of 2 that divides N. 
In other words, we have to find the maximum K for which N modulo 2^K is 0.

For example, given integer N = 24 the answer is 3, because 2^3 = 8 is the highest power of 2 that divides N.

Write a function:

int solution(int N);

that, given a positive integer N, returns the highest power of 2 that divides N.

For example, given integer N = 24, the function should return 3, as explained above.

Assume that:

N is an integer within the range [1..1,000,000,000].
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.
*/

#include<iostream>

int solution(int N)
{
    int i = 0;

    while (N % (1 << i) == 0)
        ++i;

    return i-1;
}

int main(void)
{
    int N = 8;

    std::cout << "Maximum K for which 2^k devides " << N << " is: " << solution(N);

    return 0;
}