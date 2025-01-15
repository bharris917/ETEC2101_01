#include <person.h>		// why "" instead of <>?

//We're providing the BODY / DEFINITION of the method we declared in our h file
float Person::calculate_pay()
{
	// In any (non_static) method, we have access to all attributes for this 
	// instance. Our job in this method is to tell the compiler HOW to
	// calculate a wage using our attributes.
	return hourly_rate * hours_worked;
}