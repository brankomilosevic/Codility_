/*

Lesson 15 - Abs Distinct

A non-empty array A consisting of N numbers is given. The array is sorted in non-decreasing order. 
The absolute distinct count of this array is the number of distinct absolute values among the elements of the array.

For example, consider array A such that:

  A[0] = -5
  A[1] = -3
  A[2] = -1
  A[3] =  0
  A[4] =  3
  A[5] =  6
The absolute distinct count of this array is 5, because there are 5 distinct absolute values among the elements of this array, namely 0, 1, 3, 5 and 6.

Write a function:

int solution(int A[], int N);

that, given a non-empty array A consisting of N numbers, returns absolute distinct count of array A.

For example, given array A such that:

  A[0] = -5
  A[1] = -3
  A[2] = -1
  A[3] =  0
  A[4] =  3
  A[5] =  6
the function should return 5, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−2,147,483,648..2,147,483,647];
array A is sorted in non-decreasing order.
*/

#include<iostream>
#include<vector>
#include<unordered_set>
using std::vector;

int abs(int N)
{
  if (N >= 0) return N;
  return -N;
}

int solution_old(vector<int> &A)
{
// 100%
  int res = 0;
  int len = A.size();

  if (len == 1) return 1;

  std::unordered_set<int> s;

  {    
    for (int i = 0; i < len; ++i)
    s.insert(abs(A[i]));
  }

  res = s.size();
  return res;
}

int solution(vector<int> A)
{
  int res = 0;
  int len = A.size();
  int index_left = 0;
  int index_right = len-1;

  if (len == 1) return 1;
  res = len;

  while (index_left < index_right)
  {
    while (index_left != index_right && A[index_left] == A[index_left + 1])
    {
      ++index_left;
      --res;
    }

    while (index_left != index_right && A[index_right] == A[index_right - 1])
    {
      --index_right;
      --res;
    }

    if (index_left == index_right) break;

    int sum = A[index_left] + A[index_right];

    if (sum == 0)
    {
      --res;
      ++index_left;
      --index_right;
    }
    else if (sum > 0)
    {
      --index_right;
    }
    else
    {
      ++index_left;
    }
  }
  return res;
}

int main(void)
{
  vector<int> A = { -5, -3, -1, 0, 3, 6};

  std::cout << "Number of distinct abs is: " << solution(A);

  return 0;
}