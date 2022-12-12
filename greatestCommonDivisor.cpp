#include <iostream>

using namespace std;

/*
 *  Exercice in thebook : "Learning Algorithms Through Programming and Puzzle Solving"
 *
 *  Page: 58
 *  Year: 2018
 *
 *  Compute the greatest common divisor
 *
 *  example :
 *
 *      Inputs : a = 28851538     b = 1183019
 *                                                            v
 *      Output = 17657
*/

int itS = 0, itD = 0;

int gcdBySubstraction(int a, int b)
{
    int r = a > b ? a : b;

    if(a == 0 || b == 0)
        return -1;
    while(a != b)
    {
        if(a < b)
        {
            int z = a;
            a = b;
            b = z;
        }
        r = a - b;
        a = b;
        b = r;
        itS++;
    }
    return r;
}

int gcdByDivision(int a, int b)
{
    int r = a > b ? a : b;

    if(a == 0 || b == 0)
        return -1;
    while(r != 0)
    {
        if(a < b)
        {
            int z = a;
            a = b;
            b = z;
        }
        r = a % b;
        a = b;
        b = r;
        itD++;
    }
    return a;
}

int main()
{
    int a = 28851538, b = 1183019, gcdS = gcdBySubstraction(a,b), gcdD = gcdByDivision( a,  b);

    cout << "The greatest commun devider by substraction between " << a << " and " << b <<" is " << gcdS << " with " << itS << " iterations" << endl;

    cout << "The greatest commun devider by Division between " << a << " and " << b <<" is " << gcdD << " with " << itD << " iterations" << endl;

    return 0;
}
