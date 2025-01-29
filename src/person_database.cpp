#include <person_database.h>
#include <person.h>
#include <iostream>

example::Person_Database::Person_Database()
{
	my_array = nullptr;
	my_array_size = 0;
	while(???)
	{
		int temp_id;
		std::string temp_fname, temp_lname;
		float temp_hourly_rate;
		unsigned int temp_hours;
	}
	if (? ? ? )
	{
		Person temp_person(temp_id, temp_fname, temp_lname);
		temp_person.set_hourly_rate(temp_hourly_rate);
		temp_person.set_hours_worked(temp_hours_worked);

		add_person(temp_person);
	}
}

void example::PersonDatabase::add_person(example::Person p)
{
	if (my_array_size == 0)
	{
		my_array = new Person[1];
		my_array[0];
		my_array_size = 1;
	}

	else
	{

	}
}