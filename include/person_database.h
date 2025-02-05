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
		/// <summary>
		/// it's what holds all of the data
		/// </summary>
		Person* my_array;
		/// <summary>
		/// the total size of the array
		/// </summary>
		unsigned int my_array_size;
		/// <summary>
		/// makes sure the data can't go over a certain amount
		/// </summary>
		int capacity;
		

	public:
		PersonDatabase(std::string fname);

		~PersonDatabase();
		/// <summary>
		/// gets the number of people
		/// </summary>
		/// <returns></returns>
		unsigned int get_num_people();
		/// <summary>
		/// adds a person
		/// </summary>
		/// <param name="p"></param>
		void add_person(Person& p);
		/// <summary>
		/// removes a person
		/// </summary>
		/// <param name="p"></param>
		void remove_person(Person& p);
		/// <summary>
		/// converts data to a string
		/// </summary>
		/// <returns></returns>
		std::string to_string();
	};

}
#endif