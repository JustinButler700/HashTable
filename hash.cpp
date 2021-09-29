// ====================================================
//HW#: 8
//Your name: Justin Butler
//Complier:  G++
//File type: HashMap program implementation file
//=====================================================
#include "hash.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

HashMap::HashMap(int size)
{
    this->size = size;
    table = new Entry *[size];
    for (int i = 0; i < size; i++)
        table[i] = NULL;
}
/*
destructor  
Destroys the hashmap
*/
HashMap::~HashMap()
{
    for (int i = 0; i < size; i++)
        if (table[i] != NULL)
            delete table[i];
    delete[] table;
}
// PURPOSE: Uses DJB(x33+b) Hashing function to create a key for storing our entry and returns its hashed value as an unsigned long
//Parameter: string str (key to be hashed) in this case, the name of our contact.
unsigned long HashMap::myHash(string str)

{
    const char *cstr = str.c_str();
    unsigned long hash = 5381;
    int c;
    while (c = *cstr++)
        hash = hash * 33 + c;
    return hash;
}
// PURPOSE: Adds a new entry to the hashmap by finding its key and placing it in the correct spot with collision handling
//Parameter: Entry e holds the Contact to be added to the hashmap and data about it (key ect)
void HashMap::put(Entry *e)
{
    string key = e->getKey();
    int index = myHash(key) % size;
    int startIndex = index;
    while (table[index] != NULL && table[index]->getKey() != key && table[index]->getKey() != "empty")
    {
        index = (index + 1) % size;
        if (index == startIndex)
            throw Overflow();
    }
    table[index] = e;
}
// PURPOSE: Retrieves the contact at the given key on the hashmap
//Parameter: key holds the posistion of the contact entry on the hashmap
Entry *HashMap::get(string key)
{
    int index = myHash(key) % size;
    int startIndex = index;
    while (table[index] != NULL && table[index]->getKey() != key)
    {
        index = (index + 1) % size;
        if (index == startIndex)
            return NULL;
    }
    return table[index];
}
// PURPOSE: removes an entry at a specific key on the hashmap and replaces it with an empty entry
//Parameter: key holds the posistion of the contact entry on the hashmap
Entry *HashMap::remove(string key)
{
    int index = myHash(key) % size;
    int startIndex = index;
    while (table[index] != NULL && table[index]->getKey() != key)
    {
        index = (index + 1) % size;
        if (index == startIndex)
            return NULL;
    }
    Entry *e = table[index];
    delete e;
    table[index] = new Entry("empty", 0, 0.0); // updated to prevent "unrecognized token " error
    return e;
}