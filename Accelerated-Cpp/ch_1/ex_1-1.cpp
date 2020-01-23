// ask for a person's name, and generate a framed greeting
#include <iostream>
#include <string>

int main()
{
	const std::string hello = "Hello";
	const std::string message = hello + ", world" + "!";

	// write it all
	std::cout << hello << std::endl;
	std::cout << message << std::endl;
	return 0;
}