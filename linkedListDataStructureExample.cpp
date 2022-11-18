#include <iostream>
#include <time.h>       /* time */

using namespace std;

class A {
public:
    int m_id{-1};
    A * m_next{nullptr};

    A(): m_id{-1},m_next{nullptr}{};
    A(int id): m_id{id},m_next{nullptr}{};
    A(int id, A* next): m_id{id},m_next{next}{};

    ~A(){    }
};

int generateRand_0_100();
void addElementToTheEnd(A * root, int value);
void destroyList(A* root);
void destroyListRercursion(A* root);

int generateRand_0_100()
{
    return 0 + rand() % (100 - 0);
}

void addElementToTheEnd(A * root, int value)
{
    A * Current = root;
    while(Current->m_next != nullptr)
    {
        Current = Current->m_next;
    }

    A* newCase = new A{value, nullptr};
    Current->m_next = newCase;
}



void destroyList(A* root)
{
    destroyListRercursion(root);

    if(root != nullptr)
    {
        cout << "This Value will be destroyed D: " << root->m_id << endl;
        delete root;
        root = nullptr;
    }
}

void destroyListRercursion(A* root)
{
    A* Current = root;

    if(root->m_next != nullptr && root != nullptr)
    {
        while(Current->m_next->m_next != nullptr)
        {
            Current = Current->m_next;
        }

        if(Current->m_next != nullptr)
        {
            cout << "This Value will be destroyed : " << Current->m_next->m_id << endl;
            delete Current->m_next;
            Current->m_next = nullptr;
        }
            destroyListRercursion(root);
    }
}
int main()
{
    srand ( time(NULL) );


    A *  First = new A(2);
    A *  Second = new A(3, nullptr);
    A *  Third = new A(4, nullptr);
    A *  Fourth = new A(5, nullptr);
    A * Fifth;
    First->m_next = Second;
    Second->m_next = Third;
    Third->m_next = Fourth;
    addElementToTheEnd(First, 12);
    addElementToTheEnd(First, 14);
    addElementToTheEnd(First, 16);
    addElementToTheEnd(First, 18);

    for (int i = 0; i <= 9 ; ++i)
            addElementToTheEnd(First,generateRand_0_100());

    destroyList(First);

    return 0;
}
