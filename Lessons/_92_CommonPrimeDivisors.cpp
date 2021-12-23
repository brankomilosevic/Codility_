/*
Lesson 12 - Common Prime Divisors

A prime is a positive integer X that has exactly two distinct divisors: 1 and X. The first few prime integers are 2, 3, 5, 7, 11 and 13.

A prime D is called a prime divisor of a positive integer P if there exists a positive integer K such that D * K = P. For example, 2 and 5 are prime divisors of 20.

You are given two positive integers N and M. The goal is to check whether the sets of prime divisors of integers N and M are exactly the same.

For example, given:

N = 15 and M = 75, the prime divisors are the same: {3, 5};
N = 10 and M = 30, the prime divisors aren't the same: {2, 5} is not equal to {2, 3, 5};
N = 9 and M = 5, the prime divisors aren't the same: {3} is not equal to {5}.
Write a function:

int solution(vector<int> &A, vector<int> &B);

that, given two non-empty arrays A and B of Z integers, returns the number of positions K for which the prime divisors of A[K] and B[K] are exactly the same.

For example, given:

    A[0] = 15   B[0] = 75
    A[1] = 10   B[1] = 30
    A[2] = 3    B[2] = 5
the function should return 1, because only one pair (15, 75) has the same set of prime divisors.

Write an efficient algorithm for the following assumptions:

Z is an integer within the range [1..6,000];
each element of arrays A and B is an integer within the range [1..2,147,483,647].

*/

#include<iostream>
#include<vector>
#include<set>

using namespace std;

set<int> get_factors(int n)
{
    set<int> f;
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        f.insert(2);
        n = n/2;
    }
 
    // n must be odd at this point. So we can skip one element (Note i = i +2)
    for (int i = 3; i * i<= n; i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            f.insert(i);
            n = n/i;
        }
    }
 
    // This condition is to handle the case when n is a prime number greater than 2
    if (n > 2)
        f.insert(n);

    return f;
}

int solution(vector<int> &A, vector<int> &B)
{
// 92% grade, time complexity for extremely large numbers

    int k = A.size();
    int count = 0;
    set<int> a;
    set<int> b;
    for (int i=0; i<k; ++i)
    {
        if (A[i] % 2 == 0 && B[i] % 2 != 0) continue;
        if (A[i] % 2 != 0 && B[i] % 2 == 0) continue;
        if (A[i] == B[i])
        {
            ++count;
            continue;
        }
        a = get_factors(A[i]);
        b = get_factors(B[i]);

        if ( a == b )
            ++count;
    }

    return count;
} 

int main(void)
{
    vector<int> A = { 15, 10, 3 };
    vector<int> B = { 75, 30, 5 };
    int K = solution(A, B);

    cout << "Number of positions for which prime divisors of A and B are same is: " << K;
    return 0;
}