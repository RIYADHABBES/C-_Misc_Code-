#include <iostream>
#include <time.h>       /* time */

using namespace std;

/*
*                  Singly Linked List Data Structure Printing Values Example
*
*
*                               -------------------------
*                   ------------|   A                   |
*                  |            -------------------------
*                  |            | int m_id              |
*                  |            | A * m_next            |
*                  |            |                       |
*                  |            |                       |
*                  |            -------------------------
*                  |            |                       |
*                  |            -------------------------
*                  |                /#\
*                  |                \#/
*                  |_________________|
*
*      ------------------------               ------------------------               ------------------------               ------------------------
*      |Id = 1  | Next = 0x356|     ------>   |Id = 15 | Next = 0x...|   --...-->    |Id = 7  | Next = 0x845|     ------>   |Id = 6  | Next = NULL |  ------>   NULL
*      ------------------------               ------------------------               ------------------------               ------------------------
*       0x145                                  0x356                                    0x014                                0x845
*       .
*      / \
*       |
*       |
*       ptr_cursor = root (or first or begin) 
*/

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
void deleteElementFromTheEnd(A * root, int pos_end);
void printListElements(A * root);
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

void deleteElementFromTheEnd(A * root, int pos_end)
{
    int listSize = 0;
    A * ptr_cursor = root;
    
    while(ptr_cursor != nullptr)
    {
        listSize++;
        ptr_cursor = ptr_cursor->m_next;
    }
    
    if(listSize != 0 && pos_end >= 0 && pos_end < listSize)
    {
        ptr_cursor = root;
        
        for(int i = 0; i < listSize - pos_end - 1 - 1; i++)
        {
            ptr_cursor = ptr_cursor->m_next;
        }
        
        A * ptr_destroyer = ptr_cursor->m_next;
        ptr_cursor->m_next = ptr_destroyer->m_next;
        
        delete ptr_destroyer;
    }
}

void printListElements(A * root)
{
    A * ptr_cursor = root;
    std::cout << "\n\nList Elements \n\n" ;
    while(ptr_cursor  != nullptr)
    {
        std::cout << "Element Id : " <<ptr_cursor->m_id << "   next_Adresse : " << ptr_cursor->m_next << "\n";
        ptr_cursor = ptr_cursor->m_next;
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

 //   for (int i = 0; i <= 9 ; ++i)
  //          addElementToTheEnd(First,generateRand_0_100());

//    destroyList(First);

printListElements(First);

deleteElementFromTheEnd(First, 2);
printListElements(First);
    return 0;
}
