// ask for a person's name, and generate a framed greeting
#include <iostream>
#include <string>

int main()
{
	const std::string exclam = "!";
	// cannot concatenate string literal with string literal
	const std::string message = "Hello" + ", world" + exclam;

	// write it all
	std::cout << exclam << std::endl;
	std::cout << message << std::endl;
	return 0;
}