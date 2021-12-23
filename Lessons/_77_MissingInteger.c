/*
Lesson 4 - Missing Integer

This is a demo task.

Write a function:

int solution(int A[], int N);

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].
*/

int comp_f(const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b);
}

void print_array (int A[], int N)
{
    printf("\n[ ");
    for (int i=0; i<N; i++)
        printf("%d ", A[i]);
    printf("]\n");
}

int solution(int A[], int N)
{
// 77% - some specific cases 

    print_array(A, N);
    qsort(A, N, sizeof(int), comp_f);
    print_array(A, N);
    
    if (N==1)
    { 
        if (A[0] == 1) 
            return 2; 
        else 
            return 1;
    }
    int res = 1, middle = 0;
    
    if (A[N-1] <= 0) return 1;
    if (A[N-1] == 1) return 2;

    for (int i=0; i<N; i++)
        if (A[i] < 0) A[i] = 0;
    
    for (int i=0; i<N-1; i++)
    {
        if (A[i+1] - A[i] > 1)
        {
            res = A[i] + 1;
            middle = 1;
            break;
        }
        
    }
    
    if (middle)
        return (res<1) ? 1: res;
    else
        return (A[N-1]+1 < 1) ? 1 : A[N-1]+1;
}