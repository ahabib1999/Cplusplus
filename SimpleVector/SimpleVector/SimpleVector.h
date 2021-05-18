#pragma once

#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>                  // Needed for bad-alloc exception
#include <cstdlib>              // Needed for the exit function
using namespace std;
// ***************************************************************
// * Template Assignment simplevector.h                          *
// * Description:  Contains the basic definition of the          *
// * SimpleVector Template class.  The method names and          *
// * signatures must not be modified. You will add your          *
// * Method implimentation to the end of this file where         *
// * indicated.                                                  *
// * Author: Dr. David Gaitros                                   *
// * Last Modified:  March 7th, 2021.                            *
// ***************************************************************
template <class T>
class SimpleVector {
    const int DEFAULTVECTORSIZE = 100;
private:
    T* aptr; 		// To point to the allocated array
    int arraysize; 		// Number of elements in the array
    void memError(); 	// Handles memory allocation errors
    void subError(); 	// Handles subscripts out of range
public:
    // Default constructor - Already written, 
    SimpleVector() { 
        aptr = 0; 
        arraysize = DEFAULTVECTORSIZE; 
    };

    // Constructor declaration
    SimpleVector(int);

    // Copy Constructor declaration
    SimpleVector(const SimpleVector&);

    // Destructor - check to see if the size > zero.
    ~SimpleVector();

    // Accessor to return the array size
    int size() const { return arraysize; }

    // Accessor to return a specific element
    T getElementAt(int sub);

    // Overload [] operator declaration
    T& operator[](const int&);
};
#endif SIMPLEVECTOR_H
// ***************************************************************
// * Add your method implementation here.                        *
// ***************************************************************

// *****************************************************************
// * Function Name: SimpleVector(int s) *
// * Description: Constructor with one param *
// * Parameter Description: int s: the array size for the vector object *
// * Date: 03/26/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

template <class T>

SimpleVector<T>::SimpleVector(int s)
{
    if (s < 1) arraysize = DEFAULTVECTORSIZE;
    else arraysize = s;

    try
    {
        aptr = new T[arraysize];
    }
    catch (bad_alloc)
    {
        memError();
    }
}

// *****************************************************************
// * Function Name: ~SimpleVector() *
// * Description: Destructor for the SimpleVector class *
// * Parameter Description: N/A *
// * Date: 03/26/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

template <class T>

SimpleVector<T>::~SimpleVector()
{
    if (arraysize > 0)
    {
        delete[] aptr;
    }
}

// *****************************************************************
// * Function Name: SimpleVector(const SimpleVector& v) *
// * Description: Copy constructor for the SimpleVector class *
// * Parameter Description: const SimpleVector& v: the vector object to copy from *
// * Date: 03/26/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

template <class T>

SimpleVector<T>::SimpleVector(const SimpleVector& v)
{
    arraysize = v.arraysize;
    aptr = new T[arraysize];

    for (int i = 0; i < arraysize; i++)
    {
        aptr[i] = v.aptr[i];
    }
}

// *****************************************************************
// * Function Name: operator[] (const int& index) *
// * Description: [] operator overload function *
// * Parameter Description: const int& index: index from which to return the desired element *
// * Date: 03/26/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

template <class T>

T& SimpleVector<T>:: operator[] (const int& index)
{
    try
    {
        return aptr[index];
    }
    catch (int index)
    {
        subError();
    }
}

// *****************************************************************
// * Function Name: getElementAt(int sub) *
// * Description: Return the element at the specified subscript *
// * Parameter Description: int sub: subscript of the element that needs to be returned *
// * Date: 03/26/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

template <class T>

T SimpleVector<T>::getElementAt(int sub)
{
    try
    {
        return aptr[sub];
    }
    catch (int index)
    {
        subError();
    }
}

// *****************************************************************
// * Function Name: memError() *
// * Description: Display the bad memory error *
// * Parameter Description: N/A *
// * Date: 03/26/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

template <class T>

void SimpleVector<T>::memError()
{
    cout << "Error: cannot allocate memory." << endl;
    exit(EXIT_FAILURE);
}

// *****************************************************************
// * Function Name: subError() *
// * Description: Display the bad subscript error *
// * Parameter Description: N/A *
// * Date: 03/26/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

template <class T>

void SimpleVector<T>::subError()
{
    cout << "Error: index out of bounds." << endl;
    exit(EXIT_FAILURE);
}

