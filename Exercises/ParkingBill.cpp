/*
You parked your car in a parking lot and want to compute the total cost of the ticket. The billing rules are as follows:

The entrance fee of the car parking lot is 2;
The first full or partial hour costs 3;
Each successive full or partial hour (after the first) costs 4.
You entered the car parking lot at time E and left at time L. 

In this task, times are represented as strings in the format "HH:MM" 
(where "HH" is a two-digit number between 0 and 23, which stands for hours, and "MM" is a two-digit number between 0 and 59, which stands for minutes).

Write a function:

class Solution { public int solution(String E, String L); }

that, given strings E and L specifying points in time in the format "HH:MM", 
returns the total cost of the parking bill from your entry at time E to your exit at time L. You can assume that E describes a time before L on the same day.

For example, given "10:00" and "13:21" your function should return 17, 
because the entrance fee equals 2, 
the first hour costs 3 and 
there are 2 more full hours and part of a further hour, 
so the total cost is 2 + 3 + (3 * 4) = 17. 

Given "09:42" and "11:42" your function should return 9, 
because the entrance fee equals 2, 
the first hour costs 3 and the 
second hour costs 4, 
so the total cost is 2 + 3 + 4 = 9.

Assume that:

strings E and L follow the format "HH:MM" strictly;
string E describes a time before L on the same day.
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.
*/

// 2021-11-29 //
// 100% grade //

#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int solution(string E, string L)
{
    int res = 0 ;
    int entrance = 2;
    int first = 3;
    int after = 4;
    int min_total = 0;

    int h1, h2, m1, m2;
    sscanf(E.c_str(), "%d:%d", &h1, &m1);
    sscanf(L.c_str(), "%d:%d", &h2, &m2);

    // cout << "\nEnter at " << h1 << " hours and " << m1 << " minutes";
    // cout << "\nLeave at " << h2 << " hours and " << m2 << " minutes";

    min_total = (h2 - h1)*60 + (m2 - m1);
    // cout << "\n->Total minutes: " << min_total;

    if (min_total <= 60) res = first;
    if (min_total > 60) 
    {
        if (min_total % 60)
        {
            res = first + after*(min_total/60);
        }
        else
        {
            res = first + after*(min_total/60 - 1);
        }
    }
    return res + entrance;
}

int main(void)
{
    string E = "09:42";
    string L = "11:42";

    cout << "\nParking cost is: " << solution(E, L);
    return 0;
}