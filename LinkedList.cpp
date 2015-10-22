#include "LinkedList.h"

// Constructs the empty linked list object.
// Creates the head node and sets length to zero.
LinkedList::LinkedList()
{
    head = new data_entry;
    head -> next = NULL;
    length = 0;
}

// Inserts data at the end of the list.
void LinkedList::insertData(data_entry * newData)
{
    if (!head -> next)
    {
        head -> next = newData;
        length++;
        return;
    }
    data_entry * p = head;
    data_entry * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
    }
    p -> next = newData;
    newData -> next = NULL;
    length++;
}

// Removes data from the list by ID.
// Returns true if the operation is successful.
bool LinkedList::removeData(int dataID)
{
    if (!head -> next) return false;
    data_entry * p = head;
    data_entry * q = head;
    while (q)
    {
        if (q->get_ID() == dataID)
        {
            p -> next = q -> next;
            delete q;
            length--;
            return true;
        }
        p = q;
        q = p -> next;
    }
    return false;
}

// Searches for data by its ID.
// Returns a reference to first match.
// Returns a NULL pointer if no match is found.
data_entry * LinkedList::getData(int dataID)
{
    data_entry * p = head;
    data_entry * q = head;
    while (q)
    {
        p = q;
        if ((p != head) && (p->get_ID() == dataID))
            return p;
        q = p -> next;
    }
    return NULL;
}

// Displays list contents to the console window.
void LinkedList::printList()
{
    if (length == 0)
    {
        cout << "\n{ }\n";
        return;
    }
    data_entry * p = head;
    data_entry * q = head;
    cout << "\n{ ";
    while (q)
    {
        p = q;
        if (p != head)
        {
            cout << p->get_ID();
            if (p -> next) cout << ", ";
            else cout << " ";
        }
        q = p -> next;
    }
    cout << "}\n";
}

// Returns the length of the list.
int LinkedList::getLength()
{
    return length;
}

// De-allocates list memory when the program terminates.
LinkedList::~LinkedList()
{
    data_entry * p = head;
    data_entry * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
        if (q) delete p;
    }
}

