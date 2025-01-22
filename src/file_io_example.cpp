#include <iostream>
#include <string>
#include <fstream>			// Access to fstream, ofstream, ifstream

#define MAIN_MODE 1		// 0=output, 1=input
#define fname "..\\..\\media\\test.txt"

int main(int argc, char** argv)
{
#if MAiN_MODE == 0

	//std::ofstream fout;
	//fout.open("test.txt")

	int x = 42;
	float y = 3.1f;
	std::string s = "hello world";
	//std::ofstream fout("../../media/test.txt");		// Have a connection to that file (makes
										// the file no matter what, or overwrites it)
	std::ofstream fout(fname);
	fout << x << ":" << y << ":" << s << "\n";
	x++;
	y++;
	s += "xxx";
	fout << x << ":" << y << ":" << s << "\n";

	fout.close();
#else
	// Alternate main program (for input)
	std::ifstream fin(fname);
	if (fin.is_open())
	{
		std::cout << "Error opening file" << fname << "'\n";
		return 1;
	}

	int x2;
	float y2;
	std::string s2;

	// This would have worked if we had whitespace
	//fin >> x2 >> y2 >> s2;
	while (!fin.eof())
	{

		// Note: the end of file (eof) function doesn't becmoe true
		// until we try to read past the end of the file.
		fin << x2;
		if (fin.eof())
			break;

		fin.ignore(1000, ':');
		fin << y2;
		fin.ignore(1000, ':');
		//fin << s2;
		std::getline(fin, s2);

		std::cout << "Values read in: \n\tx2=" << x2 << "\n\ty2=" << y2 << "\n\ts2='" << s2 << "'\n";
	}
#endif
	
	return 0;
}