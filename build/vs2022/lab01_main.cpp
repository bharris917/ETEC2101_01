#include <iostream>
#include "person.h"
#include "person_database.h"

int main()
{
	// In this construcotr, you'll read in the conents of the 
	// text file into an array of Person objects. DO NOT use any
	// container types (std::vector, std::list, etc.)
	example::PersonDatabase PD("..\\..\\media\\persondb.txt");
	int x;


	while (true)
	{
		
		std::cout << "==================\n";
		std::cout << "1. Add Person\n";
		std::cout << "2. Remove Person\n";
		std::cout << "3. Print\n";
		std::cout << "4. Quit\n";
		std::cout << "==================\n";
		std::cin >> x;
		switch (x)
		{
			case 1:
			{

			int id;
			std::string first_name, last_name;
			float hourly_rate;
			unsigned int hours_worked;

			std::cout << "Enter ID: ";
			std::cin >> id;
			std::cout << "Enter First Name: ";
			std::cin >> first_name;
			std::cout << "Enter Last Name: ";
			std::cin >> last_name;
			std::cout << "Enter Hours Worked: ";
			std::cin >> hours_worked;
			std::cout << "Enter Hourly Rate: ";
			std::cin >> hourly_rate;


			try
			{
				example::Person new_person(id, first_name, last_name);
				new_person.set_hourly_rate(hourly_rate);
				new_person.set_hours_worked(hours_worked);

				PD.add_person(new_person);
			}
			catch (std::runtime_error& e)
			{
				std::cout << "Error: " << e.what() << std::endl;
			}
			break;
			}
			case 3:
			{
				std::cout << PD.to_string();
				break;
			}
			case 4:
			{
				return 0;
			}
		}
		
	}
	
	return 0;
}