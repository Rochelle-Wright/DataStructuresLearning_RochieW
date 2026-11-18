#pragma once
#include <string>

struct Contact 
{
	std::string name;
	std::string phoneNum;
};

class Contacts 
{
public: 
	Contacts();

	void addContact(const std::string& name, const std::string& phoneNum);
	bool binarySearchContact(const std::string& name); //before we were checking 1 by 1. Now we'll be sectioning our data
	void displayAll() const;
	void runMenu();

private:
	static const int MAX_CONTACTS = 20;
	Contact contactList[MAX_CONTACTS];
	int currentSize;

	void sortContacts();
};