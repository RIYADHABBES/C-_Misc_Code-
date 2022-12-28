#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
//using namespace std;

/*
 *  Exercice in thebook : "Learning Algorithms Through Programming and Puzzle Solving"
 *
 *  Page: 82
 *  Year: 2018
 *
 *  Binary search
 *
 *  Sorted Array Search Problem
 *
 *  Search a key in a sorted array of keys
 *  
 *    (The simplest case)
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
bool binarySearch(const std::vector<int>& vec, int q)
{
    if(vec.size() > 0)
    {

        int startIndex = 0;
        int endIndex = vec.size() - 1;
        int midIndex = (startIndex + endIndex) / 2;

        if(q < vec.at(startIndex) || q > vec.at(endIndex))
                return false;

        if(vec.at(midIndex) == q || vec.at(startIndex) == q || vec.at(endIndex) == q)
            return true;

        while(midIndex != startIndex && midIndex != endIndex && ((midIndex - startIndex) != 1 || (endIndex - midIndex) != 1))
        {
            if(vec.at(midIndex) < q && vec.at(endIndex) > q)
            {
                startIndex = midIndex;
                midIndex = (startIndex + endIndex) / 2;
            }

            if(vec.at(midIndex) > q && vec.at(startIndex) < q)
            {
                endIndex = midIndex;
                midIndex = (startIndex + endIndex) / 2;
            }

            if(vec.at(midIndex) == q || vec.at(startIndex) == q || vec.at(endIndex) == q)
                return true;
        }
        if(vec.at(midIndex) == q || vec.at(startIndex) == q || vec.at(endIndex) == q)
            return true;
    }

    return false;
}

int main()
{
    std::vector<int> vec = {1, 4, 65 , 74 , 75, 80, 82 ,84, 142};
    int q = 39;
    std::cout << "The value " << q << (binarySearch(vec, q)? " exists" : " doesn't exist") << " in the liste" << std::endl;
}
