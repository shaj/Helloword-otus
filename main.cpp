#include <iostream>
#include "lib.h"


int main(int argc, char const *argv[])
{
	std::cout << "Hello, World!" << std::endl;
	std::cout << "Version " << version_major() << ".";
	std::cout << version_minor() << ".";
	std::cout << version_patch() << std::endl;
	return 0;
}
