#pragma once
// Created by David A Gaitros on 10/15/19. 
// ******************************************************************** 
// * Name: Stack Class                                                * 
// * Description:  A template Stack class designed to be used with    * 
// *   any simple C++ type to include floating point, double          * 
// *   floating point, character, and boolan.                         * 
// *   The stack pointer, as is the convention, points to the last    * 
// *   or highest element in the array. So if you allocate 100        * 
// *   elements of type "T" then the first empty element will be 99.  * 
// * Author: Dr. David A. Gaitros                                     * 
// * Date: January 19, 2019                                           * 
// ******************************************************************** 
#include <iostream>
#include <vector>
using namespace std;

const int DEFAULTSIZE = 100;

template <class T>
class Stack {
public:
    Stack();                    // Default Constructor, stack is size 100.
    Stack(const int size);      // Constructor, creates stack of size "size"
    Stack(const Stack<T>& item);// Copy constructor
    ~Stack();                   // Destructor
    bool Full();                // Return true if the stack is full
    bool Empty();               // Return true if the stack is empty
    int Size();                 // Return the size of the stack
    T Top();                    // Returns the top element, does not pop it.
    bool Push(const T item);   // Put an item on the stack.
    bool Pop();                 // Pop an item off and display to std out
    Stack<T>& operator = (const Stack<T> s); // Assignment operator overload

    // *****************************************************************
// * Function Name: operator <<(ostream& os, Stack<T>& s) *
// * Description: << operator overlaod *
// * Parameter Description: ostream& os: The ostream object that returns the output, Stack<T>& s: The stack called with the operator *
// * Date: 04/02/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

    friend ostream& operator <<(ostream& os, Stack<T>& s)
    {
        if (s.Empty())
        {
            cout << "Error: The stack is empty" << endl;
        }
        else
        {
            s.Pop();
            os << "";
            return os;
        }
    };
    void PrintStack(); // DELETE THIS
private:
    T* _stack;                 // The "stack"
    int _size;                  // The number of elements the stack can hold
    int _top;                   // Points to the first empty node
    int _maxsize;               //  Added to allow you to keep track of the size you allocated. 
    T  dummy;                   // Something to return in case there was an error on the Top()
};

// *****************************************************************
// * Function Name: Stack() *
// * Description: Default Constructor *
// * Parameter Description: N/A *
// * Date: 04/02/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

template <class T>

Stack<T>::Stack()
{
    
    _size = DEFAULTSIZE;
    _top = _size - 1;
    _stack = new T[_size];
    _maxsize = 0;
    dummy = -1; // Error flag value
}

// *****************************************************************
// * Function Name: Stack(const int size) *
// * Description: Constructor with one param *
// * Parameter Description: int size: Space allocated for new stack *
// * Date: 04/02/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

template <class T>

Stack<T>::Stack(const int size)
{
    _size = size;
    _top = _size - 1;
    _stack = new T[_size];
    _maxsize = 0;
    dummy = -1; // Error flag value
}

// *****************************************************************
// * Function Name: Stack<T>::operator = (const Stack<T> s) *
// * Description: Assignment operator overload function *
// * Parameter Description: const Stack<T> s: The stack to be made a copy of *
// * Date: 04/02/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

template <class T>

Stack<T>& Stack<T>::operator = (const Stack<T> s)
{
    _size = s._size;
    _top = s._top;
    _stack = new T[_size];
    _maxsize = s._maxsize;
    dummy = s.dummy; // Error flag value

    for (int i = 0; i < _maxsize; i++)
    {
        _stack[i] = s._stack[i];
    }
}

// *****************************************************************
// * Function Name: Stack(const Stack<T>& item) *
// * Description: Copy constructor *
// * Parameter Description: const Stack<T>& item: The Stack object to be made a copy of *
// * Date: 04/02/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

template <class T>

Stack<T>::Stack(const Stack<T>& item)
{
    _size = item._size;
    _top = item._top;
    _stack = new T[_size];
    _maxsize = item._maxsize;
    dummy = item.dummy; // Error flag value

    for (int i = 0; i < _maxsize; i++)
    {
        _stack[i] = item._stack[i];
    }
}

// *****************************************************************
// * Function Name: ~Stack() *
// * Description: Destructor *
// * Parameter Description: N/A *
// * Date: 04/02/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

template <class T> 

Stack<T>::~Stack()
{
    if (_size > 0)
    {
        delete[] _stack;
    }
}

// *****************************************************************
// * Function Name: Push(const T item) *
// * Description: Pushes an item into the Stack *
// * Parameter Description: const T item: The item to be pushed in *
// * Date: 04/02/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

template <class T>

bool Stack<T>::Push(const T item)
{
    if (Full())
    {
        cout << "Error: The stack is full" << endl;
        return false;
    }

    _stack[_top] = item;
    _top -= 1;
    _maxsize += 1;

    return true;
}

// *****************************************************************
// * Function Name: PrintStack() *
// * Description: Prints out the contents of the stack *
// * Parameter Description: N/A *
// * Date: 04/02/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

template <class T>

void Stack<T>::PrintStack()
{
    for (int i = 0; i < _maxsize; i++)
    {
        cout << _stack[i] << endl;
    }
}

// *****************************************************************
// * Function Name: Pop() *
// * Description: Pops an item off the Stack *
// * Parameter Description: N/A *
// * Date: 04/02/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

template <class T>

bool Stack<T>::Pop()
{
    if (Empty())
    {
        cout << "Error: The stack is empty" << endl;
        return false;
    }

    cout << _stack[_top + 1] << endl;
    _top = _top + 1;
    _maxsize -= 1;

    return true;
}

// *****************************************************************
// * Function Name: Size() *
// * Description: Prints out the size allocated to the stack *
// * Parameter Description: N/A *
// * Date: 04/02/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

template <class T>

int Stack<T>::Size()
{
    return _size;
}

// *****************************************************************
// * Function Name: Top() *
// * Description: Prints out the top element of the Stack without popping it off *
// * Parameter Description: N/A *
// * Date: 04/02/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

template <class T>

T Stack<T>::Top()
{
    if (Empty())
    {
        cout << "Error: The stack is empty" << endl;
        return dummy;
    }

    return _stack[_top + 1];
}

// *****************************************************************
// * Function Name: Empty() *
// * Description: Checks if a stack is empty *
// * Parameter Description: N/A *
// * Date: 04/02/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

template <class T> 

bool Stack<T>::Empty()
{
    if (_top == _size - 1)
    {
        return true;
    }

    return false;
}

// *****************************************************************
// * Function Name: Full() *
// * Description: Checks if a stack is full *
// * Parameter Description: N/A *
// * Date: 04/02/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

template <class T> 

bool Stack<T>::Full()
{
    if (_top <= -1)
    {
        return true;
    }

    return false;
}