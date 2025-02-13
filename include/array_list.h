#pragma once
#include <iostream>
#include <ostream>
#include <fstream>
namespace ssuds
{
	/// <summary>
	/// 
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template <class T>
	class ArrayList
	{
	private:
		T* my_array;
		unsigned int my_array_size;
		unsigned int my_array_capacity;

		void grow()
		{
			unsigned int new_capacity = (my_array_capacity == 0) ? 1 : my_array_capacity * 2;
			reserve(new_capacity);
		}

		void shrink()
		{
			if (my_array_size < my_array_capacity / 4)
				reserve(my_array_capacity / 2);
		}

	public:
		ArrayList() : my_array(nullptr), my_array_size(0), my_array_capacity(0) {}

		~ArrayList()
		{
			delete[] my_array;
		}

		unsigned int size() const { return my_array_size; }

		void reserve(unsigned int new_capacity)
		{
			if (new_capacity > my_array_capacity)
			{
				T* new_array = new T[new_capacity];
				for (unsigned int i = 0; i < my_array_size; i++)
					new_array[i] = my_array[i];
				delete[] my_array;
				my_array = new_array;
				my_array_capacity = new_capacity;
			}
		}

		void append(const T& new_value)
		{
			if (my_array_size == my_array_capacity)
				grow();
			my_array[my_array_size++] = new_value;
		}

		void prepend(const T& new_value)
		{
			insert(new_value, 0);
		}

		void insert(const T& new_value, unsigned int index)
		{
			if (index > my_array_size)
				throw std::out_of_range("Index out of range");
			if (my_array_size == my_array_capacity)
				grow();
			for (unsigned int i = my_array_size; i > index; i--)
				my_array[i] = my_array[i - 1];
			my_array[index] = new_value;
			my_array_size++;
		}

		T& at(unsigned int index)
		{
			if (index >= my_array_size)
				throw std::out_of_range("Index out of range");
			return my_array[index];
		}

		T remove(unsigned int id)
		{
			if (id >= my_array_size)
				throw std::out_of_range("Index out of range");
			T removed_value = my_array[id];
			for (unsigned int i = id; i < my_array_size - 1; i++)
				my_array[i] = my_array[i + 1];
			my_array_size--;
			shrink();
			return removed_value;
		}

		int remove_all(const T& value)
		{
			int count = 0;
			for (int i = 0; i < (int)my_array_size; i++)
			{
				if (my_array[i] == value)
				{
					remove(i);
					count++;
					i--;
				}
			}
			return count;
		}

		int find(const T& search_value, unsigned int start_index = 0) const
		{
			for (int i = start_index; i < my_array_size; i++)
				if (my_array[i] == search_value)
					return i;
			return -1;
		}

		void output(std::ostream& os)
		{
			os << "[";
			for (int i = 0; i < my_array_size; i++)
			{
				os << my_array[i];
				if (i < my_array_size - 1)
					os << ", ";
			}
			os << "]";
		}
	};
}