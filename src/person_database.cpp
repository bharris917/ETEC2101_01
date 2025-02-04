#include <person_database.h>
#include <person.h>
#include <iostream>
#include <fstream>

example::PersonDatabase::PersonDatabase(std::string fname)
{
	my_array = nullptr;
	my_array_size = 0;

	std::ifstream fin(fname);
	if (fin.is_open())	
	{
		while (true)
		{
			int temp_id;
			std::string temp_fname, temp_lname;
			float temp_hourly_rate;
			unsigned int temp_hours;

			if (!fin.eof())
			{
				example::Person temp_person(temp_id, temp_fname, temp_lname);
				temp_person.set_hourly_rate(temp_hourly_rate);
				temp_person.set_hours_worked(temp_hours);

				example::PersonDatabase::add_person(temp_person);
			}
		}
	}
	fin.close();
}



void example::PersonDatabase::add_person(example::Person p)
{
	if (my_array_size == 0)
	{
		my_array = new Person[1];
		my_array[0];
		my_array_size = 1;
	}

	if (my_array_size > 0)
	{
		my_array = new Person[1];
		my_array_size++;
	}
	else
	{
		return 1;
	}

	
}



void example::PersonDatabase::remove_person(example::Person p)
{
	my_array--;
	my_array_size = my_array;
}

