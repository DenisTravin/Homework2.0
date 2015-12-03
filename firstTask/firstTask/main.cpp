#include <iostream>
#include <fstream>
#include "list.h"

using namespace std;

void main()
{
	listHead list;
	makeWarder(&list);
	ifstream fin("in.txt");
	if (!fin.is_open())
		cout << "File can't be open" << endl;
	else
	{
		fin >> list.numOfElements;
		listElement* temp = list.head;
		for (int i = 0; i < list.numOfElements; i++)
		{
			int currentElement;
			fin >> currentElement;
			addElement(&temp, currentElement);
		}
	}
	reverseList(&list);
	printList(&list);
	fin.close();
	deleteAllList(&list);
	scanf("%*s");
}
