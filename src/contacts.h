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
	bool searchContact(const std::string& name);
	void displayAll() const;
	void runMenu();

private:
	static const int MAX_CONTACTS = 20;
	Contact contactList[MAX_CONTACTS];
	int currentSize;

};