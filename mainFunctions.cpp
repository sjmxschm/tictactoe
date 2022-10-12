/*
mainFunctions.cpp includes all needed functions which are not part of a class
*/

# include <string>
# include <iostream>
using std::string;
using std::cout;
using std::cin;

int* getRowColumnFromUser(string pname) {
	static int result[2];

	int row;
	int column;

	// promt user to input data
	cout << pname << ", please specify row:\n";
	cin >> row;
	row -= 1;			// take care that indexing in C++ start at 0
	cout << pname << ", please specify column:\n";
	cin >> column;
	column -= 1;		// take care that indexing in C++ start at 0

	result[0] = row;
	result[1] = column;

	return result;
}