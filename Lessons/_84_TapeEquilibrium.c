/*

Lesson 3 - Tape Equilibrium

A non-empty array A consisting of N integers is given. Array A represents numbers on a tape.

Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].

The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|

In other words, it is the absolute difference between the sum of the first part and the sum of the second part.

For example, consider array A such that:

  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
We can split this tape in four places:

P = 1, difference = |3 − 10| = 7
P = 2, difference = |4 − 9| = 5
P = 3, difference = |6 − 7| = 1
P = 4, difference = |10 − 3| = 7
Write a function:

int solution(int A[], int N);

that, given a non-empty array A of N integers, returns the minimal difference that can be achieved.

For example, given:

  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
the function should return 1, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [2..100,000];
each element of array A is an integer within the range [−1,000..1,000].
*/

int solution(int A[], int N)
{
    // 84% - time complexity
  
    int sum1 = 0, sum2 = 0, diff = 0, min_diff = 1000000000;
    
    for (int i=1; i<N; i++) sum2 += A[i];
    sum1 = A[0];
    diff = (sum1 > sum2) ? (sum1 - sum2) : (sum2 - sum1);
    if (min_diff > diff) min_diff = diff;
    
    for (int i=1; i<N; i++)
    {
        sum1 += A[i];
        sum2 -= A[i];
        diff = (sum1 > sum2) ? (sum1 - sum2) : (sum2 - sum1);
        if (min_diff > diff) min_diff = diff;        
        
        // printf("\n-> sum1: %d sum2: %d diff: %d mindiff: %d", sum1, sum2, diff, min_diff);
    }
    
    return min_diff;
}