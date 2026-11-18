#pragma once
#include <string>

struct MessageNode 
{
	std::string content;
	MessageNode* next;
};

class TextThread
{
public:
	TextThread(); //Constructor
	~TextThread(); //Destructor (what does it mean to clean up memory? how does this do that?)

	void addMessage(const std::string& content); // Add to last
	void displayThread() const;                  // Traversal
	void deleteMessage(int index);               // Delete a specific message
	void runMenu();

private:
	MessageNode* head_; // Points to the first message
	MessageNode* tail_; // Points to the last message (makes adding to the end O(1))
	int messageCount_;
};