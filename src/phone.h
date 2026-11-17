#pragma once
#include "contacts.h"
#include <string>

class Phone {
public: 
	Phone();
	void run();

private:
	Contacts myContacts;

	void printMainMenu() const;
	void handleChoice(int choice);

	void featureContacts();
	void featureCallLog();
	void featureTextLog();
	void featureNotifications();
	void featureRecentApps();
	void featureTexts();
	void featurePriority();
	void featureNavigation();
	void featureAutoReply();
	
	bool isRunning = true;
};