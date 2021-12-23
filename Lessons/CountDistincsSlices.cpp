/*
Lesson 15 - Count Distinct Slices
An integer M and a non-empty array A consisting of N non-negative integers are given. All integers in array A are less than or equal to M.
A pair of integers (P, Q), such that 0 ≤ P ≤ Q < N, is called a slice of array A. The slice consists of the elements A[P], A[P + 1], ..., A[Q]. 
A distinct slice is a slice consisting of only unique numbers. That is, no individual number occurs more than once in the slice.
For example, consider integer M = 6 and array A such that:
    A[0] = 3
    A[1] = 4
    A[2] = 5
    A[3] = 5
    A[4] = 2
There are exactly nine distinct slices: (0, 0), (0, 1), (0, 2), (1, 1), (1, 2), (2, 2), (3, 3), (3, 4) and (4, 4).
The goal is to calculate the number of distinct slices.
Write a function:
int solution(int M, int A[], int N);
that, given an integer M and a non-empty array A consisting of N integers, returns the number of distinct slices.
If the number of distinct slices is greater than 1,000,000,000, the function should return 1,000,000,000.
For example, given integer M = 6 and array A such that:
    A[0] = 3
    A[1] = 4
    A[2] = 5
    A[3] = 5
    A[4] = 2
the function should return 9, as explained above.
Write an efficient algorithm for the following assumptions:
N is an integer within the range [1..100,000];
M is an integer within the range [0..100,000];
each element of array A is an integer within the range [0..M].
*/

#include<iostream>
#include<vector>
int solution(int M, std::vector<int> &A)
{
// 100% (do not understand, yet)
      // array to remember last positions of values
      int vMax = A[0];
      for (size_t i = 1; i < A.size(); ++i) 
        vMax = vMax > A[i] ? vMax : A[i];
      
      if (A.size() == 1) return 1;
      if (M < 1) return 0;

      std::vector<int> vLastPos (vMax + 1, 0);
    
      for (size_t i = 0; i < vLastPos.size(); ++i) 
        vLastPos[i] = -1;
      // each element adds the same number of slices as is the length of current distinct slice

      int vSlices = 0, vNewStart = -1;

      for (size_t i = 0; i < A.size(); ++i)
      {
         int vVal = A[i];
         int vPrevPos = vLastPos[vVal];
         vSlices += i - (vPrevPos > vNewStart ? vPrevPos : vNewStart);
         
         if (vSlices > 1000000000) return 1000000000;
         
         if (vPrevPos != -1) 
            vNewStart = vNewStart > vPrevPos ? vNewStart : vPrevPos; // actual start of distinct slice
         
         vLastPos[vVal] = i;
      }
      return vSlices;
}

int main(void)
{
    std::vector<int> A = { 3, 4, 5, 5, 2};
    int M = 6;

    std::cout << "Number of distinct slices is: " << solution(M, A);

    return 0;
}