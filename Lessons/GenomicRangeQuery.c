/*
Lesson 5 - Genomic Range Query

A DNA sequence can be represented as a string consisting of the letters A, C, G and T, which correspond to the types of successive nucleotides in the sequence. 
Each nucleotide has an impact factor, which is an integer. 
Nucleotides of types A, C, G and T have impact factors of 1, 2, 3 and 4, respectively. 

You are going to answer several queries of the form: 
What is the minimal impact factor of nucleotides contained in a particular part of the given DNA sequence?

The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1] consisting of N characters. 
There are M queries, which are given in non-empty arrays P and Q, each consisting of M integers. 
The K-th query (0 ≤ K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K] (inclusive).

For example, consider string S = CAGCCTA and arrays P, Q such that:

    P[0] = 2    Q[0] = 4
    P[1] = 5    Q[1] = 5
    P[2] = 0    Q[2] = 6
The answers to these M = 3 queries are as follows:

The part of the DNA between positions 2 and 4 contains nucleotides G and C (twice), whose impact factors are 3 and 2 respectively, so the answer is 2.
The part between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so the answer is 4.
The part between positions 0 and 6 (the whole string) contains all nucleotides, in particular nucleotide A whose impact factor is 1, so the answer is 1.
Assume that the following declarations are given:

struct Results {
  int * A;
  int M; // Length of the array
};

Write a function:

struct Results solution(char *S, int P[], int Q[], int M);

that, given a non-empty string S consisting of N characters and two non-empty arrays P and Q consisting of M integers, 
returns an array consisting of M integers specifying the consecutive answers to all queries.

Result array should be returned as a structure Results.

For example, 
#1
given the string S = CAGCCTA and arrays P, Q such that:

P[0] = 2    Q[0] = 4
P[1] = 5    Q[1] = 5
P[2] = 0    Q[2] = 6
the function should return the values [2, 4, 1], as explained above.

#2
given the string S = GACACCATA  and arrays P, Q such that:

P[0] = 0    Q[0] = 8
P[1] = 0    Q[1] = 2
P[2] = 4    Q[2] = 5
P[3] = 7    Q[3] = 7
the function should return the values [1, 1, 2, 4], as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
M is an integer within the range [1..50,000];
each element of arrays P and Q is an integer within the range [0..N − 1];
P[K] ≤ Q[K], where 0 ≤ K < M;
string S consists only of upper-case English letters A, C, G, T.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Results {
  int * A;
  int M; // Length of the array
};

struct Results solution_old(char *S, int P[], int Q[], int M)
{
// 66% - time complexity
	
    struct Results res;
    res.A = (int *) malloc(M * sizeof(int));
    res.M = M;
    // int N = strlen(S);
    int min, l;
    for (int i=0; i<M; i++)
    {
        min = 5;
        for (int j=P[i]; j<=Q[i]; j++)
        {
            if (S[j] == 'A') { l = 1; }
            if (S[j] == 'C') { l = 2; }
            if (S[j] == 'G') { l = 3; }
            if (S[j] == 'T') { l = 4; }
            if (min > l) min = l;
         } 
         res.A[i] = min;
    }
    
    return res;
}

struct Results solution(char *S, int P[], int Q[], int M)
{
// 100%
  struct Results res;
  res.A = (int *) malloc(M * sizeof(int));
  res.M = M;

  int n = strlen(S);
  int matrix[4][n+1];

  for (int i = 0; i < 4; ++i)
    for (int j = 0; j < n; ++j)
      matrix[i][j] = 0;

  if (S[0] == 'A') matrix[0][0] = 1;
  if (S[0] == 'C') matrix[1][0] = 1;
  if (S[0] == 'G') matrix[2][0] = 1;
  if (S[0] == 'T') matrix[3][0] = 1;

  for (int i = 0; i < n; ++i)
  {
    int a_0 = 0, a_1 = 0, a_2 = 0, a_3 = 0;
    if (S[i] == 'A') { a_0 = 1; }
    if (S[i] == 'C') { a_1 = 1; }
    if (S[i] == 'G') { a_2 = 1; }
    if (S[i] == 'T') { a_3 = 1; }    

    matrix[0][i+1] = matrix[0][i] + a_0;
    matrix[1][i+1] = matrix[1][i] + a_1;
    matrix[2][i+1] = matrix[2][i] + a_2;
    matrix[3][i+1] = matrix[3][i] + a_3;
  }

  for (int i = 0; i < 4; ++i)
  {
    printf("\n");
    for (int j = 0; j < n; ++j)
      printf(" %d", matrix[i][j]);
  }
  
  for (int i = 0; i < M; i++)
  {
    if (matrix[0][Q[i]+1] - matrix[0][P[i]]) { res.A[i] = 1; continue; }
    if (matrix[1][Q[i]+1] - matrix[1][P[i]]) { res.A[i] = 2; continue; }
    if (matrix[2][Q[i]+1] - matrix[2][P[i]]) { res.A[i] = 3; continue; }
    if (matrix[3][Q[i]+1] - matrix[3][P[i]]) { res.A[i] = 4; continue; }
  }

  return res;
}

int main(void)
{
  struct Results res;
  int P[] = {2, 5, 0};
  int Q[] = {4, 5, 6};
  char S[] = "CAGCCTA";
  int M = 3;
 
  res = solution(S, P, Q, M);
  
  printf("\n");
  for (int i = 0; i < res.M; ++i)
    printf(" %d", res.A[i]);

  return 0;
}