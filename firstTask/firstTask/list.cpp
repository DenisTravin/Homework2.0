#include <cstdio>
#include "list.h"

void makeWarder(listHead* list)
{
	listElement* newElement = new listElement;
	newElement->element = 0;
	newElement->next = nullptr;
	list->head = newElement;
}

void addElement(listElement** source, int number)
{
	listElement *newElementTemp = new listElement;
	newElementTemp->element = number;
	newElementTemp->next = nullptr;
	(*source)->next = newElementTemp;
	*source = newElementTemp;
}

void printList(listHead* list)
{
	listElement* temp = list->head->next;
	for (int i = 0; i < list->numOfElements; i++)
	{
		printf("%i ", temp->element);
		temp = temp->next;
	}
}

void reverseList(listHead* list)
{
	listElement* tempForRe = list->head->next;
	listElement* tempNext = tempForRe->next;
	tempForRe->next = nullptr;
	for (int i = 0; i < list->numOfElements - 1; i++)
	{
		listElement* temp = tempNext->next;
		tempNext->next = tempForRe;
		tempForRe = tempNext;
		if (temp != nullptr)
		{
			tempNext = temp;
		}
		else
		{
			list->head->next = tempNext;
		}
	}
}

void deleteAllList(listHead* list)
{
	listElement* temp = list->head;
	for (int i = 0; i < list->numOfElements + 1; i++)
	{
		listElement* tempNext = temp->next;
		delete temp;
		temp = tempNext;
	}
	list->head = nullptr;
}