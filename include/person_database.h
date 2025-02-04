//#pragma once
#ifndef _PERSON_DATABASE_H_    
#define _PERSON_DATABASE_H_ 
#include <person.h>
#include <string>

namespace example
{

	class PersonDatabase
	{
	private:
		Person* my_array;
		unsigned int my_array_size;
		std::string add;
		std::string remove;
		std::string print;

	public:
		PersonDatabase(std::string fname);

		~PersonDatabase();

		unsigned int get_num_people();
		void add_person(Person p);
		void remove_person(Person p);
		std::string to_string();
	};

}
#endif