#include <iostream>
#include <fstream>
#include "list.h"

using namespace std;

void main()
{
	ifstream fin("in.txt");
	if (!fin.is_open())
	{
		cout << "File can't be open" << endl;
	}
	else
	{
		ListHead list;
		makeWarder(&list);
		ListElement* temp = list.head;
		fin >> list.numOfElements;
		for (int i = 0; i < list.numOfElements; i++)
		{
			int currentElement;
			fin >> currentElement;
			addElement(&temp, currentElement);
		}
		reverseList(&list);
		printList(&list);
		deleteAllList(&list);
	}
	fin.close();
	scanf("%*s");
}