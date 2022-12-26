#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

/*
 *  Exercice in thebook : "Learning Algorithms Through Programming and Puzzle Solving"
 *
 *  Page: 69
 *  Year: 2018
 *
 *  Maximum value of the loot
 *
 *  example :
 *
 *      Inputs : W = 50
 *
 *      w_0 = 20 p_0 = 60         where w_i: the weight of the element in pounds
 *                                      p_i : the price of element per pound
 *      w_1 = 50 p_1 = 100
 *
 *      .
 *      .
 *      .
 *
 *      w_n = 30 p_n = 120
 *
 *      Output :
 *
 *            p_0 * u_0 + p_1 * u_1 + ... + p_n * u_n = P_max                  P_max is tha maximal gain that we can obtain
 *
 *            u_0 + u_1 + ... + u_n <= W             where u_i : is the weight of each element that we will take in a way that maximizes P_max (gain)
 *
 *            60 * 0 + 100 * 20 + ... + 120 * 30 = 5600 $
 *
 *            0 + 20 + ... + 30 <= 50
 *
 *
*/

struct Element{
    int m_pricePerPound = 0;
    int m_pounds = 0;
    Element(){};
    Element(int pricePerPound, int pounds):m_pricePerPound{pricePerPound},m_pounds{pounds}{};
};

bool compareByPrice(const Element& a, const Element& b)
{
    return a.m_pricePerPound > b.m_pricePerPound;
}
float loot(int W, vector<Element> elements)
{
    std::sort(elements.begin(), elements.end(), compareByPrice);

    int r = W;
    float sum = 0;
    for(const Element& el : elements)
    {
        if(el.m_pounds <= r)
        {
            sum = sum + el.m_pounds * el.m_pricePerPound;
            r = r - el.m_pounds;
        }
        else
        {
            sum = sum + r * el.m_pricePerPound;
            return sum;
        }
    }
    return sum;
}

int main()
{
    int W = 50;
    vector<Element> v = {Element(60,20),Element(100,50),Element(120,30)};

    int sum = loot(W,v);

    std::cout << "The maximum loot is " << sum
              << std::endl;
}
