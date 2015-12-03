#pragma once

struct listElement
{
	int element;
	listElement *next;
};

struct listHead
{
	int numOfElements;
	listElement *head;
};

void makeWarder(listHead* list);
void addElement(listElement** source, int number);
void printList(listHead* list);
void reverseList(listHead* list);
void deleteAllList(listHead* list);