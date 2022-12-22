// C++ program to calculate
// last digit of the sum of the
// fibonacci numbers from M to N
#include<bits/stdc++.h>
using namespace std;

/*
 *  Exercice in thebook : "Learning Algorithms Through Programming and Puzzle Solving"
 *
 *  Page: 60
 *  Year: 2018
 *
 *  Compute the last digit of F_m + F_m+1 + ... + F_n
 *
 *  example :
 *
 *      Inputs : n = 100     m = 0
 *
 *      F_0 + F_1 + ... + F_100 = 927 372 692 193 078 999 175
 *                                                          ^
 *                                                          |
 *      Output ----------------------------------------------
 *
 *
*/

// The code is copied from geeksforgeeks : https://www.geeksforgeeks.org/last-digit-of-sum-of-numbers-in-the-given-range-in-the-fibonacci-series/



// Calculate the sum of the first
// N Fibonacci numbers using Pisano
// period
long long fib(long long n)
{

    // The first two Fibonacci numbers
    long long f0 = 0;
    long long f1 = 1;

    // Base case
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    else
    {
        // Pisano period for % 10 is 60
        long long rem = n % 60;

        // Checking the remainder
        if(rem == 0)
           return 0;

        // The loop will range from 2 to
        // two terms after the remainder
        for(long long i = 2; i < rem + 3; i++)
        {
           long long f = (f0 + f1) % 60;
           f0 = f1;
           f1 = f;
        }

        long long s = f1 - 1;
        return s;
    }
}

// Driver Code
int main()
{
    long long m = 0;
    long long n = 100;

    long long final = abs(fib(n) - fib(m - 1));
    cout << final % 10 << endl;
}

// This code is contributed by Bhupendra_Singh
