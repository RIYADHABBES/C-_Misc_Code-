#include <iostream>

using namespace std;

/*
 *  Exercice in thebook : "Learning Algorithms Through Programming and Puzzle Solving"
 *
 *  Page: 56
 *  Year: 2018
 *
 *  Compute the last digit of the n-th Fibonacci number
 *
 *  example :
 *
 *      F_170 = 150 804 340 016 807 970 735 635 273 952 047 185
 *                                                            v
 *                                    The output = 5 _________|
*/

int fibonacciLastDigit(const int n)
{
    int a_1 = 1;
    int a_2 = 0;
    int fib{0};
    for(int i = 2; i <= n ; ++i)
    {
        fib = (a_1 + a_2) % 10;
        a_2 = a_1;
        a_1 = fib;
    }
    return fib;
}
int main()
{
    int n = 139, f2 = fibonacciLastDigit(n);

    cout << "Last digit of Fibonnaci number : " << "F_" << n << " = " << f2 << endl;

    return 0;
}
