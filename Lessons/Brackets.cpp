/*
Lesson 7 - Brackets

A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:

S is empty;
S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
S has the form "VW" where V and W are properly nested strings.
For example, the string "{[()()]}" is properly nested but "([)()]" is not.

Write a function:

int solution(char *S);

that, given a string S consisting of N characters, returns 1 if S is properly nested and 0 otherwise.

For example, given S = "{[()()]}", the function should return 1 and given S = "([)()]", the function should return 0, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [0..200,000];
string S consists only of the following characters: "(", "{", "[", "]", "}" and/or ")".
*/

#include<iostream>
#include<stack>
#include<map>

using namespace std;
 
// function to check if brackets are balanced
int solution (string expr)
{
// 100%     
    stack<char> s;
    char x;
 
    for (size_t i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
        {
            s.push(expr[i]);
            continue;
        }
 
        // If current current character is not opening bracket, then it must be closing. 
        if (s.empty())
            return false;
 
        switch (expr[i]) 
        {
        // store the top element
        case ')':
            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;
        case '}':
            x = s.top();
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;
        case ']':
            x = s.top();
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }
 
    return (s.empty());
}

// another one using map...
bool correct_paranthesis(string str)
{
	stack<char> stk;
	map<char,char> bracket_map;
	bracket_map[')'] = '(';
	bracket_map['}'] = '{';
	bracket_map[']'] = '[';
	
	for(size_t i = 0; i < str.size(); ++i)
    {
		if(str[i] == '(' || str[i] == '{' || str[i] == '[')
			stk.push(str[i]);
		
        if(str[i] == ')' || str[i] == '}' || str[i] == ']')
        {
			if(stk.empty())
				return false;
			if(stk.top() == bracket_map[str[i]] )
				stk.pop();
		}
	}
	
	return (stk.empty() == true);
}
int main()
{
    string expr = "{()}[]";
    cout << expr;
    if (solution(expr))
        cout << " : Balanced";
    else
        cout << " : Not Balanced";
    return 0;
}