#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

/*
 *  Exercice in thebook : "Learning Algorithms Through Programming and Puzzle Solving"
 *
 *  Page: 29
 *  Year: 2018
 *
 *  I wrote two algorithms to test the runtime when i use only on loop instead of using two loops
 *
 *  Also i changed a little bit the question so when ai = aj it takes only one of them and not ai*aj
 *
 *  Needs Some Corrections (Not Reliable)
*/

// Slower Algorithm
uint64_t maximumPairwiseProduct(vector<uint64_t> vec)
{
    if(vec.size() < 2)
        return -1;
    uint64_t max1 = vec.at(0);
    for(uint64_t i = 1; i < vec.size(); ++i)
    {
        max1 = std::max(max1, vec.at(i));
    }
    uint64_t max2 = vec.at(0);
    uint64_t i = 1;
    while(max2 == max1 && i != vec.size() - 1)
    {
        max2 = vec.at(i);
        ++i;
    }
    for(uint64_t i = 1; i < vec.size(); ++i)
    {
        if(vec.at(i) > max2 && vec.at(i) != max1)
            max2 = vec.at(i);
    }

    return max2*max1;
}

// Faster Algorithm
uint64_t maximumPairwiseProduct2(vector<uint64_t> vec)
{
    if(vec.size() < 2)
        return -1;
    uint64_t max1 = vec.at(0);
    uint64_t max2 = vec.at(0);
    uint64_t prevMax = max1;
    uint64_t i = 1;
    while(max2 == max1 && i != vec.size() - 1)
    {
        max2 = vec.at(i);
        ++i;
    }
    int ind1 = 0, ind2{0};
    for(uint64_t i = 1; i < vec.size(); ++i)
    {
        if(vec.at(i) > max1)
        {
            prevMax = max1;
            max1 = vec.at(i);
            ind1 = i;
        }
        if((vec.at(i) > max2 && vec.at(i) != max1) && (prevMax > vec.at(i)))
        {
            max2 = vec.at(i);
            ind2 = i;
        }
    }

    cout << "Hello " << ind1 << " " << ind2 << endl;
    return max2*max1;
}
int main()
{
    cout << "Hello World!" << endl;

    vector<uint64_t> vec{14,14,7,5,14,2,8,8,10,1,1000,90000};


std::chrono::steady_clock::time_point begin1 = std::chrono::steady_clock::now();
 uint64_t first = maximumPairwiseProduct(vec);
std::chrono::steady_clock::time_point end1 = std::chrono::steady_clock::now();

std::chrono::steady_clock::time_point begin2 = std::chrono::steady_clock::now();
uint64_t second = maximumPairwiseProduct2(vec);
std::chrono::steady_clock::time_point end2 = std::chrono::steady_clock::now();

cout << "First  : " << first << endl;
cout << "Second : " << second << endl;
std::cout << "Time difference 1 = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end1 - begin1).count() << "[ns]" << std::endl;

std::cout << "Time difference 2 = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end2 - begin2).count() << "[ns]" << std::endl;

    return 0;
}
