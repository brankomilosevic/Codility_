/*

Lesson - 9

A non-empty array A consisting of N integers is given.

A triplet (X, Y, Z), such that 0 ≤ X < Y < Z < N, is called a double slice.

The sum of double slice (X, Y, Z) is the total of A[X + 1] + A[X + 2] + ... + A[Y − 1] + A[Y + 1] + A[Y + 2] + ... + A[Z − 1].

For example, array A such that:

    A[0] = 3
    A[1] = 2
    A[2] = 6
    A[3] = -1
    A[4] = 4
    A[5] = 5
    A[6] = -1
    A[7] = 2
contains the following example double slices:

double slice (0, 3, 6), sum is 2 + 6 + 4 + 5 = 17,
double slice (0, 3, 7), sum is 2 + 6 + 4 + 5 − 1 = 16,
double slice (3, 4, 5), sum is 0.
The goal is to find the maximal sum of any double slice.

Write a function:

int solution(vector<int> &A);

that, given a non-empty array A consisting of N integers, returns the maximal sum of any double slice.

For example, given:

    A[0] = 3
    A[1] = 2
    A[2] = 6
    A[3] = -1
    A[4] = 4
    A[5] = 5
    A[6] = -1
    A[7] = 2
the function should return 17, because no double slice of array A has a sum of greater than 17.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [3..100,000];
each element of array A is an integer within the range [−10,000..10,000].

*/

#include<iostream>
#include<vector>

using namespace std;

int max(int a, int b)
{
    if (a > b) 
        return a;
    return b;
}

int solution(vector<int> &A)
{
    int result = 0;
    int len = A.size();
    vector<int> front(len, 0);
    vector<int> back(len, 0);

    if (len < 3) return 0;

    // front array will contain max sum forwards at the position i (position 0 and len-1 are skipped because o double slice boundaries)
    for (int i=1; i<len-1; ++i)
    {
        front[i] = max(front[i-1] + A[i], 0);
    }

    // back array will contain max sum from backwards at the position i (position 0 and len-1 are skipped because o double slice boundaries)
    for (int i=len-2; i>0; --i)
    {
        back[i] = max(back[i+1] + A[i], 0);
    }

    // find the maximum of front and back at each location
    for (int i=1; i<len-1; ++i)
    {
        result = max(result, front[i-1] + back[i+1]);
    }

    return result;
}

int main(void)
{
    //vector<int> A = { 3, 2, 6, -1, 4, 5, -1, 2 };   // 17
    //vector<int> A = { -2 -3, 4, -1, -2, 1, 5, -3 }; // 9
    vector<int> A = { 1, 2, 3 };                    // 0       

    cout << "Maximal sum of any double slice is: " << solution(A);

    return 0;
}


/* 
    //start from i=1 because slice can't start at index 0
    for(int i = 1; i < A.length-1; i++) 
    { slice1LocalMax[i] = Math.max(slice1LocalMax[i-1] + A[i], 0); } 
    
    //start from i=A.length-2 because slice can't end at index A.length-1 
    for(int i = A.length-2; i > 0; i--)
    {
      slice2LocalMax[i] = Math.max(slice2LocalMax[i+1]+A[i], 0);
    }
   
    int maxDoubleSliceSum = 0;
   
    //compute sums of all slices to find absolute max
    for(int i = 1; i < A.length-1; i++) {
      maxDoubleSliceSum = Math.max(maxDoubleSliceSum, slice1LocalMax[i-1] + slice2LocalMax[i+1]);
    }
   
    return maxDoubleSliceSum;


    0
*/