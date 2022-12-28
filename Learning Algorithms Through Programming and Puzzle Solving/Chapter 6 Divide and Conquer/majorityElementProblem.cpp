#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
//using namespace std;

/*
 *  Exercice in thebook : "Learning Algorithms Through Programming and Puzzle Solving"
 *
 *  Page: 85
 *  Year: 2018
 *
 *  Majority Element
 *
 *  Majority Element Problem Problem
 *
 *  Search a key in a sorted array of keys
 *
 *  example :
 *
 *      Inputs :     vec = {1, 4, 65 , 74 , 75, 80, 82 ,84, 142};
 *
 *                   key = 39
 *
 *
 *      Outputs :    39 doesn't exist in vec
 *
 *
*/

int BoyerMooreMajorityVotingAlgorithm(const std::vector<int>& vec)
{
    int candidate = 0, votes = 0;

    for(unsigned int i = 0; i < vec.size(); ++i)
    {
        if(votes == 0)
        {
            candidate = vec.at(i);
        }
        else
        {
            if(vec.at(i) == candidate)
            {
                votes++;
            }
            else
            {
                votes--;
            }
        }
    }

    unsigned int count = 0;

    for(unsigned int i = 0; i < vec.size(); ++i)
    {
        if(vec.at(i) == candidate)
            count++;
    }

    if(count >= vec.size() / 2)
        return candidate;

    return -1;
}
int main()
{
    std::vector<int> vec = {1, 4, 65 , 5 , 75, 5, 82 ,5, 5, 5 , 3 , 5 };
    int result = BoyerMooreMajorityVotingAlgorithm(vec);
    if(result != -1)
        std::cout << "The majority element is " << result << std::endl;
    else
        std::cout << "No majority element" << std::endl;
}
