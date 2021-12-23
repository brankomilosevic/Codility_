/*
Lesson 10 - Count SemiPrimes

A prime is a positive integer X that has exactly two distinct divisors: 1 and X. The first few prime integers are 2, 3, 5, 7, 11 and 13.

A semiprime is a natural number that is the product of two (not necessarily distinct) prime numbers. The first few semiprimes are 4, 6, 9, 10, 14, 15, 21, 22, 25, 26.

You are given two non-empty arrays P and Q, each consisting of M integers. These arrays represent queries about the number of semiprimes within specified ranges.

Query K requires you to find the number of semiprimes within the range (P[K], Q[K]), where 1 ≤ P[K] ≤ Q[K] ≤ N.

For example, consider an integer N = 26 and arrays P, Q such that:

    P[0] = 1    Q[0] = 26
    P[1] = 4    Q[1] = 10
    P[2] = 16   Q[2] = 20
The number of semiprimes within each of these ranges is as follows:

(1, 26) is 10,
(4, 10) is 4,
(16, 20) is 0.
Write a function:

vector<int> solution(int N, vector<int> &P, vector<int> &Q);

that, given an integer N and two non-empty arrays P and Q consisting of M integers, returns an array consisting of M elements specifying the consecutive answers to all the queries.

For example, given an integer N = 26 and arrays P, Q such that:

    P[0] = 1    Q[0] = 26
    P[1] = 4    Q[1] = 10
    P[2] = 16   Q[2] = 20
the function should return the values [10, 4, 0], as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..50,000];
M is an integer within the range [1..30,000];
each element of arrays P and Q is an integer within the range [1..N];
P[i] ≤ Q[i].
*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> get_factors(int n) 
{
  vector<int> f(n+1, 0);
  f[1] = 1;
  int i = 2;
  
  while (i * i <= n) 
  {
    if (f[i] == 0) 
    {
      int k = i * i;
      while (k <= n) 
      {
        if (f[k] == 0)
          f[k] = i;
        k += i;
      }
    }
    ++i;
  }

  return f;
}

vector<int> solution(int N, vector<int> &P, vector<int> &Q) 
{
    vector<int> F = get_factors(N);
    vector<int> prefix_semi_primes(N + 1, 0);
    vector<int> res(P.size(), 0);

    for (int i = 1; i <= N; ++i) 
    {
        if (F[i] > 0 && F[i / F[i]] == 0)
            prefix_semi_primes[i]++;
        prefix_semi_primes[i] += prefix_semi_primes[i - 1];
    }

    const int M = P.size();
    
    for (int i = 0; i < M; i++) {
        res[i] = prefix_semi_primes[Q[i]] - prefix_semi_primes[P[i] - 1];
    }

    return res;
}

int main(void)
{ 
  vector<int> P = { 1, 4, 16 };
  vector<int> Q = { 26, 10, 20 };
  int N = 26;
  vector<int> sol = solution(N, P, Q);

  for (size_t i=0; i<sol.size(); ++i)
    cout << "[ " << sol[i] << " ]";

  return 0;
}