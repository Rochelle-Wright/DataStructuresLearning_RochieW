#include "phone.h"
#include <iostream>


int main() 
{
	Phone phone;
	phone.run();

	std::cout << "\nPress Enter to exit...";
	std::cin.ignore();
	std::cin.get();
	return 0;
}