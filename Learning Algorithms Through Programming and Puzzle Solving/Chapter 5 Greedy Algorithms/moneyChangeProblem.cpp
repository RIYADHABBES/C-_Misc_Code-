// C++ program to calculate
// last digit of the sum of the
// fibonacci numbers from M to N
#include<bits/stdc++.h>
using namespace std;

/*
 *  Exercice in thebook : "Learning Algorithms Through Programming and Puzzle Solving"
 *
 *  Page: 66
 *  Year: 2018
 *
 *  Money change problem
 *
 *  example :
 *
 *      Inputs : n = 28
 *
 *      n = 28 = 10 + 10 + 5 + 1 + 1 + 1
 *              |_______________________|
 *                         |
 *                         -------------------> 6
 *                                              ^
 *                                              |
 *      Output ----------------------------------
 *
 *
*/

struct Change{
    int m_tens = 0;
    int m_fives = 0;
    int m_ones = 0;
    int m_numberOfAllCoins = 0;
    Change(){};
    Change(int tens, int fives, int ones, int numberOfAllCoins):m_tens{tens},m_fives{fives}, m_ones{ones},m_numberOfAllCoins{numberOfAllCoins}{};
};

Change coins(int n)
{
    if(n > 0)
    {
    Change change;
    change.m_tens = ((n - (n % 10)) / 10);

    n = n % 10;

    change.m_fives = ((n - (n % 5)) / 5);

    change.m_ones = n % 5;

    change.m_numberOfAllCoins = change.m_ones + change.m_fives + change.m_tens;

    return change;
    }
    if(n == 0)
        return Change(0, 0, 0, 0);
    return Change(0 , 0 , 0 , -1);
}

int main()
{
    int n = 28;
    Change change = coins(n);

    std::cout << "The change of " << n
              << " is:\n Tens  " << change.m_tens
              << " \n Fives " << change.m_fives
              << " \n Ones  " << change.m_ones
              << " \n Number of all coins is " << change.m_numberOfAllCoins
              << std::endl;
}
