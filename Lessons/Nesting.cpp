/*
Lesson 7 - Nesting

A string S consisting of N characters is called properly nested if:

S is empty;
S has the form "(U)" where U is a properly nested string;
S has the form "VW" where V and W are properly nested strings.
For example, string "(()(())())" is properly nested but string "())" isn't.

Write a function:

int solution(string &S);

that, given a string S consisting of N characters, returns 1 if string S is properly nested and 0 otherwise.

For example, given S = "(()(())())", the function should return 1 and given S = "())", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..1,000,000];
string S consists only of the characters "(" and/or ")".
*/
#include<iostream>
#include<stack>
#include<string>
using namespace std;

int solution_old(string S)
{
// 87% 
// problem with string S = "()(()()(((()())(()()))"
    stack<char> s;
    if (S.length() == 0) return 1;
    if (S.length() % 2) return 0;
    if (S[0] == ')') return 0;
    
    for (size_t i=0; i<S.length(); ++i)
    {
        if (S[i] == '(')
        {
            s.push('(');
        }

        if (s.empty()) return 0;

        if (S[i] == ')')
        {
            s.pop();
        }
    }

    return !S.empty();
}

int solution(string S)
{
// 100% - not using stack !!!, just counting
    int res = 0;
    for (size_t i = 0; i < S.length(); ++i)
    {
        if (S[i] == ')') --res;
        if (res < 0) return 0;
        if (S[i] == '(') ++res;
    }
    return !res;
}

int main(void)
{
    string S = "(()(())())";
    // string S = "())";
    // string S = "()(()()(((()())(()()))";
    cout << S;
    if (solution(S))
        cout << " : Balanced\n";
    else
        cout << " : NOT Balanced\n";
    return 0;
}
