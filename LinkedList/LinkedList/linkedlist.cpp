#include "linklist.h"
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// *****************************************************************
// * Function Name: LinkList() *
// * Description: Default Constructor for the LinkList class *
// * Parameter Description: N/A *
// * Date: 04/16/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

LinkList::LinkList()
{
	head = new PieCake_struct{
		1,
		"Head",
		"Node",
		'A',
		'M',
		'P',
		nullptr,
		tail
	};

	tail = new PieCake_struct{
		2,
		"Tail",
		"Node",
		'A',
		'F',
		'C',
		head,
		nullptr
	};

	current = head;
	count = 0;
}

// *****************************************************************
// * Function Name: List() *
// * Description: List the current record *
// * Parameter Description: N/A *
// * Date: 04/16/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void LinkList::List()
{
	cout << current->id << setw(12) << current->fname << setw(10) << current->mi << setw(12) << current->lname << setw(8) << current->sex << setw(8) << current->pORc << endl;
	current = current->next;
}

// *****************************************************************
// * Function Name: Print() *
// * Description: Default List all the records in the Link List *
// * Parameter Description: N/A *
// * Date: 04/16/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void LinkList::Print()
{
	cout << "** The Great Cheesecake Survey" << endl;
	cout << "ID   " << setw(10) << "First Name" << setw(10) << "MI" << setw(12) << "Last Name" << setw(10) << "Sex" << setw(10) << "Answer" << endl;
	cout << "--   -----------       --     ----------    ---   ----" << endl;

	current = head->next;
	while (current->lname != "Tail")
	{
		List();
	}
	cout << endl;
}

// *****************************************************************
// * Function Name: ~LinkList() *
// * Description: Destructor for the LinkList class *
// * Parameter Description: N/A *
// * Date: 04/16/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

LinkList::~LinkList()
{
	current = head;

	while (current->next != nullptr)
	{
		current = current->next;
		delete current->prev;
	}
	delete tail;
}

// *****************************************************************
// * Function Name: Size() *
// * Description: Return number of records in LinkList *
// * Parameter Description: N/A *
// * Date: 04/16/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

int LinkList::Size()
{
	return count;
}

// *****************************************************************
// * Function Name: Empty() *
// * Description: Check if list is Empty *
// * Parameter Description: N/A *
// * Date: 04/16/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

bool LinkList::Empty()
{
	if (count == 0 || head->next == tail)
	{
		return true;
	}
	else
	{
		return false;
	}
}

// *****************************************************************
// * Function Name: Find(const int id) *
// * Description: Find the record with the passed in id *
// * Parameter Description: N/A *
// * Date: 04/16/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

bool LinkList::Find(const int id)
{
	current = head->next;

	while (current->lname != "Tail")
	{
		if (current->id == id)
		{
			return true;
		}
		current = current->next;
	}
	current = nullptr;
	return false;
}

// *****************************************************************
// * Function Name: Insert(PieCake_struct* p) *
// * Description: Insert the passed in record into the list *
// * Parameter Description: N/A *
// * Date: 04/16/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

void LinkList::Insert(PieCake_struct* p)
{
	if (head->next == tail)
	{
		head->next = p;
		p->next = tail;
		p->prev = head;
		tail->prev = p;
	}
	else
	{

		tail->prev->next = p;
		p->prev = tail->prev;
		tail->prev = p;
		p->next = tail;
	}
	count += 1;
}

// *****************************************************************
// * Function Name: CountPie() *
// * Description: Count number of people who answered Pie *
// * Parameter Description: N/A *
// * Date: 04/16/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

int LinkList::CountPie()
{
	int pieCount = 0;
	current = head->next;

	while (current->lname != "Tail")
	{
		if (current->pORc == 'P')
		{
			pieCount += 1;
		}
		current = current->next;
	}
	return pieCount;
}

// *****************************************************************
// * Function Name: CountCake() *
// * Description: Count number of people who answered Cake *
// * Parameter Description: N/A *
// * Date: 04/16/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

int LinkList::CountCake()
{
	int cakeCount = 0;
	current = head->next;

	while (current->lname != "Tail")
	{
		if (current->pORc == 'C')
		{
			cakeCount += 1;
		}
		current = current->next;
	}
	return cakeCount;
}

// *****************************************************************
// * Function Name: Delete() *
// * Description: Deletes the current record from the list *
// * Parameter Description: N/A *
// * Date: 04/16/2021 *
// * Author: Akbar Habib. *
// * Referenes: Place here any references where you may have *
// * gotten the idea for the code or algorithm. You should *
// * reference any code you use from the book and class. *
// *****************************************************************

bool LinkList::Delete()
{
	if (current != nullptr)
	{
		current->prev->next = current->next;
		current->next->prev = current->prev;
		count -= 1;
		delete current;
		return true;
	}
	else
	{
		return false;
	}
}