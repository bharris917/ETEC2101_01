#include <iostream>
#include <person.h>
#include <person_database.h>

int main(int aargc, char** argv)
{
	int x;
	std::cout << "==================";
	std::cout << "1. Add Person";
	std::cout << "2. Remove Person";
	std::cout << "3. Print";
	std::cout << "4. Quit";
	std::cout << "==================";
	std::cin >> x;
	if (x == 4)
	{
		return 0;
	}

	// In this construcotr, you'll read in the conents of the 
	// text file into an array of Person objects. DO NOT use any
	// container types (std::vector, std::list, etc.)
	example::PersonDatabase PD("..\\..\\media\\persondb.txt");
}