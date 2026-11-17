#include "contacts.h"
#include <iostream>

Contacts::Contacts()
{
	currentSize = 0;
}

void Contacts::addContact(const std::string& name, const std::string& phoneNum) 
{
	if (currentSize >= MAX_CONTACTS) 
	{
		std::cout << "ERROR: This contact list is full \n";
		return;
	}

	contactList[currentSize].name = name;
	contactList[currentSize].phoneNum = phoneNum;
	currentSize++;
	std::cout << "Contact Added!";
}

bool Contacts::searchContact(const std::string& name) 
{
	for (int i = 0; i < currentSize; i++)
	{
		if (contactList[i].name == name) 
		{
			std::cout << "Found " << contactList[i].name 
				<< " - " << contactList[i].phoneNum
				<< "! \n";
			return true;
		}
	}

	std::cout << "Contact not found!";
	return false;
}

void Contacts::displayAll() const
{
	if (currentSize == 0) 
	{
		std::cout << "Contact list is currently empty \n";
		return;
	}
	for (int i = 0; i < currentSize; i++) 
	{
		std::cout << i + 1 << ". " << contactList[i].name
			<< " (" << contactList[i].phoneNum << ")\n";
	}
}

void Contacts::runMenu()
{
    int choice = 0;
    while (choice != 4)
    {
        std::cout << "\n--- Contacts ---\n"
            << "1. Add Contact\n"
            << "2. Search Contact (Linear)\n"
            << "3. Display All\n"
            << "4. Back to Main Menu\n"
            << "Choice: ";

        std::string input;
        std::getline(std::cin, input);

        if (input.empty()) continue; // If they just hit Enter, ask again

        try {
            choice = std::stoi(input);
        }
        catch (...) {
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            std::string name, phone;
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            std::cout << "Enter phone number: ";
            std::getline(std::cin, phone);
            addContact(name, phone);
        }

        else if (choice == 2) {
            std::string name;
            std::cout << "Enter name to search: ";
            std::getline(std::cin, name);
            searchContact(name);
        }
        else if (choice == 3) {
            displayAll();
        }
    }
}