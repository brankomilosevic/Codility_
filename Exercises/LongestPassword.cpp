/*
You would like to set a password for a bank account. However, there are three restrictions on the format of the password:

it has to contain only alphanumerical characters (a−z, A−Z, 0−9);
there should be an even number of letters;
there should be an odd number of digits.

You are given a string S consisting of N characters. 
String S can be divided into words by splitting it at, and removing, the spaces. 
The goal is to choose the longest word that is a valid password. 
You can assume that if there are K spaces in string S then there are exactly K + 1 words.

For example, given "test 5 a0A pass007 ?xy1", there are five words and three of them are valid passwords: "5", "a0A" and "pass007". 
Thus the longest password is "pass007" and its length is 7. 
Note that neither "test" nor "?xy1" is a valid password, because "?" is not an alphanumerical character and "test" contains an even number of digits (zero).

Write a function:

int solution(string &S);

that, given a non-empty string S consisting of N characters, returns the length of the longest word from the string that is a valid password. 
If there is no such word, your function should return −1.

For example, given S = "test 5 a0A pass007 ?xy1", your function should return 7, as explained above.

Assume that:

N is an integer within the range [1..200];
string S consists only of printable ASCII characters and spaces.
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.
*/

// 2021-11-26 //
// 100% grade //

#include<iostream>
#include<string>
#include<vector>
#include<string.h>

using namespace std;

vector<string> split(const char *str, char c = ' ')
{
    vector<string> result;

    do
    {
        const char *begin = str;

        while(*str != c && *str)
            str++;

        result.push_back(string(begin, str));
    } while (0 != *str++);

    return result;
}

int size_of_pass(const char *s)
{
    int res = -1;
    int let = 0;
    int dig = 0;
    int len = strlen(s);

    for (int i = 0; i < len; ++i)
    {
        if ( isalnum(s[i]) ) 
        {
            if ( isdigit(s[i]) ) ++dig;
            if ( isalpha(s[i]) ) ++let;
        }
        else
        {
            return -1;
        }
    }
    
    if ( let % 2) return -1;
    if ( dig % 2 == 0 ) return -1;

    return len;
}

int solution(string &S)
{
    vector<string> tokens = split(S.c_str());
    int res = -1;

    for (auto &str : tokens)
    {
        int size = size_of_pass(str.c_str());
        cout << str << ": " << size << "\n";
        if ( size != -1 && res < size )
            res = size;
    }

    return res;
}

int main(void)
{
    string S = "test 5 a0A pass007 ?xy1";
    // string S = "test";

    cout << "\nMax pass is " << solution(S) << " long.";

    return 0;
}