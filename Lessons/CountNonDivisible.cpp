/*
Lesson 11 - Count Non Divisible

You are given an array A consisting of N integers.

For each number A[i] such that 0 ≤ i < N, we want to count the number of elements of the array that are not the divisors of A[i]. 
We say that these elements are non-divisors.

For example, consider integer N = 5 and array A such that:

    A[0] = 3
    A[1] = 1
    A[2] = 2
    A[3] = 3
    A[4] = 6
For the following elements:

A[0] = 3, the non-divisors are: 2, 6,
A[1] = 1, the non-divisors are: 3, 2, 3, 6,
A[2] = 2, the non-divisors are: 3, 3, 6,
A[3] = 3, the non-divisors are: 2, 6,
A[4] = 6, there aren't any non-divisors.
Assume that the following declarations are given:

struct Results {
  int * C;
  int L; // Length of the array
};

Write a function:

struct Results solution(int A[], int N);

that, given an array A consisting of N integers, returns a sequence of integers representing the amount of non-divisors.

Result array should be returned as a structure Results.

For example, given:

    A[0] = 3
    A[1] = 1
    A[2] = 2
    A[3] = 3
    A[4] = 6
the function should return [2, 4, 3, 2, 0], as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..50,000];
each element of array A is an integer within the range [1..2 * N].
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> solution(vector<int> &A)
{
100%
  int len = A.size();
  int max = 0;
  for (int i=0; i<len; ++i)
    if (max < A[i])
      max = A[i];
  
  vector<int> counts (max + 1,0);

  // Calculate occurences of each number in the array
  for (int i = 0; i < len; ++i)
    counts[A[i]] += 1;

  vector<int> answer(len, 0);

  // For each element of the array
  for (int i = 0; i < len; ++i)	
  {
    // Calulate how many of its divisors are in the array
    int divisors = 0;
    const int num = A[i];
    for (int j = 1; j * j <= num; ++j)
    {
      if (num % j == 0)
      {
        divisors += counts[j];
        if (num / j != j) {
        divisors += counts[num / j];
      }
    }
  }

  // Subtract the number of divisors from the number of elements in the array
  answer[i] = len - divisors;
}

return answer;

}

int main(void)
{
  vector<int> A { 3, 1, 2, 3, 6 };
  vector<int>sol = solution(A);
  int len = sol.size();

  for (int i=0; i<len; ++i)
    cout << sol[i] << " ";
}
