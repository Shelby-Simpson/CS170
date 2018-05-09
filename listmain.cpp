/*Problem3
  Assignment 3
  Shelby Simpson
  5/8/2018*/

// listmain.cpp
//
// This is a main program to test the linked list class.
//


#include <iostream>
using namespace std;
#include "list.h"

void main ()
{
   list l;

   cout << "List created." << endl;
   Employee first("Peter", 10);
   l.rearInsert (first);
   Employee second("John", 20);
   l.rearInsert (second);
   cout << "Two data values inserted in rear." << endl;
   cout << "The list is: " << l << endl;
   Employee third("George", 30);
   l.frontInsert (third);
   Employee fourth("Mary", 40);
   l.frontInsert (fourth);
   cout << "Two data values inserted in front." << endl;
   cout << "The list is: " << l << endl;
   Employee fifth("Evan", 50);
   l.specInsert(fifth, 4);
   cout << "One data value inserted into the fourth position." << endl;
   cout << "The list is: " << l << endl;
   l.specRemove(4);
   cout << "One data value removed from the fourth position." << endl;
   cout << "The list is: " << l << endl;
   l.frontRemove();
   cout << "One data value removed from the front." << endl;
   cout << "The list is: " << l << endl;
   l.rearRemove();
   cout << "One data value removed from the rear." << endl;
   cout << "The list is: " << l << endl;
   system("pause");
}