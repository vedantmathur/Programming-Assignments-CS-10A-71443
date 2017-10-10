// Vedant Mathur
// Assignment 1 - Schedule of Classes
// Grade: 100/100 A
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

const int COURSE_WIDTH = 40;
const int PROF_WIDTH = 28;
const int MAX_WIDTH = 79;


int main()
{
	// Intialize variables to use throughout the program
	string class1, class2, class3, class4, class5;
	string prof1, prof2, prof3, prof4, prof5;

	// Introduction to the program
	cout << "Welcome to your schedule" << endl;

	// Ask for the first class
	cout << "Name your first class" << endl;
	// Input using getline
	getline(cin, class1);

	// Do the same for professor for that class
	cout << "Name the professor for " << class1 << endl;
	getline(cin, prof1);

	// Repeat 5 times (4 more beyond here)
	cout << "Name your second class" << endl;
	getline(cin, class2);
	cout << "Name the professor for " << class2 << endl;
	getline(cin, prof2);
	cout << "Name your third class" << endl;
	getline(cin, class3);
	cout << "Name the professor for " << class3 << endl;
	getline(cin, prof3);
	cout << "Name your fourth class" << endl;
	getline(cin, class4);
	cout << "Name the professor for " << class4 << endl;
	getline(cin, prof4);
	cout << "Name your fifth class" << endl;
	getline(cin, class5);
	cout << "Name the professor for " << class5 << endl;
	getline(cin, prof5);

	// Begin increment at 1
	int courseNumber = 1;

	// Making the dashed line. Set the first and last characters to a plus (+) sign. MAX_WIDTH should be subtracted by one due to the plus signs 
	cout << endl << '+' << setfill('-') << setw(MAX_WIDTH - 1) << right << '+';
	// Reset the setfill so it doesn't affect the rest of the output
	cout << setfill(' ');

	cout << endl << "| " << courseNumber << " | " << setw(COURSE_WIDTH) << right << class1 << " | " << setw(PROF_WIDTH) << left << prof1 << " |";
	courseNumber++;							    
	cout << endl << "| " << courseNumber << " | " << setw(COURSE_WIDTH) << right << class2 << " | " << setw(PROF_WIDTH) << left << prof2 << " |";
	courseNumber++;								 																						  
	cout << endl << "| " << courseNumber << " | " << setw(COURSE_WIDTH) << right << class3 << " | " << setw(PROF_WIDTH) << left << prof3 << " |";
	courseNumber++;								 																						  
	cout << endl << "| " << courseNumber << " | " << setw(COURSE_WIDTH) << right << class4 << " | " << setw(PROF_WIDTH) << left << prof4 << " |";
	courseNumber++;								 																						  
	cout << endl << "| " << courseNumber << " | " << setw(COURSE_WIDTH) << right << class5 << " | " << setw(PROF_WIDTH) << left << prof5 << " |";

	// ending dashed line
	cout << endl << '+' << setfill('-') << setw(MAX_WIDTH - 1) << right << '+' << endl;
	cout << setfill(' ');
	// Reset setfill for future expansion if necessary

	return 0;
}
