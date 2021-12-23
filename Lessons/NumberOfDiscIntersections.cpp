/*
Lesson 6 - Number of disk intersections

We draw N discs on a plane. The discs are numbered from 0 to N − 1. 
An array A of N non-negative integers, specifying the radiuses of the discs, is given. 
The J-th disc is drawn with its center at (J, 0) and radius A[J].

We say that the J-th disc and K-th disc intersect if J ≠ K and the J-th and K-th discs have at least one common point 
(assuming that the discs contain their borders).

The figure below shows discs drawn for N = 6 and A as follows:

A[0] = 1
A[1] = 5
A[2] = 2
A[3] = 1
A[4] = 4
A[5] = 0

There are eleven (unordered) pairs of discs that intersect, namely:

discs 1 and 4 intersect, and both intersect with all the other discs;
disc 2 also intersects with discs 0 and 3.

Write a function:

int solution(vector<int> &A);

that, given an array A describing N discs as explained above, returns the number of (unordered) pairs of intersecting discs. 
The function should return −1 if the number of intersecting pairs exceeds 10,000,000.

Given array A shown above, the function should return 11, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [0..2,147,483,647].
*/

#include<iostream>
#include<vector>

// 2021-11-30 //
// 100% grade //
/*
Intiially we calculate all start and end points of discs. 
After, go by all line and check count of discs inside current point. 
If in current point started some discs and intersection count increased by: 
    - already active discs multiplied by count of started in current point (result += t * dps[i]) and 
    - count of intersections of started (result += dps[i] * (dps[i] - 1) / 2) 
eg. if started 5 discs in one of point it will increased by (1+2+3+4+5 intersections, or 5*(5-1) / 2[sum formula]).

Basically, we are keeping track of the current "active" disks at each location. 
This is the value of t. 
Whenever a new disk starts at location i, it intersects with all existing disks at that location. 
That's why we have result += t * dps[i]. 
We also need to add the number of intersections for all the disks that just started at location i.
i.e. the number of intersections within themselves excluding whatever already existed (result += dps[i] * (dps[i] - 1) / 2)
*/

int solution_old(std::vector<int> &A)
{
    int sum = 0;
    int active = 0;
    size_t len = A.size();

    std::vector<int> start(len, 0);
    std::vector<int> end(len, 0);
    
    for (size_t i = 0; i < len; ++i)
    {
        if (i < A[i])
            start[0]++;
        else
            start[i-A[i]]++;
        
        if (i+A[i] >= len)
            end[len-1]++;
        else
            end[i+A[i]]++;
    }

    for (size_t i = 0; i < len; ++i)
    {
        sum += active * start[i] + (start[i]*(start[i]-1)) / 2;
        
        if (sum > 10000000) 
            return -1;
        active += start[i] - end[i];
    }

    return sum;
}

int solution(std::vector<int> &A) 
{
    // 81% grade - time complexity, I believe
    int size = (int)A.size();
    std::vector<long> a;

    for (int i = 0; i < size; i++) 
    {
        a.push_back(A[i]);
    }

    std::vector<long> left;
    std::vector<long> right;

    for (int i = 0; i < size; i++) 
    {
        left.push_back((i - a[i]));
        right.push_back((i + a[i]));
    }
    
    int res = 0;
    for (long i = 0; i < size - 1; i++) 
    {
        for (long j = i + 1; j < size; j++) 
        {
            if ((j - i <= a[i] + a[j]))
                 res++;
        }
    }
    
    return res;
}

int main(void)
{
    std::vector<int> A = { 1, 5, 2, 1, 4, 0 };
    std::cout << "Number of intersection pairs is: " << solution(A);

    return 0;
}