#include <iostream>
#include <vector>
using namespace std;

/*
*                 Tree Data Structure Printing Values Example
*
*
*                               -------------------------
*                   ------------|   A                   |
*                  |            -------------------------
*                  |            | int m_id              |
*                  |            | std::vector<A *> m_e  |
*                  |            |                       |
*                  |            |                       |
*                  |            -------------------------
*                  |            |                       |
*                  |            -------------------------
*                  |                /\
*                  |                \/
*                  |_________________|
*
*                                       ----------
*                                       |Id = 1  |
*                                       ----------
*                                           |
*                                           |
*               -----------------------------------------------------------------------------
*               |                                      |                                    |
*           ----------                            ----------                            ----------
*           |Id = 2  |                            |Id = 3  |                            |Id = 4  |
*           ----------                            ----------                            ----------
*               |                                                                           |
*               -------------------------------------                           ------------------------
*               |           |           |           |                           |                       |
*           ----------  ----------  ----------  ----------                   ----------             ----------
*           |Id = 7  |  |Id = 8  |  |Id = 9  |  |Id = 10  |                  |Id = 5  |             |Id = 6  |
*           ----------  ----------  ----------  ----------                   ----------             ----------
*
*
*/

class A
{
public:
    int m_id;
    std::vector < A * >m_e;
    A():m_id{-1}{ };
    A(int id):m_id{id}{  };
    A(int id, std::vector <A* >e):m_id{id}, m_e{e}{  };
    void setVector (std::vector < A * >e)
    {
        m_e = e;
    }
};

void printAllWithoutRoot (A * root)
{
    for (int i = 0; i < root->m_e.size (); i++)
    {
        if (root->m_e.size () != 0)
        {
            std::cout << "Id = " << root->m_e[i]->m_id << std::endl;
            printAllWithoutRoot (root->m_e[i]);
        }
    }
}

void printAll(A* root)
{
    std::cout << "Root Id = "<< root->m_id << std::endl;
    printAllWithoutRoot (root);
}

int main ()
{
    A a10{10}, a9{9}, a8{8}, a7{7}, a6{6}, a5{5}, a4{4}, a3{3}, a2{2}, a1{1};

    std::vector < A * >vec1  {  &a2, &a3, &a4};
    std::vector < A * >vec2  {  &a5, &a6};
    std::vector < A * >vec3  {  &a7, &a8, &a9, &a10};

    a2.setVector (vec3);
    a4.setVector (vec2);
    a1.setVector (vec1);

    cout <<  endl << endl;
    printAll(&a1);
    cout <<  endl << endl;
    return 0;
}
