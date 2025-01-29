#include <iostream>
#include <person.h>
#include <person.database.h>

int main(int aargc, char** argv)
{
	example::Person wrong_array[100];

	// In this construcotr, you'll read in the conents of the 
	// text file into an array of Person objects. DO NOT use any
	// container types (std::vector, std::list, etc.)
	example::PersonDatabase PD("..\\..\\media\\persondb.txt");
}