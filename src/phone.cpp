#include "phone.h"
#include <iostream>

Phone::Phone() 
{
    isRunning = true;
}

void Phone::run()
{
    while (isRunning)
    {
        printMainMenu();

        std::string input;
        // 1. Read the entire line (waits for you to hit Enter)
        if (!std::getline(std::cin, input)) {
            break; // If the stream dies completely, exit safely
        }

        // 2. If they just hit Enter without typing, ask again
        if (input.empty()) {
            continue;
        }

        // 3. Try to convert their text into a number
        try {
            int choice = std::stoi(input);
            handleChoice(choice);
        }
        catch (...) {
            // 4. If they typed a word (like "apple"), stoi throws an error
            std::cout << "Invalid input. Please enter a number.\n";
        }
    }
}

void Phone::printMainMenu() const
{
	std::cout << "\n===== PhoneSim =====\n"
        << "1. Contacts\n"
        << "2. Call Log\n"
        << "3. Notifications\n"
        << "4. Recent Apps\n"
        << "5. Texts\n"
        << "6. Priority Texts\n"
        << "7. Navigation\n"
        << "8. Auto-Reply\n"
        << "0. Exit\n"
        << "Choice: ";
}

void Phone::handleChoice(int choice) {
    switch (choice) {
    case 1: featureContacts();      break;
    case 2: featureCallLog();       break;
    case 3: featureNotifications(); break;
    case 4: featureRecentApps();    break;
    case 5: featureTexts();         break;
    case 6: featurePriority();      break;
    case 7: featureNavigation();    break;
    case 8: featureAutoReply();     break;
    case 0: isRunning = false;       break;
    default:
        std::cout << "Invalid choice.\n";
    }
}

void Phone::featureContacts() { myContacts.runMenu(); }
void Phone::featureCallLog() { std::cout << "[Call Log] not implemented yet.\n"; }
void Phone::featureNotifications() { std::cout << "[Notifications] not implemented yet.\n"; }
void Phone::featureRecentApps() { std::cout << "[Recent Apps] not implemented yet.\n"; }
void Phone::featureTexts() { std::cout << "[Texts] not implemented yet.\n"; }
void Phone::featurePriority() { std::cout << "[Priority] not implemented yet.\n"; }
void Phone::featureNavigation() { std::cout << "[Navigation] not implemented yet.\n"; }
void Phone::featureAutoReply() { std::cout << "[Auto-Reply] not implemented yet.\n"; }