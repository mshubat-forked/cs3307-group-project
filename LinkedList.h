#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <string>
#include "data_entry.h"
using namespace std;

struct data
{
    data_entry * entry;
    data * next;
};

class LinkedList
{
private:
    // Head is a reference to a list of data nodes.
    data * head;

    // Length is the number of data nodes.
    int length;

    data_entry ** allData;

public:
    // Constructs the empty linked list object.
    // Creates the head node and sets length to zero.
    LinkedList();

    // Inserts data at the end of the list.
    void insertData(data_entry * newData);

    // Removes data from the list by item key.
    // Returns true if the operation is successful.
    bool removeData(string name);

    // Searches for data by its name.
    // Returns a reference to first match.
    // Returns a NULL pointer if no match is found.
    data_entry * getData(string name);

    //Returns a referece to first element of an array of all elements in list
    //Returns NULL if name does not match
    data_entry ** getAllData(string name);

    // Displays list contents to the console window.
    void printList();

    // Returns the length of the list.
    int getLength();

    // De-allocates list memory when the program terminates.
    ~LinkedList();
};

#endif

//*****************************************************************
// End of File
//*****************************************************************
