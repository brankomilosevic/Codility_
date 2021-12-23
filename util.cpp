/* some utilities... */

#include<iostream>
#include<vector>
#include<string>
using namespace std;

void counting_sort(vector<int> &A, int min, int max) 
{
    int offset = 0;
    if (min < 0)
        offset = -min;
    int size = max - min + 1;
    vector<int> count(size, 0);
    
    for(int i : A)
        count[i + offset] +=1;
        
    int p = 0;
    for(size_t j = 0; j<count.size(); j++)
    {
        for(int i=0; i<count[j]; i++)
            A[p++] = j - offset;
    }
}

void print_vector(vector<int> &A, string msg)
{
    cout << "\n>>> " << msg << ":\n[ ";
    for (int i=0; i<A.size(); ++i)
        cout << A[i] << " ";
    cout <<"]";
}

vector<uint64_t> getFactorial(int n) 
{
    vector<uint64_t> f(n+1, 0);
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        f[i] = f[i - 1] * i;
    return f;
}

vector<int> getFactArr(int n) 
{
    vector<int> f(n+1, 0);
    int i = 2;
    while (i * i <= n) {
        if (f[i] == 0) {
            int k = i * i;
            while (k <= n) {
                if (f[k] == 0)
                    f[k] = i;
                k+=i;
            }
        }
        i++;
    }
    return f;
}

vector<uint64_t> getFibonacciArray(size_t N) 
{
    vector<uint64_t> fib(N + 2, 0);
    fib[1] = 1;
    for (size_t i = 2; i <= N + 1; i++)
        fib[i] = fib[i - 1] + fib[i - 2];
    return fib;
}

int gcd(int a, int b, int res) 
{
// a fast one
    if (a == b)
        return res * a;
    else if ((a % 2 == 0) and (b % 2 == 0))
        return gcd(a / 2, b / 2, 2 * res);
    else if (a % 2 == 0)
        return gcd(a / 2, b, res);
    else if (b % 2 == 0)
        return gcd(a, b / 2, res);
    else if (a > b)
        return gcd(a - b, b, res);
    else
        return gcd(a, b - a, res);
}

int gcd(int a, int b) 
{
    return gcd(a, b, 1);
}

int gcdByDivision(int A, int B) 
{
// by division
    if (A % B == 0)
        return B;
    else
        return gcdByDivision(B, A % B);
}

vector<int> factorization(int x) 
{
    vector<int> primeFactors;
    vector<int> F = getFactArr(x);
    while (F[x] > 0) 
    {
        primeFactors.push_back(F[x]);
        x /= F[x];
    }
    primeFactors.push_back(x);
    
    return primeFactors;
}

pair<int,int> getLeader(vector<int> &A) 
{
// leader of array
    int candidate = -1;
    int size = 0;
    
    for(size_t i=0; i<A.size(); i++) 
    {
        if(size == 0) 
        {
            ++size;
            candidate = A[i];
        } 
        else 
        {
            if(candidate == A[i])
                ++size;
            else
                --size;
        }
    }
    
    if (size > 0)
    {
        size_t count = 0;
        for(size_t i=0; i<A.size(); ++i) 
        {
            if(A[i] == candidate)
                count++;
        }
        
        if (count > A.size() / 2) 
            return make_pair(candidate, count);
    }
    return make_pair(-1, 0);
}

int main (void)
{
    vector<int> A = { -1, -6, 3, 5, 2, 9, 9, 10 };
    
    print_vector(A, "Before sorting");
    counting_sort(A, -6, 10);
    print_vector(A, "After sorting");

    return 0;
}