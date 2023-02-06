#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> calcFreq(vector<string> v){
    for(const string& i : v)
        std::cout << i << " ";
    std::cout << std::endl;

    sort(v.begin(), v.end());

    for(const auto& i : v)
        std::cout << i << " ";
    std::cout << std::endl;

    if(v.empty())
        return vector<int>();

    string word = v.at(0);
    int count = 1;
    vector<int> freq;
    for(std::size_t i = 1; i < v.size(); i++)
    {
        if(v.at(i - 1) == v.at(i))
        {
           // word = i;
            count++;
        }
        else
        {
            freq.push_back(count);
            count = 1;
        }
    }
    freq.push_back(count);
    return freq;
}

int main()
{
    vector<string> v = {"the", "dog", "ate", "the", "meat"};
    auto vF = calcFreq(v);

    for(const int & i : vF)
        std::cout << " " << i ;
    std::cout << std::endl;

    return 0;
}
