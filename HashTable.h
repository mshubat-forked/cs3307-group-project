#ifndef HashTable_h
#define HashTable_h

#include "LinkedList.h"

//*****************************************************************
// Hash Table objects store a fixed number of Linked Lists.
//*****************************************************************
class HashTable
{
    private:

        // Array is a reference to an array (hash table) of Linked Lists.
        LinkedList * array;

        // Length is the size of the array.
        int length;

        // Returns an array location for a given item key.
        int hash(string name);

    public:

        // Constructs the empty Hash Table object
        HashTable(int tableLength);

        // Adds data to the Hash Table.
        void insertData(data_entry * newData );

        // Deletes data by name from the Hash Table.
        // Returns true if the operation is successful.
        bool removeData(string name);

        // Returns data from the Hash Table by name.
        // If the data isn't found, a null pointer is returned.
        data_entry * getDataByName(string name);

        data_entry ** getAllDataByName(string name);

        // Returns the number of locations in the Hash Table.
        int getLength();

        // Returns the number of Items in the Hash Table.
        int getNumberOfDataEntries();

        // De-allocates all memory used for the Hash Table.
        ~HashTable();
};

#endif
