#include <iostream>
/*
int smaller(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
} */

/*template <class T>
T smaller(T a, T b)
{
	if (a < b)
		return a;
	else
		return b;
}
*/

template <class T>
class MyClass
{
private:
	T my_attr;
public:
	MyClass(T my_val)
	{
		my_attr = my_val;
	}

	MyClass()
	{

	}

	void set_value(T new_val)
	{

	}

	T get_value()
	{
		return my_attr;
	}
};

int main()
{
	MyClass<int> x;

	MyClass<std::string> s("abc");

	return 0;
}