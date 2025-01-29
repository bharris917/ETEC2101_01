//#pragma once
#ifndef _PERSON_DATABASE_H_    
#define _PERSON_DATABASE_H_ 
#include <person.h>
#include <string>

using namespace example;


	class Person_Database
	{
	private:
		Person* num_people;
		unsigned int num_people_size;
		std::string add;
		std::string remove;
		std::string print;

	public:
		Person_Database();

		Person_Database(std::string fname);

		~Person_Database();

		unsigned int get_num_people();
		std::string add_person();
		std::string remove_person();
		std::string to_string();
	};


#endif