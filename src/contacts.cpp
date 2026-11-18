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

    //adding out new contact to the end of the list
	contactList[currentSize].name = name;
	contactList[currentSize].phoneNum = phoneNum;
	currentSize++;

    sortContacts();
    std::cout << "Contact Added!";

}

//Insertion sort
void Contacts::sortContacts() 
{
    // Starting from the second element [index 1] because 1 is already sorted. 
    // We just need figure out is the numbers being added after it are 
    // higher (moved right) or lower (moved left) than it.

    for (int i = 0; i < currentSize; i++) 
    {
        Contact currContact = contactList[i];
        int j = i - 1;

        //Compare each letter in the contact name against each letter in curr contact name. 
        //j starts at the end of the array and goes down by 1 each check.
        while (j >= 0 && contactList[j].name > currContact.name) // is the j name greater than the new name we need to sort?
        {
            contactList[j + 1] = contactList[j]; // ... no, so we need to leave this j name where it is and move on.
            j = j - 1;
        }

        //...yes! so we can insert the currContact into its correct sorted spot
        contactList[j + 1] = currContact;
    }
}

bool Contacts::binarySearchContact(const std::string& name) 
{
    int left = 0; //These are index numbers
    int right = currentSize - 1;

    while (left <= right) 
    {
        int mid = left + (right - left) / 2; // Find the middle index
        if (contactList[mid].name == name) 
        {
            std::cout << "Found! " << contactList[mid].name
                << " - " << contactList[mid].phoneNum << "\n";
            return true;
        }
        else if(contactList[mid].name < name) //left in the list
        {
            // The name we want is alphabetically AFTER the middle.
            // Throw away the left half.
            left = mid + 1;
        }
        else //right in the list
        {
            // The name we want is alphabetically BEFORE the middle.
            // Throw away the right half.
            right = mid - 1;
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
            << "2. Search Contact (Binary)\n"
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
            binarySearchContact(name);
        }
        else if (choice == 3) {
            displayAll();
        }
    }
}