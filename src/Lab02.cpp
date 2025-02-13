#include <array_list.h>			// Kind of like vector
#include <iostream>


int main(int argc, char** argv)
{
	ssuds::ArrayList<int> ilist;
	ilist.append(42);
	ilist.append(43);
	ilist.append(44);
	ilist.prepend(41);
	ilist.prepend(40);

	for (int i = 0; i < ilist.size(); i++)
		std::cout << "ilist[" << i << "] = " << ilist.at(i) << "\n";

	// [40, 41, 42, 43, 44]
	ilist.append(40);
	ilist.append(43);
	ilist.append(99);
	ilist.append(43);
	ilist.append(98);
	// [40, 41, 42, 43, 44, 40, 43, 99, 43, 98]
	int test = ilist.find(43);			// Should return 3
	int test2 = ilist.find(43, 4);			// Should return 6
	int test3 = ilist.find(43, 7);			// Should return 8
	int test4 = ilist.find(43, 9);			// Should return -1
	int test5 = ilist.find(104);				// Should return -1

	std::cout << "test 1 = " << test << "\n";
	std::cout << "test 2 = " << test2 << "\n";
	std::cout << "test 3 = " << test3 << "\n";
	std::cout << "test 4 = " << test4 << "\n";
	std::cout << "test 5 = " << test5 << "\n";


	ilist.output(std::cout);			// [40, 41, 42, 43, 44, 40, 43, 99, 43, 98]
	ilist.remove(1);
	ilist.output(std::cout);			// [40, 42, 43, 44, 40, 43, 99, 43, 98]


	ilist.remove_all(40);
	ilist.output(std::cout);			// [42, 43, 44, 43, 99, 43, 98]
	
	std::ofstream fout("test.txt");
	ilist.output(fout);

}
