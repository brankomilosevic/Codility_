/*

Lesson 8 - EquiLeader
A non-empty array A consisting of N integers is given.

The leader of this array is the value that occurs in more than half of the elements of A.

An equi leader is an index S such that 0 ≤ S < N − 1 and two sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N − 1] have leaders of the same value.

For example, given array A such that:

    A[0] = 4
    A[1] = 3
    A[2] = 4
    A[3] = 4
    A[4] = 4
    A[5] = 2
we can find two equi leaders:

0, because sequences: (4) and (3, 4, 4, 4, 2) have the same leader, whose value is 4.
2, because sequences: (4, 3, 4) and (4, 4, 2) have the same leader, whose value is 4.
The goal is to count the number of equi leaders.

Write a function:

int solution(int A[], int N);

that, given a non-empty array A consisting of N integers, returns the number of equi leaders.

For example, given:

    A[0] = 4
    A[1] = 3
    A[2] = 4
    A[3] = 4
    A[4] = 4
    A[5] = 2
the function should return 2, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int Dominator(vector<int> &A, size_t start, size_t end)
{
// 100%
    size_t len = end-start+1;
    stack<int> S;
    for (size_t i=start; i<=end; ++i)
    {
        if (S.empty())
        {
            S.push(A[i]);
        }
        else
        {
            if (S.top() == A[i])
                S.push(A[i]);
            else
                S.pop();
        }
    }

    if (S.empty()) return -1;

    size_t count = 0;
    int index = -1;
    int candidate = S.top();
    for (size_t i=start; i<=end; ++i)
    {
        if (A[i] == candidate) 
        {
            count++;
            index = i;
        }
    }
    
    if (count > len/2) return index;

    return -1;
}

int solution_old(vector<int> &A)
{
// 55% - time complexity !!!
    int count = 0;
    int len = A.size();
    if (len < 2) return 0;
    int beg, end;
    int Dom_1, Dom_2;

    for (size_t i=0; i<len-1; ++i)
    {
        beg = 0;
        end = i;
        Dom_1 = Dominator(A, beg, end);
        beg = i+1;
        end = len-1;
        Dom_2 = Dominator(A, beg, end);

        if ( (Dom_1 != -1) && (Dom_2 != -1) && (A[Dom_1] == A[Dom_2]) ) 
            ++count;
    }

    return count;
}

int solution(vector<int> A)
{
    int count = 0;
    int len = A.size();
    if (len < 2) return 0;

    // find the dominator of whole array
    int index = Dominator(A, 0, len-1);
    int dominator = 0;
    if (index == -1)
        return 0;
    else
        dominator = A[index];

    // going throught the vector, count the number of dominators at index i
    vector<int> dominators(len, 0);
    int dom_count = 0;
    for (int i=0; i<len; ++i)
    {
        if (A[i] == dominator)
            dom_count++;
        dominators[i] = dom_count;
    }
    // once again, going through the array and compare the number of dominators before and after the index
    int left = 0;
    int right = 0;
    for (int i=0; i<len-1; ++i)
    {
        left = dominators[i];
        right = dominators[len-1] - dominators[i];
        if (left > (i+1)/2) 
            if (right > (len-i-1)/2)
                ++count;
    }

    return count;
}

int main(void)
{
    // vector<int> A = { 4, 3, 4, 4, 4, 2 }; // 2
    // vector<int> A = { 1, 5, 1, 5, 5, 5, 5, 5 }; // 3
    // vector<int> A = { 1, 1, 1, 1, 1, 1 }; // 5
    // vector<int> A = { 4, 4, 2, 5, 3, 4, 4, 4 }; // 3
     
    // vector<int> A = { 1, 2, 3  }; // 0
    // vector<int> A = { 1000000000 }; // 0
    // vector<int> A = { 1000, 1  }; // 0
    // vector<int> A = { 0, 0  }; // 1    

    cout << "Number of equi leaders is: " << solution(A);
}