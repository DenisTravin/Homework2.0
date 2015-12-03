#include <cstdio>
#include "list.h"

void makeWarder(listHead* list)//making warder for list
{
	list->numOfElements = 0;
	listElement* newElement = new listElement;
	newElement->element = 0;
	newElement->next = nullptr;
	list->head = newElement;
}

void addElement(listElement** source, int number)//add new element in list after source
{
	listElement *newElementTemp = new listElement;
	newElementTemp->element = number;
	newElementTemp->next = nullptr;
	(*source)->next = newElementTemp;
	*source = newElementTemp;
}

void printList(listHead* list)//print all list
{
	listElement* temp = list->head->next;
	for (int i = 0; i < list->numOfElements; i++)
	{
		printf("%i ", temp->element);
		temp = temp->next;
	}
}

void reverseList(listHead* list)//reverse list
{
	listElement* firstElement = list->head->next;
	if (firstElement == nullptr || firstElement->next == nullptr)//if list empty or have only one element we should do nothing
	{
		return;
	}
	listElement* secondElement = firstElement->next;
	firstElement->next = nullptr;
	for (int i = 0; i < list->numOfElements - 1; i++)
	{
		listElement* temp = secondElement->next;
		secondElement->next = firstElement;
		firstElement = secondElement;
		if (temp != nullptr)
		{
			secondElement = temp;
		}
		else
		{
			list->head->next = secondElement;
		}
	}
}

void deleteAllList(listHead* list)//delete all list with warder
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