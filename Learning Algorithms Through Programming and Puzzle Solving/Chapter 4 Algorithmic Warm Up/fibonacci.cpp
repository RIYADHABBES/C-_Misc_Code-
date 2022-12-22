#include <iostream>
#include <chrono>

using namespace std;

/*
 *  Exercice in thebook : "Learning Algorithms Through Programming and Puzzle Solving"
 *
 *  Page: 54
 *  Year: 2018
 *
 *  I wrote two algorithms to test the runtime when i use a recursion face to when i use only a loop that saves the previous calculation.
 *
*/

int fibonacciRecursive(const int n)
{
    if(n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive( n - 2);
}

int fibonacci(const int n)
{
    int a_1 = 1;
    int a_2 = 0;
    int fib{0};
    for(int i = 2; i <= n ; ++i)
    {
        fib = a_1 + a_2;
        a_2 = a_1;
        a_1 = fib;
    }
    return fib;
}
int main()
{
    cout << "Hello World!" << endl;

    std::chrono::steady_clock::time_point begin1 = std::chrono::steady_clock::now();
    int f1 = fibonacciRecursive(10);
    std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();

    std::chrono::steady_clock::time_point begin2 = std::chrono::steady_clock::now();
    int f2 = fibonacci(10);
    std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();

     cout << "Fibonnaci Recursive: " << f1 << endl;
     cout << "Fibonnaci Normal: " << f2 << endl;

    std::cout << "Time difference 1 = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1).count() * 10e-9 << "[s]" << std::endl;
    std::cout << "Time difference 2 = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2).count() * 10e-9 << "[s]" << std::endl;

    return 0;
}
