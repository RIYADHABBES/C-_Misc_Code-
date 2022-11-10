#include <iostream>

/*
    This file calculates the factorial using a Recursion.
*/

//! The recursion function
//  Needs <result> to be passed by reference.

void factRecursion(int & result,const int val)
{
    int index = val;
    
    if(val != 1 && val != 0)
    {
        result *=  (index); 
        factRecursion(result,index - 1);
        index = index - 1;
    }
}

// The main factorial function
// It makes some initializations and call the factRecursion function

int factorial(const int val)
{
    int result = 1;
    factRecursion(result,val);
    
    if(result <= 0)
    {
        std::cout << "Be carfull the factorial result exceeds the integer size, the function returns 0" << std::endl;
        result = 0;
    }
    return result;
}

int main(void) {

    std::cout << factorial(19) << std::endl;

    return 0;
}
