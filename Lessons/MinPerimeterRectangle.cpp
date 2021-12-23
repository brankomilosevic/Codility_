/*
Lesson 10 - Min Perimeter Rectangle

An integer N is given, representing the area of some rectangle.

The area of a rectangle whose sides are of length A and B is A * B, and the perimeter is 2 * (A + B).

The goal is to find the minimal perimeter of any rectangle whose area equals N. The sides of this rectangle should be only integers.

For example, given integer N = 30, rectangles of area 30 are:

(1, 30), with a perimeter of 62,
(2, 15), with a perimeter of 34,
(3, 10), with a perimeter of 26,
(5, 6), with a perimeter of 22.
Write a function:

int solution(int N);

that, given an integer N, returns the minimal perimeter of any rectangle whose area is exactly equal to N.

For example, given an integer N = 30, the function should return 22, as explained above.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..1,000,000,000].

*/
#include<iostream>

int solution(int N)
{
// 100%
    int res = 2 + 2*N;
    int sqrt = 1;

    while (sqrt * sqrt <= N) ++sqrt;    // minimal perimeter of given area is of a sqare
    while (N % sqrt) --sqrt;            // if are can not be presented as square of int, then go down 1 by 1
    
    int A = sqrt;
    int B = N/A;
    return 2 * (A+B);
}

int main(void)
{
    int N = 1;
    std::cout << "Minimal perimetar of rectangle of area " << N << " is: " << solution(N);
}
