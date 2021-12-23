/*

Lesson 8 - Dominator

An array A consisting of N integers is given. The dominator of array A is the value that occurs in more than half of the elements of A.

For example, consider array A such that

 A[0] = 3    A[1] = 4    A[2] =  3
 A[3] = 2    A[4] = 3    A[5] = -1
 A[6] = 3    A[7] = 3
The dominator of A is 3 because it occurs in 5 out of 8 elements of A (namely in those with indices 0, 2, 4, 6 and 7) and 5 is more than a half of 8.

Write a function

int solution(vector<int> &A);

that, given an array A consisting of N integers, returns index of any element of array A in which the dominator of A occurs. 
The function should return −1 if array A does not have a dominator.

For example, given array A such that

 A[0] = 3    A[1] = 4    A[2] =  3
 A[3] = 2    A[4] = 3    A[5] = -1
 A[6] = 3    A[7] = 3
the function may return 0, 2, 4, 6 or 7, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
using namespace std;

int solution_old(vector<int> &A)
{
    int index = -1;
    size_t max = 0;
    if (A.size() == 0) return -1;
    if (A.size() == 1) return 0;
    if (A.size() == 2) return (A[0] == A[1]) ? 0: -1;

    sort(A.begin(), A.end());


    for (size_t i=0; i<A.size(); )
    {
        size_t l = 0;
        while (A[i] == A[i+l]) l++;

        if (max < l)   
        { 
            max = l; 
            index = i; 
        }
        i += l;
    }

    if (max > A.size() / 2) 
        return index;

    return -1;
}

int solution(vector<int> &A)
{
// 100%
    size_t len = A.size();
    stack<int> S;
    for (size_t i = 0; i < len; ++i)
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

    // cout << "stack top : " << S.top(); 

    size_t count = 0;
    int index = -1;
    int candidate = S.top();
    for (size_t i=0; i<len; ++i)
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

int solution_another_one(vector<int> &A) 
{
    // write your code in C++14 (g++ 6.2.0)
    int size = (int)A.size(), maxV = INT_MIN, maxIndex = -1;
    if (size == 0) return -1;
    
    map<int, int> m;
    
    for (int i = 0; i < size; i++) 
    {
        if (m.find(A[i]) == m.end()) 
            m[A[i]] = 1;
        else
            m[A[i]]++;
        
        if (m[A[i]] > maxV) 
        {
            maxV = m[A[i]];
            maxIndex = i;
        }
    }
    
    
    return m[A[maxIndex]] > size / 2 ? maxIndex : -1;
}

int main(void)
{
    // vector<int> A = { 3, 4,3, 2, 3, -1, 3, 3 }; 
    // vector <int> A = { 2, 1, 1, 3 };
    vector<int> A = { 0, 0, 1, 1, 1 };
    // vector<int> A = { 2, 1, 1, 1, 3 };
    
    int index = solution(A);
    if (index != -1)
        cout << "\n\nDominator is : " << A[index];
    else
        cout << "\n\nThere is no Dominator";
    return 0;
}