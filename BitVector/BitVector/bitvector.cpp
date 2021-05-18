
#include <iostream>
#include "bitvector.h"

using namespace std;

// *****************************************************************
// * Function Name: BitVector() *
// * Description: Default constructor for the class *
// * Parameter Description: N/A *
// * Date: 02/13/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

BitVector::BitVector()
{
	int numbits = 256;
	int bitsinword = 32;
	size = numbits / bitsinword + 1;
	bvect = new int[size];
	bitlocations = numbits - 1;
	Unset();
}

// *****************************************************************
// * Function Name: BitVector(size_t Size) *
// * Description: Default constructor with one parameter *
// * Parameter Description: Size: The number of bits that the object can hold *
// * Date: 02/13/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

BitVector::BitVector(size_t Size)
{
	int numbits = Size;
	int bitsinword = 32;
	size = numbits / bitsinword + 1;
	bvect = new int[size];
	bitlocations = numbits - 1;
	Unset();
}

// *****************************************************************
// * Function Name: BitVector(BitVector& a) *
// * Description: Copy constructor for the class *
// * Parameter Description: a: BitVector object that values are copied into *
// * Date: 02/13/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

BitVector::BitVector(BitVector& a)
{
	size = a.size;
	bvect = new int[size];

	for (int i = 0; i < size; i++)
	{
		bvect[i] = a.bvect[i];
	}

	bitlocations = a.bitlocations;
}

// *****************************************************************
// * Function Name: BitVector& BitVector:: operator = (BitVector& a) *
// * Description: Assignment operator for the class *
// * Parameter Description: a: BitVector object that values are copied into *
// * Date: 02/13/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

BitVector& BitVector:: operator = (BitVector& a)
{
	size = a.size;
	bvect = new int[size];

	for (int i = 0; i < size; i++)
	{
		bvect[i] = a.bvect[i];
	}

	bitlocations = a.bitlocations;

	return a;
}

// *****************************************************************
// * Function Name: ~BitVector() *
// * Description: Destructor for the class *
// * Parameter Description: N/A *
// * Date: 02/13/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

BitVector::~BitVector()
{
	if (bvect != nullptr)
	{
		delete bvect;
	}
}

// *****************************************************************
// * Function Name: Set() *
// * Description: Turn all bits on *
// * Parameter Description: N/A *
// * Date: 02/13/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void BitVector::Set()
{
	for (int index = 0; index < size; index++)
	{
		bvect[index] = -1;
	}
}

// *****************************************************************
// * Function Name: Unset() *
// * Description: Turn all bits off *
// * Parameter Description: N/A *
// * Date: 02/13/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void BitVector::Unset()
{
	for (int index = 0; index < size; index++)
	{
		bvect[index] = 0;
	}
}

// *****************************************************************
// * Function Name: Test(size_t index) const *
// * Description: Tests if a bit is turned on or off *
// * Parameter Description: size_t index: The bit to be tested *
// * Date: 02/13/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

bool BitVector::Test(size_t index) const
{
	int numbits = size * 32;
	if (index < 0 || index > numbits)
	{
		return false;
	}

	int mask = 1;
	int andresult = 0;

	mask = mask << (index % 32);
	andresult = bvect[index / 32] & mask;

	if (andresult != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// *****************************************************************
// * Function Name: Print() *
// * Description: Displays whether a bit is turned on or off *
// * Parameter Description: N/A *
// * Date: 02/13/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void BitVector::Print()
{

	for (int index = 0; index < 32 * size; index++)
	{
		if (Test(index))
		{
			cout << "Index " << index << " is on" << endl;
		}
		else
		{
			cout << "Index " << index << " is off" << endl;
		}
	}
}

// *****************************************************************
// * Function Name: Set(const size_t index) *
// * Description: Turns a specific bit on *
// * Parameter Description: size_t index: The bit to be turned on *
// * Date: 02/13/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void BitVector::Set(const size_t index)
{
	int mask = 1;
	mask = mask << (index % 32);
	bvect[index / 32] = bvect[index / 32] | mask;
}

// *****************************************************************
// * Function Name: Size() const *
// * Description: Returns the number of bits an object can hold *
// * Parameter Description: N/A *
// * Date: 02/13/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

size_t BitVector::Size() const
{
	return 32 * size;
}

// *****************************************************************
// * Function Name: Unset(const size_t index) *
// * Description: Turns a specific bit on *
// * Parameter Description: size_t index: The bit to be turned off *
// * Date: 02/13/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void BitVector::Unset(const size_t index)
{
	if (Test(index))
	{
		Flip(index);
	}
}

// *****************************************************************
// * Function Name: Flip() *
// * Description: Filps the status of each bit *
// * Parameter Description: N/A *
// * Date: 02/13/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void BitVector::Flip()
{
	int mask = -1;

	for (int i = 0; i < size; i++)
	{
		bvect[i] = bvect[i] ^ mask;
	}
}

// *****************************************************************
// * Function Name: Flip(const size_t index) *
// * Description: Filps the status of each bit *
// * Parameter Description: index: The bit to be flipped *
// * Date: 02/13/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void BitVector::Flip(const size_t index)
{
	int mask = 1;
	mask = mask << (index % 32);
	bvect[index / 32] = bvect[index / 32] ^ mask;
}