/*
Excersise 5

Write a function solution that, given two integers A and B, 
returns a string containing exactly A letters 'a' and exactly B letters 'b' 
with no three consecutive letters being the same 
(in other words, neither "aaa" nor "bbb" may occur in the returned string).

Examples:

1. Given A = 5 and B = 3, your function may return "aabaabab". 
Note that "abaabbaa" would also be a correct answer. 
Your function may return any correct answer.

2. Given A = 3 and B = 3, your function should return "ababab", "aababb", "abaabb" 
or any of several other strings.

3. Given A = 1 and B = 4, your function should return "bbabb", 
which is the only correct answer in this case.

Assume that:

A and B are integers within the range [0..100];
at least one solution exists for the given A and B.
In your solution, focus on correctness. 
The performance of your solution will not be the focus of the assessment.
*/

#include<iostream>
#include<stdlib.h>

// 2021-12-17
// 100% grade on codility
char * solution(int A, int B)
{
    char *str = (char *)malloc((A+B+1) * sizeof(char));

    int len = A + B;
    int index = 0;
    char c = 0;
    int rep_a = 0, rep_b = 0;

    while (index < len)
    {
        if ( A > B )
        {
            if (rep_a < 2)
            {
                c = 'a';
                --A;
                ++rep_a;
                rep_b = 0;
            }
            else
            {
                c = 'b';
                --B;
                rep_a = 0;
            }
        }
        else
        {
            if (rep_b < 2)
            {
                c = 'b';
                --B; 
                ++rep_b;
                rep_a = 0;
            }
            else
            {
                c = 'a';
                --A;
                rep_b = 0;
            }
        }
        str[index] = c;
        ++index;
    }
    
    str[len] = 0;
    return str;
}

int main(void)
{
    int A = 1; // 5, 3, 1
    int B = 4; // 3, 3, 4

    char *str = solution(A, B);
    std::cout << "String is:\n[" << str << "]\n\n";

    return 0;
}
