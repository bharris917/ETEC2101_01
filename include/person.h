// The #pragma once is a short-hand for the #ifndef/#define/.../#endif thing
// The purpose of both is to prevent the compiler from ever seeing the declaration
// of this class twice (which would cause an error)

// person.h
// #pragma once       // does the same compiler guard as below
#ifndef _PERSON_H_    // "compiler guard" -- makes sure this
#define _PERSON_H_    //   header file (and the stuff within it...our
                      //   class declaration) is only seen once by the
                      //   compiler
#include <string>

namespace example
{
    /// <summary>
    /// This is a class that illustrates how to use OOP concepts in C++
    /// </summary>
    class Person
    {
        // These are ATTRIBUTES -- variables that each instance of the class
        
    private:
        int id;
        /// <summary>
        /// This is the first name
        /// </summary>
        std::string first_name;
        std::string last_name;
        float hourly_rate;
        unsigned int hours_worked;

    public:
        //Constructor

        /// <summary>
        /// This is the default constructor for the Person class
        /// </summary>
        Person();

        Person(int starting_id, std::string start_fname, std::string start_lname);

        // Destructor (called when an instance is about to be destroyed)
        ~Person();

        // GETTER methods
        int get_id();
        std::string get_first_name();
        std::string get_last_name();
        float get_hourly_rate();
        unsigned int get_hours_worked();

        //SETTER methods
        
        /// <summary>
        /// This sets the hourly rate
        /// </summary>
        /// <param name="new_rate"> This is the new rate</param>

        void set_hourly_rate(float new_rate);
        void set_hours_worked(unsigned int new_hours);

        // This is a METHOD -- a function that all instances of the class can
        // use.  This is a DECLARATION.  

        /// <summary>
        /// A getter for wage
        /// </summary>
        /// <returns>The wage for this person in dollars for this month</returns>

        float calculate_wage();
    };
}
#endif