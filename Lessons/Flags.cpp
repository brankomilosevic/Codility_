/*
Lesson 10 - Flags

A non-empty array A consisting of N integers is given.

A peak is an array element which is larger than its neighbours. More precisely, it is an index P such that 0 < P < N − 1 and A[P − 1] < A[P] > A[P + 1].

For example, the following array A:

    A[0] = 1
    A[1] = 5
    A[2] = 3
    A[3] = 4
    A[4] = 3
    A[5] = 4
    A[6] = 1
    A[7] = 2
    A[8] = 3
    A[9] = 4
    A[10] = 6
    A[11] = 2
has exactly four peaks: elements 1, 3, 5 and 10.

You are going on a trip to a range of mountains whose relative heights are represented by array A, as shown in a figure below. You have to choose how many flags you should take with you. The goal is to set the maximum number of flags on the peaks, according to certain rules.



Flags can only be set on peaks. What's more, if you take K flags, then the distance between any two flags should be greater than or equal to K. The distance between indices P and Q is the absolute value |P − Q|.

For example, given the mountain range represented by array A, above, with N = 12, if you take:

two flags, you can set them on peaks 1 and 5;
three flags, you can set them on peaks 1, 5 and 10;
four flags, you can set only three flags, on peaks 1, 5 and 10.
You can therefore set a maximum of three flags in this case.

Write a function:

int solution(vector<int> &A);

that, given a non-empty array A of N integers, returns the maximum number of flags that can be set on the peaks of the array.

For example, the following array A:

    A[0] = 1
    A[1] = 5
    A[2] = 3
    A[3] = 4
    A[4] = 3
    A[5] = 4
    A[6] = 1
    A[7] = 2
    A[8] = 3
    A[9] = 4
    A[10] = 6
    A[11] = 2
the function should return 3, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..400,000];
each element of array A is an integer within the range [0..1,000,000,000].

*/

/**
The result can be found by bisection. If we know that x flags can be set, then we also know that
x−1, x−2, . . . , 1 flags can be set. Otherwise, if x flags cannot be set, then x+1, x+2, . . . , √N
flags cannot be set either. 

Using bisection we can reduce the problem to checking whether x flags can be set. 
Notice that we can always greedily set a flag on the first peak.
*/

#include<iostream>
#include<vector>

using namespace std;

// build the vector of peeks
vector<int> find_peeks(vector<int> &A)
{
    int len = A.size();;
    vector<int>peeks(len, 0);

    for (int i=1; i<len-1; ++i)
        if (A[i] > A[i-1] && A[i] > A[i+1])
            peeks[i] = 1;

    // cout << "\nTerrain:\n";
    // for (int i=0; i<len; ++i) cout << A[i] << " ";

    return peeks;
}

// check if x flags can be put on the terrain
int check_flags(vector<int> A, int x)
{
    int len = A.size();
    vector<int> peeks = find_peeks(A);
    // cout << "\nPeeks:\n";
    // for (int i=0; i<len; ++i) cout << peeks[i] << " ";    
    int flags = x;
    int pos = 0;

    while ( pos < len && flags > 0 )
    {
        if (peeks[pos])
        {
            pos += x;
            --flags;
        }
        else
        {
            ++pos;
        }
    }

    return flags == 0;
}

int solution(vector<int> &A)
{
    int len = A.size();
    int flags = 0;
    // cout << "Can we put " << flags << " flags: " << check_flags(A, flags) << "\n";
    
    // this one is time consuming, not good for large inputs
    // while (check_flags(A, flags))
    //     ++flags;
    
    // in this one we go bisecting, Log(N) instead of N
    int left = 0;
    int right = len;
    flags = left + (right - left) / 2;
    while (left < right)
    {
        if (check_flags(A, flags) && !check_flags(A, flags+1))
            break;
        
        if (check_flags(A, flags))
            left = flags;
        else
            right = flags;

        flags = left + (right - left) / 2;
    }

    return flags;
}

int main(void)
{
    vector<int> A(12, 0);
    A[0] = 1;
    A[1] = 5;
    A[2] = 3;
    A[3] = 4;
    A[4] = 3;
    A[5] = 4;
    A[6] = 1;
    A[7] = 2;
    A[8] = 3;
    A[9] = 4;
    A[10] = 6;
    A[11] = 2;

    cout << "\nMaximum number of flags that can be put is: " << solution(A);
    return 0;
}

/*
class Solution {
    public int solution(int[] A) {
        if(A.length==1)  return 0;
        ArrayList<Integer> al=new ArrayList<Integer>();
        for(int i=1;i<A.length-1;i++)
        {
          if(A[i]>A[i-1] && A[i]>A[i+1])
          {
             al.add(i);
          }
        }
        int s=al.size();
        if(s==1) return 1;
        if(s==0)return 0;
        s=(int) Math.ceil(Math.sqrt(A.length));
        while(s>=0) {
            int lp=al.get(0);
            int c=1;
            for(int i=1;i<al.size();i++)
            {
                int d=Math.abs(al.get(i)-lp);
                if(d>=s)
                {
                    lp=al.get(i);
                    c++;
                    if(c==s)
                        return c;
                }
            }
            s--;}
        return 0;}
}
*/
