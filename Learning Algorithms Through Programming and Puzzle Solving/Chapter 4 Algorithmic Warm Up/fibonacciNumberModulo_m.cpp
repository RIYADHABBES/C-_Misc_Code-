// C++ program to calculate
// Fibonacci no. modulo m using
// Pisano Period
#include <bits/stdc++.h>
using namespace std;

/*
 *  Exercice in thebook : "Learning Algorithms Through Programming and Puzzle Solving"
 *
 *  Page: 60
 *  Year: 2018
 *
 *  Compute the n-th Fibonacci number modulo m
 *
 *  example :
 *
 *      Inputs : n = 2816213588     m = 30524
 *                                                            v
 *      Output = 10249
*/

// The code is copied from geeksforgeeks : https://www.geeksforgeeks.org/fibonacci-number-modulo-m-and-pisano-period/

// Calculate and return Pisano Period
// The length of a Pisano Period for
// a given m ranges from 3 to m * m
long long pisano(long long m)
{
    long long prev = 0;
    long long curr = 1;
    long long res = 0;

    for(int i = 0; i < m * m; i++)
    {
        long long temp = 0;
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;

        if (prev == 0 && curr == 1)
            res = i + 1;
    }
    return res;
}

// Calculate Fn mod m
long long fibonacciModulo(long long n, long long m)
{

    // Getting the period
    long long pisanoPeriod = pisano(m);

    n = n % pisanoPeriod;

    long long prev = 0;
    long long curr = 1;

    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;

    for(int i = 0; i < n - 1; i++)
    {
        long long temp = 0;
        temp = curr;
        curr = (prev + curr) % m;
        prev = temp;
    }
    return curr % m;
}

// Driver Code
int main()
{
    long long n = 2816213588;
    long long m = 30524;

    cout << "The Fibonnacci_" << n << " Modulo " << m << " is = " << (fibonacciModulo(n, m)) << endl;
    return 0;
}

// This code is contributed by subhammahato348
