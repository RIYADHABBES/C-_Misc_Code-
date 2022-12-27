#include <vector>
#include <algorithm>
#include <iostream>
//using namespace std;

/*
 *  Exercice in thebook : "Learning Algorithms Through Programming and Puzzle Solving"
 *
 *  Page: 73
 *  Year: 2018
 *
 *  Maximum Number of Prizes
 *
 *  Distinct Summands Problem
 *
 *  Represent a positive integer as the sum of the maximum number of pairwise distinct positive integers
 *
 *  example :
 *                    ________________________
 *      Inputs :     |           8           |
 *                    ------------------------
 *                    ________________________
 *      Outputs :    | 1 |  2  |    5        |
 *                    ------------------------
 *
*/

std::vector<int> maximumNumberOfPrizes(int n){
    int r = n;
    int v = 1;
    std::vector<int> result;
    while(r > 2 * v && r > 0)
    {

        result.push_back(v);
        r = r - v;
        ++v;
    }
    result.push_back(r);
    return result;
}

void printVectorValues(const std::vector<int> v){
    std::cout << "The values are : \n" << std::endl;

    for(const int& i : v)
        std::cout << "          " << i << std::endl;
                        }
int main()
{
    int n = 8;
    printVectorValues(maximumNumberOfPrizes(n));

}
