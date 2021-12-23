/*
Write a function:

int solution(string &S);

that, given a string S, returns the index (counting from 0) of a character such that the part of the string to the left of that character is a 
reversal of the part of the string to its right. The function should return −1 if no such index exists.

Note: reversing an empty string (i.e. a string whose length is zero) gives an empty string.

For example, given a string:

"racecar"

the function should return 3, because the substring to the left of the character "e" at index 3 is "rac", and the one to the right is "car".

Given a string:

"x"

the function should return 0, because both substrings are empty.

Write an efficient algorithm for the following assumptions:

the length of S is within the range [0..2,000,000].
*/

// 2021-11-29 //
// 100% grade //s

#include<iostream>
#include<string>
using namespace std;

int solution(string &S)
{
    int res = -1;
    int len = S.size();

    if (len == 0) return -1;
    if (len == 1) return 0;
    if (len % 2 == 0) return -1;

    int mid = len / 2;

    for (int i = 0; i < mid ; ++i)
    {
        if (S[i] != S[len - i - 1]) return -1;
    }

    return mid;   
}

int main(void)
{
    string S = "racecarar";

    cout << "The index of sy etry point is: " << solution(S);

    return 0;
}