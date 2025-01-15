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

class Person
{
    // These are ATTRIBUTES -- variables that each instance of the class
    // gets a copy of.
    // By default all members of a class are PRIVATE (we can only
    //   access them in a method).  Normally we make our attributes private
    //   but methods public.
private:
    int id;
    std::string first_name;
    std::string last_name;
    float hourly_rate;
    unsigned int hours_worked;

public:
    //Constructor
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
    void set_hourly_rate(float new_rate);
    void set_hours_worked(unsigned int new_hours);

    // This is a METHOD -- a function that all instances of the class can
    // use.  This is a DECLARATION.  
    float calculate_wage();
};

#endif