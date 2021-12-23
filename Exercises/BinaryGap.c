/*
Lesson 1 - Binary Gap
A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap of length 2. 
The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. 
The number 20 has binary representation 10100 and contains one binary gap of length 1. 
The number 15 has binary representation 1111 and has no binary gaps. 
The number 32 has binary representation 100000 and has no binary gaps.

Write a function:

int solution(int N);

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. 
Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..2,147,483,647].
*/

// 2021-11-29 //
// 100% grade //

#include <stdio.h>

int solution(int N)
{
    unsigned n = (unsigned) N;
    int gap = 0;
    if (N == 0) return 0;
    int size = 8*sizeof(n);
    int arr[size];
    unsigned i = 0, mask = 1;
    
    for (i = 0; i < size; i++) 
    {
        arr[i] = !!(n & mask);
        mask = mask << 1;
    }
    
    printf("-->"); 
    for (i = 0; i < size; i++) printf("%d", arr[i]);
    
    int start = -1, stop = -1, has_end, j, local = -1; 
    
    for (i = 0; i < size-1; i++)
    {
        has_end = 0;
        if (arr[i])
        {
            start = i;
            j=i+1;
            while (!arr[j]) 
            {
                j++;
                if (j >= size) 
                {
                    has_end = 1;
                    break;
                }
            }
            stop = j;
        }
        printf("\n-->%d %d", start, stop);
        if (has_end) break;
        if (stop > start) local = stop - start - 1; 
        printf("--> local gap: %d", local);
        if (gap < local) gap = local;
    }
    
    return gap;
}

int main(void)
{
    int n;

    printf("Enter number: ");
    scanf("%d", &n);

    printf("\nLongest binary gap is: %d\n", solution(n));

    return 0;
}