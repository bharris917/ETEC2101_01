#pragma once
#include <iostream>
#include <ostream>
#include <fstream>
namespace ssuds
{
	/// <summary>
	/// This is our template class
	/// </summary>
	/// <typeparam name="T"></typeparam>
	template <class T>
	/// <summary>
	/// The class we use for our array that holds all of our setters and getters.
	/// </summary>
	class ArrayList
	{
	private:
		/// <summary>
		/// my_array being assigned to T
		/// </summary>
		T* my_array;
		/// <summary>
		/// making the size of the array an integer but leaving it unsigned
		/// </summary>
		unsigned int my_array_size;
		/// <summary>
		/// making the capacity of the array (how many numbers can be in it) another unsigned int
		/// </summary>
		unsigned int my_array_capacity;

		/// <summary>
		/// grow is what makes the capacity expand when it potentially becomes full, uses the ? operator
		/// to determine if it needs to grom or if it should stay the same.
		/// </summary>
		void grow()
		{
			unsigned int new_capacity = (my_array_capacity == 0) ? 1 : my_array_capacity * 2;
			reserve(new_capacity);
		}
		/// <summary>
		/// shrink does the opposite of grow
		/// </summary>
		void shrink()
		{
			if (my_array_size < my_array_capacity / 4)
				reserve(my_array_capacity / 2);
		}

	public:
		class ArrayListIterator 
		{
		private:
			const ArrayList* my_array_list;
			int index;
		public:
			ArrayListIterator(const ArrayList* owning_list = nullptr, int starting_index = 0)
			{
				my_array_list = owning_list;
				index = starting_index;
			}

			bool operator!=(const ArrayListIterator& rhs) const 
			{
				return index != rhs.index;
			}

			/// <summary>
			/// This fumction makes a copy of our array, then changes the array, then returns the copy
			/// </summary>
			/// <returns></returns>
			ArrayListIterator& operator++() 
			{
				if (index < my_array_list->my_size) ++index;
				return *this;
			}

			ArrayListIterator operator++(int) 
			{
				ArrayListIterator temp = *this;
				++(*this);
				return temp;
			}
			/// <summary>
			/// This would let the + function work but i couldnt figure it out.
			/// </summary>
			/// <param name=""></param>
			/// <returns></returns>
			ArrayListIterator operator+(int) 
			{
				return ArrayListIterator();
			}

			T& operator*() const 
			{
				return my_array_list->my_list[index];
			}
		};

		

		ArrayList(std::initializer_list<T> init_list) : my_array_size(0), my_array_capacity(init_list.size()) 
		{
			my_array = new T[my_array_capacity];
			for (const T& item : init_list) 
			{
				my_array[my_array_size++] = item;
			}
		}

		ArrayList(const ArrayList& other) : my_array_size(other.my_size), my_array_capacity(other.my_array_capacity) 
		{
			my_array = new T[my_array_capacity];
			for (unsigned int i = 0; i < my_array_size; i++)
				my_array[i] = other.my_array[i];
		}

		ArrayList(ArrayList&& other) noexcept : my_array(other.my_array), my_array(other.my_array), my_array_capacity(
			other.my_array_capacity) 
		{
			other.my_array = nullptr;
			other.my_array_size = 0;
			other.my_array_capacity = 0;
		}
		/*
		~ArrayList() 
		{
			delete[] my_array;
		}
		*/
		ArrayList& operator=(const ArrayList& other) 
		{
			if (this != &other) {
				delete[] my_array;
				my_array_size = other.my_array_size;
				my_array_capacity = other.my_array_capacity;
				my_array = new T[my_array_capacity];
				for (unsigned int i = 0; i < my_array_size; i++)
					my_array[i] = other.my_array[i];
			}
			return *this;
		}

		ArrayList& operator=(ArrayList&& other) noexcept 
		{
			if (this != &other) {
				delete[] my_array;
				my_array = other.my_array;
				my_array_size = other.my_array_size;
				my_array_capacity = other.my_array_capacity;
				other.my_array = nullptr;
				other.my_array_size = 0;
				other.my_array_capacity = 0;
			}
			return *this;
		}

		ArrayListIterator begin() const 
		{ 
			return ArrayListIterator(this, 0);
		}
		ArrayListIterator end() const 
		{
			return ArrayListIterator(this, my_array_size); 
		}
		/// <summary>
		/// The default constructor
		/// </summary>
		ArrayList() : my_array(nullptr), my_array_size(0), my_array_capacity(0) {}
		/// <summary>
		/// The destructor
		/// </summary>
		~ArrayList()
		{
			delete[] my_array;
		}

		/// <summary>
		/// this is our size getter method
		/// </summary>
		/// <returns></returns>
		unsigned int size() const
		{
			return my_array_size;
		}

		/// <summary>
		/// The reserve method which will determine the capacity of the list(if called)
		/// </summary>
		/// <param name="new_capacity"></param>
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

		/// <summary>
		/// This method adds a new value to the array list but at the end
		/// </summary>
		/// <param name="new_value"></param>
		void append(const T& new_value)
		{
			if (my_array_size == my_array_capacity)
				grow();
			my_array[my_array_size++] = new_value;
		}

		/// <summary>
		/// This method also adds a new value to the array list except it'll be at the beginning. The 0 is what places
		/// it at the beginning
		/// </summary>
		/// <param name="new_value"></param>
		void prepend(const T& new_value)
		{
			insert(new_value, 0);
		}

		/// <summary>
		/// The insert method adds a new value to the list but it can be wherever in the list as long as it's within
		/// the capacity.
		/// </summary>
		/// <param name="new_value"></param>
		/// <param name="index"></param>
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

		/// <summary>
		/// This method takes an index and returns a reference to the item at that , if it doesn't work
		/// then it'll error.
		/// </summary>
		/// <param name="index"></param>
		/// <returns></returns>
		T& at(unsigned int index)
		{
			if (index >= my_array_size)
				throw std::out_of_range("Index out of range");
			return my_array[index];
		}

		/// <summary>
		/// This method is the counterpart to insert where you can remove a chosen index from
		/// anywhere in the list, as long as it is in range, if not it errors.
		/// </summary>
		/// <param name="id"></param>
		/// <returns></returns>
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

		/// <summary>
		/// This method will remove all instances of a value instead of an index.
		/// </summary>
		/// <param name="value"></param>
		/// <returns></returns>
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

		/// <summary>
		/// This method finds (hehe) the index of a selected value, which is the search_value and the start_index is
		/// how many spots from the value in the list.
		/// </summary>
		/// <param name="search_value"></param>
		/// <param name="start_index"></param>
		/// <returns></returns>
		int find(const T& search_value, unsigned int start_index = 0) const
		{
			for (int i = start_index; i < my_array_size; i++)
				if (my_array[i] == search_value)
					return i;
			return -1;
		}

		/// <summary>
		/// The output method is what prints out the list and formats it correctly.
		/// </summary>
		/// <param name="os"></param>
		void output(std::ostream& os)
		{
			os << "[";
			for (int i = 0; i < my_array_size; i++)
			{
				os << my_array[i];
				if (i < my_array_size - 1)
					os << ", ";
			}
			os << "]" << "\n";
		}
	};
}