/*

Lesson 5 - Minimum average of two slices

A non-empty array A consisting of N integers is given. 
A pair of integers (P, Q), such that 0 ≤ P < Q < N, is called a slice of array A (notice that the slice contains at least two elements). 
The average of a slice (P, Q) is the sum of A[P] + A[P + 1] + ... + A[Q] divided by the length of the slice. 
To be precise, the average equals (A[P] + A[P + 1] + ... + A[Q]) / (Q − P + 1).

For example, array A such that:

    A[0] = 4
    A[1] = 2
    A[2] = 2
    A[3] = 5
    A[4] = 1
    A[5] = 5
    A[6] = 8
contains the following example slices:

slice (1, 2), whose average is (2 + 2) / 2 = 2;
slice (3, 4), whose average is (5 + 1) / 2 = 3;
slice (1, 4), whose average is (2 + 2 + 5 + 1) / 4 = 2.5.
The goal is to find the starting position of a slice whose average is minimal.

Write a function:

int solution(vector<int> &A);

that, given a non-empty array A consisting of N integers, returns the starting position of the slice with the minimal average. 
If there is more than one slice with a minimal average, you should return the smallest starting position of such a slice.

For example, given array A such that:

    A[0] = 4
    A[1] = 2
    A[2] = 2
    A[3] = 5
    A[4] = 1
    A[5] = 5
    A[6] = 8
the function should return 1, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [2..100,000];
each element of array A is an integer within the range [−10,000..10,000].
*/
#include<iostream>
#include<vector>
using namespace std;

// Kadane's algorithm
// 2021-11-30 //
// 100% grade //
// Have to admit, not originaly my solution //
int solution(vector<int> &A) 
{
    int N = A.size();
    vector<int> ps(N + 1, 0);
    
    for (int i = 1; i <= N; i++)
        ps[i] = A[i - 1] + ps[i - 1];

    int lft_idx, min_lft_idx;
    double avg_here, min_avg, avg_of_two, avg_with_prev;
    
    // Initialize variables at the first possible slice (A[0:1]).
    lft_idx = min_lft_idx = 0;
    avg_here = min_avg = (A[0] + A[1]) / 2.0;
    
    // Find min average of every slice that ends at ith element, starting at i = 2.
    for (int i = 2; i < N; i ++) 
    {
        // average of A[lft_idx : i]
        avg_with_prev = ((double) ps[i + 1] - ps[lft_idx]) / (i - lft_idx + 1);

        // average of A[i - 1 : i]
        avg_of_two = (A[i - 1] + A[i]) / 2.0;
        
        // Find minimum and update lft_idx of slice
        // (previous lft_idx or i - 1).
        if (avg_of_two < avg_with_prev) 
        {
            avg_here = avg_of_two;
            lft_idx = i - 1;
        }
        else
            avg_here = avg_with_prev;
        
        // Keep track of minimum so far and its left index.
        if (avg_here < min_avg) 
        {
            min_avg = avg_here;
            min_lft_idx = lft_idx;
        }
    }
        
    return min_lft_idx;
}

int main(void)
{
    vector<int> A = { 4, 2, 2, 5, 1, 5, 8 };

    cout << "Starting index of slice with minimal average is: " << solution(A);

    return 0;
}


