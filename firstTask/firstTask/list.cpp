#include <cstdio>
#include "list.h"

void makeWarder(ListHead* list)//making warder for list
{
	list->numOfElements = 0;
	ListElement* newElement = new ListElement;
	newElement->element = 0;
	newElement->next = nullptr;
	list->head = newElement;
}

void addElement(ListElement** source, int number)//add new element in list after source
{
	ListElement *newElementTemp = new ListElement;
	newElementTemp->element = number;
	newElementTemp->next = nullptr;
	(*source)->next = newElementTemp;
	*source = newElementTemp;
}

void printList(ListHead* list)//print all list
{
	ListElement* temp = list->head->next;
	for (int i = 0; i < list->numOfElements; i++)
	{
		printf("%i ", temp->element);
		temp = temp->next;
	}
}

void reverseList(ListHead* list)//reverse list
{
	ListElement* firstElement = list->head->next;
	if (firstElement == nullptr || firstElement->next == nullptr)//if list empty or have only one element we should do nothing
	{
		return;
	}
	ListElement* secondElement = firstElement->next;
	firstElement->next = nullptr;
	for (int i = 0; i < list->numOfElements - 1; i++)
	{
		ListElement* temp = secondElement->next;
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

void deleteAllList(ListHead* list)//delete all list with warder
{
	ListElement* temp = list->head;
	for (int i = 0; i < list->numOfElements + 1; i++)
	{
		ListElement* tempNext = temp->next;
		delete temp;
		temp = tempNext;
	}
	list->head = nullptr;
}