#include "LinkedList.h"

// Constructs the empty linked list object.
// Creates the head node and sets length to zero.
LinkedList::LinkedList()
{
    head = new data;
    head -> next = NULL;
    length = 0;
}

// Inserts data at the end of the list.
void LinkedList::insertData(data_entry * newData)
{
    if (!head -> next)
    {
        head -> next = new data{newData, NULL};
        length++;
        return;
    }
    data * p = head;
    data * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
    }
    p -> next = new data{newData, NULL};
    length++;
}

// Removes data from the list by name.
// Returns true if the operation is successful.
bool LinkedList::removeData(string name)
{
    if (!head -> next) return false;
    data * p = head;
    data * q = head;
    while (q)
    {
        if (q->entry->get_user().compare(name))
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

// Searches for data by its name.
// Returns a reference to first match.
// Returns a NULL pointer if no match is found.
data_entry * LinkedList::getData(string name)
{
    data * p = head;
    data * q = head;
    while (q)
    {
        p = q;
        if ((p != head) && (p->entry->get_user() == name))
            return p->entry;
        q = p -> next;
    }
    return NULL;
}

//Returns a referece to first element of an array of all elements in list
//Returns NULL if name does not match
data_entry ** LinkedList::getAllData(string name)
{
    allData  = new data_entry*[length];
    int i = 0;

    data * p = head;
    data * q = head;
    while (q)
    {
        p = q;
        if (p != head)
        {
            allData[i] = p->entry;
            i++;
        }
        q = p -> next;
    }
    return allData;
}

// Displays list contents to the console window.
void LinkedList::printList()
{
    if (length == 0)
    {
        cout << "\n{ }\n";
        return;
    }
    data * p = head;
    data * q = head;
    cout << "\n{ ";
    while (q)
    {
        p = q;
        if (p != head)
        {
            cout << p->entry->get_user();
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
    data * p = head;
    data * q = head;
    while (q)
    {
        p = q;
        q = p -> next;
        delete p;
    }
}
