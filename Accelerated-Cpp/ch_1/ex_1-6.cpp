// The user is not prompted for input again if at the
// first instance two names (such as "Samuel Beckett")
// are provided. It will just use "Beckett" as the input for
// the second prompt as it is still present in the buffer.
#include <iostream>
#include <string>

int main()
{
	std::cout << "What is your name? ";
	std::string name;
	std::cin >> name;
	std::cout << "Hello, " << name
	          << std::endl << "And what is yours? ";
	std::cin >> name;
	std::cout << "Hello, " << name
	          << "; nice to meet you too!" << std::endl;
	return 0;
}