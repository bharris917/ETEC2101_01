#include <person_database.h>
#include <person.h>
#include <iostream>
#include <fstream>

example::PersonDatabase::PersonDatabase(std::string PD)
{
	my_array = nullptr;
	my_array_size = 0;
	capacity = 10;
	my_array = new Person[capacity];

	std::ifstream fin(PD);
	if (fin.is_open())	
	{
		while (true)
		{
			int id;
			std::string fname, lname;
			float hourly_rate;
			unsigned int hours_worked;

			std::ifstream fin(PD);
			fin >> id >> fname >> lname >> hourly_rate >> hours_worked;

			if (!fin.eof())
			{
				example::Person person(id, fname, lname);
				person.set_hourly_rate(hourly_rate);
				person.set_hours_worked(hours_worked);
			}
		}
	}
	fin.close();
}

example::PersonDatabase::~PersonDatabase()
{
	std::fstream outfile("..\\..\\media\\persondb.txt", std::ios::out);
	if (outfile)
	{
		for (int i = 0; my_array_size; i++)
		{
			outfile << my_array[i].get_id() << " "
				<< my_array[i].get_first_name() << " "
				<< my_array[i].get_last_name() << " "
				<< my_array[i].get_hourly_rate() << " "
				<< my_array[i].get_hours_worked() << "\n";
		}
	}
	delete[] my_array;

}



void example::PersonDatabase::add_person(example::Person& p)
{
	if (my_array_size < capacity)
	{
		my_array[my_array_size++] = p;
	}
	else
	{
		std::cout << "Database is full. Try later \n";
	}

	
}



void example::PersonDatabase::remove_person(example::Person& p)
{
	Person* old_people = new Person[my_array_size - 1];
	for (int i = 0; i < my_array_size; ++i) 
	{
		old_people[i] = my_array[i];
	}
	old_people[my_array_size] = p;
	delete[] my_array;
	my_array = old_people;
	--my_array_size;

}

std::string example::PersonDatabase::to_string()
{
	float total_salary = 0.0f;

	std::cout << "============================\n";
	for (int i = 0; i < my_array_size; ++i)
	{
		example::Person person = my_array[i];
		float wage = person.calculate_wage();
		total_salary += wage;
		std::cout << "|ID|  |Fname| |Lname| |Hours Worked| |Hourly Rate|  |Wage|\n"
			<< person.get_id() << "	\t"
			<< person.get_first_name() << " "
			<< person.get_last_name() << " \t"
			<< person.get_hours_worked() << " \t"
			<< person.get_hourly_rate() << " \t"
			<< wage<< "\n";
	}

	return 0;

}
