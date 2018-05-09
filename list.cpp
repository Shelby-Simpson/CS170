// list.cpp
//
// This file implements the integer linked list class.
//
//#include <stddef.h>
#include <iostream>
#include "list.h"
using namespace std;

// Constructor
list::list ()
{
   first = NULL;
}

// Destructor
list::~list ()
{
    node *next_node;

    while (first != NULL)
    {
        next_node = first->next;
        delete first;
        first = next_node;
    }
}

// Insert at front of list
void list::frontInsert (Employee emp)
{
    node *new_node;

    new_node = new node;
    if (new_node == NULL)
    {
        cout << "Unable to allocate memory. Insertion cancelled." << endl;
        return;
    }
    new_node->data = emp;
    new_node->next = first;
    first = new_node;
}

// Insert at rear of list
void list::rearInsert (Employee emp)
{
    node *new_node, *current;

    new_node = new node;
    if (new_node == NULL)
    {
        cout << "Unable to allocate memory. Insertion cancelled." << endl;
        return;
    }
    new_node->data = emp;
    new_node->next = NULL;
    if (first == NULL)
        first = new_node;
    else
    {
        current = first;
        while (current->next != NULL) current = current->next;
        current->next = new_node;
    }
}

// Insert at specified location
void list::specInsert(Employee emp, int position)
{
	node *new_node, *current;

	new_node = new node;
	if (new_node == NULL)
	{
		cout << "Unable to allocate memory. Insertion cancelled." << endl;
		return;
	}
	new_node->data = emp;
	if (first == NULL)
		first = new_node;
	else
	{
		current = first;
		for (int i = 0; i < position - 2; i++)
		{
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
		
	}
}

// Remove at specified location
void list::specRemove(int position)
{
	node *current = new node, *remove;
	if (first == NULL)
		cout << "The list is already empty." << endl;
	else
	{
		remove = first;
		for (int i = 0; i < position - 1; i++)
		{
			current = remove;
			remove = remove->next;
		}
		current->next = remove->next;
		delete remove;
		
	}
}

// Remove at front
void list::frontRemove()
{
	node *remove;
	if (first == NULL)
		cout << "The list is already empty." << endl;
	else
	{
		remove = first;
		first = first->next;
		delete remove;
	}
}

// Remove at rear
void list::rearRemove()
{
	node *current = new node, *remove;
	if (first == NULL)
		cout << "The list is already empty." << endl;
	else
	{
		remove = first;
		while (remove->next != NULL)
		{
			current = remove;
			remove = remove->next;
		}
		current->next = NULL;
		delete remove;
	}

}

// Print the list
ostream& operator<< (ostream& out, list& l)
{
    list::node *current = l.first;

    while (current != NULL)
    {
        out << "[Employee " << current->data.get_name() << " with salary ";
		out << current->data.get_salary() << "] ";
        current = current->next;
    }
    return out;
}
