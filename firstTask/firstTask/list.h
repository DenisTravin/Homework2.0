#pragma once

struct ListElement
{
	int element;
	ListElement *next;
};

struct ListHead
{
	int numOfElements;
	ListElement *head;
};

void makeWarder(ListHead* list);
void addElement(ListElement** source, int number);
void printList(ListHead* list);
void reverseList(ListHead* list);
void deleteAllList(ListHead* list);