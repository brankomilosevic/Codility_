/*

Lesson 9 - Max Slice Sum

A non-empty array A consisting of N integers is given. 
A pair of integers (P, Q), such that 0 ≤ P ≤ Q < N, is called a slice of array A. 
The sum of a slice (P, Q) is the total of A[P] + A[P+1] + ... + A[Q].

Write a function:

int solution(vector<int> &A);

that, given an array A consisting of N integers, returns the maximum sum of any slice of A.

For example, given array A such that:

A[0] = 3  A[1] = 2  A[2] = -6  A[3] = 4  A[4] = 0
the function should return 5 because:

(3, 4) is a slice of A that has sum 4,
(2, 2) is a slice of A that has sum −6,
(0, 1) is a slice of A that has sum 5,
no other slice of A has sum greater than (0, 1).
Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..1,000,000];
each element of array A is an integer within the range [−1,000,000..1,000,000];
the result will be an integer within the range [−2,147,483,648..2,147,483,647].

*/
#include<iostream>
#include<vector>
using namespace std;


int solution(vector<int> &A)
{
// 84%
    int res = -1000001;
    int loc = -100001;
    size_t len = A.size();

    if (len == 1) return A[0];
    
    // trivial max of triple
    if (len == 2)
    {
        int a = A[0];
        int b = A[1];
        int c = A[0] + A[1];

        if (a>=b && a>=c) return a;
        if (b>=a && b>=c) return b;
        if (c>=a && c>=b) return c; 
    }

    loc = A[0];
    for (size_t i=1; i<len; ++i)
    {
        if (A[i] > loc + A[i])
            loc = A[i];
        else  
            loc = A[i] + loc;
        
        if (res < loc) res = loc;

    }
    return res;
}

int main(void)
{
    vector<int> A = { 3, 2, -6, 4, 0};
    // vector<int> A = { -2, 1, 1 };
    
    cout << "Maximum sum of slice is: " << solution(A);
    return 0;
}