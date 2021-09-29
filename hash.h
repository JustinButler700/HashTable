// ====================================================
//HW#: 8
//Your name: Justin Butler
//Complier:  G++
//File type: HashMap header file & Entry class
//=====================================================
#ifndef HASH_H
#define HASH_H

#include <string>

using namespace std;

class Entry
{
	string name;  // holds they key/name
	string phone; // holds contact phone number
	float salary; // holds the contact salary

public:
	// constructor to set a new contact
	Entry(string name, string phone, float salary)
	{
		this->name = name;
		this->phone = phone;
		this->salary = salary;
	}
	string getKey() { return name; }		// Purpose: Returns the name of the contact
	string getPhone() { return phone; }		// Purpose: Returns the phone # of the contact
	float getSalary() { return salary; }	// Purpose: Returns the salary of the contact
	void setKey(string str) { name = str; } // Purpose: sets the key / name of the contact
};

class HashMap
{
public:
	// for throwing overflow errors
	class Overflow
	{
	};
	/*
	constructor  
	Creates a new HashMap
	Parameter: holds the hashmap capacity
	*/
	HashMap(int size);
	/*
	destructor  
	Destroys the hashmap
	*/
	~HashMap();
	// PURPOSE: Uses DJB(x33+b) Hashing function to create a key for storing our entry and returns its hashed value as an unsigned long
	//Parameter: string str (key to be hashed) in this case, the name of our contact.
	unsigned long myHash(string str);
	// PURPOSE: Adds a new entry to the hashmap by finding its key and placing it in the correct spot with collision handling
	//Parameter: Entry e holds the Contact to be added to the hashmap and data about it (key ect)
	void put(Entry *e);
	// PURPOSE: Retrieves the contact at the given key on the hashmap
	//Parameter: key holds the posistion of the contact entry on the hashmap
	Entry *get(string key);
	// PURPOSE: removes an entry at a specific key on the hashmap and replaces it with an empty entry
	//Parameter: key holds the posistion of the contact entry on the hashmap
	Entry *remove(string key);

protected:
	Entry **table; // holds the contacts
	int size;	   // holds the table size
};
#endif
/*
	Squidward from spongebob
        .--'''''''''--.
     .'      .---.      '.
    /    .-----------.    \
   /        .-----.        \
   |       .-.   .-.       |
   |      /   \ /   \      |
    \    | .-. | .-. |    /
     '-._| | | | | | |_.-'
         | '-' | '-' |
          \___/ \___/
       _.-'  /   \  `-._
     .' _.--|     |--._ '.
     ' _...-|     |-..._ '
            |     |
            '.___.'

	Do you guys actually read my comments??
*/