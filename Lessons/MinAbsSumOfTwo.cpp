/*
Lesson 15 - Min Abs Sum of Two

Let A be a non-empty array consisting of N integers.

The abs sum of two for a pair of indices (P, Q) is the absolute value |A[P] + A[Q]|, for 0 ≤ P ≤ Q < N.

For example, the following array A:

  A[0] =  1
  A[1] =  4
  A[2] = -3
has pairs of indices (0, 0), (0, 1), (0, 2), (1, 1), (1, 2), (2, 2).
The abs sum of two for the pair (0, 0) is A[0] + A[0] = |1 + 1| = 2.
The abs sum of two for the pair (0, 1) is A[0] + A[1] = |1 + 4| = 5.
The abs sum of two for the pair (0, 2) is A[0] + A[2] = |1 + (−3)| = 2.
The abs sum of two for the pair (1, 1) is A[1] + A[1] = |4 + 4| = 8.
The abs sum of two for the pair (1, 2) is A[1] + A[2] = |4 + (−3)| = 1.
The abs sum of two for the pair (2, 2) is A[2] + A[2] = |(−3) + (−3)| = 6.
Write a function:

int solution(vector<int> &A);

that, given a non-empty array A consisting of N integers, returns the minimal abs sum of two for any pair of indices in this array.

For example, given the following array A:

  A[0] =  1
  A[1] =  4
  A[2] = -3
the function should return 1, as explained above.

Given array A:

  A[0] = -8
  A[1] =  4
  A[2] =  5
  A[3] =-10
  A[4] =  3
the function should return |(−8) + 5| = 3.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].

*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solution_old(vector<int> &A)
{
    if (A.size() == 1)
        return abs(A[0] + A[0]);

    sort(A.begin(), A.end());

    int total_min = *min_element(A.begin(), A.end());
    if (total_min >= 0)
        return A[0] + A[0];

    int minimal_sum = INT_MAX;
    vector<int>::iterator P = A.begin();
    vector<int>::iterator Q = A.end() - 1;

    while (P < Q) 
    {
        minimal_sum = min(minimal_sum, abs(*P + *Q));
        minimal_sum = min(minimal_sum, abs(*P + *P));
        minimal_sum = min(minimal_sum, abs(*Q + *Q));

        if (abs(*(P + 1) + *Q) <= abs(*P + *(Q - 1)))
            P++;
        else      
            Q--;
    }

    minimal_sum = min(minimal_sum, abs(*P + *Q));
    return minimal_sum;
}

int my_abs(int a)
{
  if ( a >= 0)
    return a;
  return -a;
}

int my_min(int a, int b, int c)
{
  int res;
  res = a < b ? a : b;
  res = res < c ? res : c;

  return res;
}

int solution(vector<int> &A)
{
  int N = A.size();

  if (N == 1) return my_abs(A[0] + A[0]);

  sort(A.begin(), A.end());
  if (A[0] >= 0) return A[0] + A[0];

  int res = INT_MAX;
  int front = 0;
  int back = N - 1;

  while (front < back)
  {
    int m_1 = A[front] + A[back];
    int m_2 = A[front] + A[front];
    int m_3 = A[back]  + A[back];

    int tmp = my_min( my_abs(m_1), my_abs(m_2), my_abs(m_3) );
    res = res < tmp ? res : tmp;

    if ( my_abs( A[front + 1] + A[back] ) <= my_abs( A[front] + A[back - 1] ) )
    { 
      ++front;
    }
    else
    {
      --back;
    }
  }

  return res;
}

int main(void)
{
  //vector<int> A { 1, 4, -3 };
  vector<int> A { -8, 4, 5, -10, 3};

  cout << "Solution: " << solution(A);
  return 0;
}