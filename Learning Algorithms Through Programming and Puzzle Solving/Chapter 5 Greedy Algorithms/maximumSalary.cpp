#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
//using namespace std;

/*
 *  Exercice in thebook : "Learning Algorithms Through Programming and Puzzle Solving"
 *
 *  Page: 73
 *  Year: 2018
 *
 *  Maximum Salary
 *
 *  Largest Concatenate Problem
 *
 *  Compile the largest number by concatenating the given numbers
 *
 *  example :
 *
 *      Inputs :     A sequence of positive integers
 *
 *
 *      Outputs :    The largest number that can be obtained by concate,nating the given integers in some order
 *
 *      Inputs : 23  39  92
 *
 *      Outputs : 923923
 *
 *
*/

bool isBetter(int a, int b){

    std::string a_string = std::to_string(a);
    a_string = a_string.substr(0, 1);

    std::string b_string = std::to_string(b);
    b_string = b_string.substr(0, 1);

    a = std::stoi(a_string);
    b = std::stoi(b_string);

    return a > b;
}

std::string maximumSalary(std::vector<int> v){

    std::string s;
    std::sort(v.begin(), v.end(), isBetter);

    for(int a : v)
        s += std::to_string(a);

    return s;
}
int main()
{
    std::vector<int> v = {23, 39, 92};

    std::cout << " " << maximumSalary(v) << std::endl;
}
