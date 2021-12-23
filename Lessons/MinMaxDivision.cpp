/*
Lesson 14 - Min Max Division

You are given integers K, M and a non-empty array A consisting of N integers. Every element of the array is not greater than M.

You should divide this array into K blocks of consecutive elements.
The size of the block is any integer between 0 and N. Every element of the array should belong to some block.

The sum of the block from X to Y equals A[X] + A[X + 1] + ... + A[Y]. The sum of empty block equals 0.

The large sum is the maximal sum of any block.

For example, you are given integers K = 3, M = 5 and array A such that:

  A[0] = 2
  A[1] = 1
  A[2] = 5
  A[3] = 1
  A[4] = 2
  A[5] = 2
  A[6] = 2
The array can be divided, for example, into the following blocks:

[2, 1, 5, 1, 2, 2, 2], [], [] with a large sum of 15;
[2], [1, 5, 1, 2], [2, 2] with a large sum of 9;
[2, 1, 5], [], [1, 2, 2, 2] with a large sum of 8;
[2, 1], [5, 1], [2, 2, 2] with a large sum of 6.
The goal is to minimize the large sum. In the above example, 6 is the minimal large sum.

Write a function:

int solution(int K, int M, vector<int> &A);

that, given integers K, M and a non-empty array A consisting of N integers, returns the minimal large sum.

For example, given K = 3, M = 5 and array A such that:

  A[0] = 2
  A[1] = 1
  A[2] = 5
  A[3] = 1
  A[4] = 2
  A[5] = 2
  A[6] = 2
the function should return 6, as explained above.

Write an efficient algorithm for the following assumptions:

N and K are integers within the range [1..100,000];
M is an integer within the range [0..10,000];
each element of array A is an integer within the range [0..M].
*/

#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>

using namespace std;

int sum(vector<int> &V, int start, int end)
{
  int res = 0;
  for (int i=start; i<=end; ++i)
    res += V[i];
  return res;
}

int check(vector<int> A, int K, int mid)
{
  int blocks = 1;
  int sum = 0;

  for (int i=0; i<A.size(); ++i)
  {
    sum += A[i];

    if ( sum > mid )
    {
      ++blocks;
      sum = A[i];
    }

    if (blocks > K)
      return 0;
  }

  return 1;
}

// 2021-12-22
// 100% grade
int solution(int K, int M, vector<int> &A)
{
  int N = A.size();
  int min_sum = *max_element(A.begin(), A.end());
  int max_sum = accumulate(A.begin(), A.end(), 0);
  // int max_sum = sum(A, 0, N-1);

  if (K == 1)
    return max_sum;
  if (N == 1)
    return min_sum;
  
  // binary spliting the min...max range to find minimal max_sum
  int result = min_sum;
  int mid;
  while (min_sum <= max_sum)
  {
    mid = (max_sum + min_sum) / 2;

    if (check(A, K, mid)) // can we have <=K blocks with max sum equal to mid
    {
      max_sum = mid - 1;
      result = mid;
    }
    else
    {
      min_sum = mid + 1;
    }
  }

  return result;
}

int main(void)
{
  vector<int> A { 2, 1, 5, 1, 2, 2, 2 };
  int K = 3;
  int M = 5;

  cout << "\n>> Solution is: " << solution(K, M, A) << '\n';
  return 0;
}