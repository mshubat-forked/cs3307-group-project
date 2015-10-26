#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "node.h"
#include "teaching_entry.h"


class LinkedList
{
private:

    Node<teaching_entry> *_pHead; // pointer of head node
    int length; //holds length of current list

public:
    /* Constructors with No Arguments */
    LinkedList();
    /* Constructors with a given value of a list node */
    LinkedList(teaching_entry val);
    /* Destructor */
    ~LinkedList();
//member functions
public:
    void add(teaching_entry val);
    void remove(teaching_entry val);
    Node<teaching_entry> * find(std::string t);
    /* Traversing the list and printing the value of each node */
    void traverse_and_print();
};

#endif // LINKEDLIST_H
