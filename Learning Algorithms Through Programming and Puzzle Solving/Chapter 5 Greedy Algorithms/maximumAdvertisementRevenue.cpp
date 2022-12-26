#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

/*
 *  Exercice in thebook : "Learning Algorithms Through Programming and Puzzle Solving"
 *
 *  Page: 71
 *  Year: 2018
 *
 *  Maximum Product of Two Sequences Problem
 *
 *  Maximum Advertisement Revenue
 *  example :
 *
 *      Find the maximum dot product of two sequences of numbers
 *
 *      Inputs: two sequences of n positive integers: price_1, ... , price_n and clicks_1, ... , clicks_n
 *
 *      Output: The maximum value of price1 * c_1 + ... price_n * c_n
 *              where c_1, ... , c_n is a permutation of clicks_1 , ... ,  clicks_n
 *
 *
 *      Inputs :
 *
 *          Prices : 2 , 3 , 9
 *          clicks : 7 , 4 , 2
 *
 *      Output :
 *
 *      79 = 7 . 9 + 2 . 2 + 3 . 4
 *
 *
*/


float maximumAdvertisementRevenue(vector<int> clicks, vector<int> prices)
{
    if(clicks.size() != prices.size() || !clicks.size() || !prices.size())
        return -1;
    std::sort(clicks.begin(), clicks.end());
    std::sort(prices.begin(), prices.end());

    int maximumAdvertisementRevenue = 0;
    for(unsigned int i = 0; i < clicks.size(); ++i)
    {
        maximumAdvertisementRevenue += clicks.at(i) * prices.at(i);
    }
    return maximumAdvertisementRevenue;
}

int main()
{
    vector<int> clicks = {7,4,2};
    vector<int> prices = {2,3,9};
    int m = maximumAdvertisementRevenue(clicks,prices);

    std::cout << "The maximum Advertisement Revenue  is " << m
              << std::endl;
}
