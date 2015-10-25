#include "HashTable.h"

// Constructs the empty Hash Table object
HashTable::HashTable( int tableLength )
{
    array = new LinkedList[tableLength];
    length = tableLength;
}

// Returns an array location for a given data ID
int HashTable::hash(string name)
{
    int hashInt = 0;

    for (int i = 0; i < name.length(); i++)
    {
        hashInt += name[i];
    }

    return (hashInt % length);
}

// Adds data to the Hash Table.
void HashTable::insertData(data_entry * newData)
{
    int index = hash(newData -> get_member());
    array[index].insertData(newData);
}

// Deletes data by ID from the Hash Table.
// Returns true if the operation is successful.
bool HashTable::removeData(string name)
{
    int index = hash(name);
    return array[index].removeData(name);
}

// Returns data from the Hash Table by ID.
// If the data isn't found, a null pointer is returned.
data_entry * HashTable::getDataByName(string name)
{
    int index = hash(name);
    return array[index].getData(name);
}

// Returns the number of locations in the Hash Table.
int HashTable::getLength()
{
    return length;
}

// Returns the amount of data in the Hash Table.
int HashTable::getNumberOfDataEntries()
{
    int dataCount = 0;
    for ( int i = 0; i < length; i++ )
    {
        dataCount += array[i].getLength();
    }
    return dataCount;
}

// De-allocates all memory used for the Hash Table.
HashTable::~HashTable()
{
    delete [] array;
}

