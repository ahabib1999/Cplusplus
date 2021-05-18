#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "linklist.h"

void OpenFile(ifstream& f);
void PropogateTheList(ifstream& f, LinkList& ML);

int main()
{
	ifstream inputfile;
	LinkList MyList;
	if (MyList.Empty()) cout << "File should be empty..passed Empty() Test" << endl;
	else cout << "Structure should be empty .. Failed Empty() Test" << endl;
	OpenFile(inputfile);
	PropogateTheList(inputfile, MyList);
	cout << "After Propogate number of records is: " << MyList.Size() << endl;
	inputfile.close();
	if (!MyList.Empty()) cout << "File should not  be empty..passed Empty() Test" << endl;
	else cout << "Structure should be not empty .. Failed Empty() Test" << endl;
	if (MyList.Find(67)) cout << "Found Record #67" << endl;
	if (MyList.Delete()) cout << "Deleteing Record #67" << endl;
	else cout << "Delete failed the test" << endl;
	if (!MyList.Find(67)) cout << "Did not find Record #67" << endl;
	MyList.Print();
	cout << "Total who thought cheesecake is pie: " << MyList.CountPie() << endl;
	cout << "Total who thought cheesecake is cake: " << MyList.CountCake() << endl;
	cout << "Total number of people: " << MyList.Size() << endl;
	return 0;
}

void OpenFile(ifstream& inputfile)
{
	static string filename;
	cout << "Enter a valid input file name: ";
	cin >> filename;
	inputfile.open(filename);
	while (!inputfile.is_open())
	{
		cout << "Invalid filename, re-enter->";
		cin >> filename;
		inputfile.open(filename);
	}
}

void PropogateTheList(ifstream& f, LinkList& ML)
{
	static PieCake_struct* record;
	record = new PieCake_struct;
	f >> record->id >> record->lname >> record->fname >> record->mi >> record->sex >>
		record->pORc;
	while (!f.eof())
	{
		ML.Insert(record);
		record = new PieCake_struct;
		f >> record->id >> record->lname >> record->fname >> record->mi >> record->sex >>
			record->pORc;
	}

}