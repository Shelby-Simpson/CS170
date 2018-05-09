// list.h
//
// This file is the specification for a class implementing a linked list of
// integers.
//
#include <iostream>
#include "ccc_empl.h"
using namespace std;

#ifndef LIST_H
#define LIST_H

class list{
public:
    list ();  // constructor
    ~list (); // destructor

    void frontInsert (Employee emp);  // insert at front of list
    void rearInsert (Employee emp);   // insert at rear of list
	void specInsert (Employee emp, int position);   // insert at specified location
	void specRemove (int position);   // remove from specific location
	void frontRemove ();  // remove from front of list
	void rearRemove ();   // remove from rear of list

    friend ostream& operator<< (ostream& out, list& l);  // print the list
    
private:
    struct node
    {
        Employee  data;
        node *next;
    };
    node *first;
	int position;
};

#endif
