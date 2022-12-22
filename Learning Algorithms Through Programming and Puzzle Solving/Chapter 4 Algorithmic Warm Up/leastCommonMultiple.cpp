#include <iostream>

using namespace std;

/*
 *  Exercice in thebook : "Learning Algorithms Through Programming and Puzzle Solving"
 *
 *  Page: 59
 *  Year: 2018
 *
 *  Compute the least common multiple
 *
 *  example :
 *
 *      Inputs : a = 28851538     b = 1183019
 *                                                            v
 *      Output = 1933053046
*/

struct Result{
    int64_t m_result;
    int m_iterations;

    Result(int64_t result,int iterations): m_result{result},m_iterations{iterations}{};
};



Result gcdByDivision(int64_t a, int64_t b)
{
    int64_t r = a > b ? a : b;
    int itD = 0;

    if(a == 0 || b == 0)
        return Result(-1, -1);
    while(r != 0)
    {
        if(a < b)
        {
            int64_t z = a;
            a = b;
            b = z;
        }
        r = a % b;
        a = b;
        b = r;
        itD++;
    }
    return Result(a, itD);
}

Result lcmBygcd(int64_t a, int64_t b)
{
    Result result = gcdByDivision(a,b);
    return  Result(a * b / result.m_result, result.m_iterations);
}

int main()
{
    int64_t a = 28851538, b = 1183019;
    Result gcdD = gcdByDivision( a,  b), lcmGCD = lcmBygcd(a,b);

    cout << "The greatest common devider by Division between " << a << " and " << b <<" is " << gcdD.m_result << " with " << gcdD.m_iterations << " iterations" << endl;

    cout << "\nThe Least common multiple by GCD between " << a << " and " << b <<" is " << lcmGCD.m_result << " with " << lcmGCD.m_iterations << " iterations" << endl;

    return 0;
}
