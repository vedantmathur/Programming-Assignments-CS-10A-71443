/*
Vedant Mathur
CS 10A 71443
Programming Assignment 3: Simple Interest
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

// Function prototypes for the two functions needed
bool ReadInputRecord(ifstream& accountTerms, string& acctNum, float& principle, float& term, float& rate);
void WriteOutputRecord(ofstream& outputFile, string acctNum, float principle, float term, float rate);

// Global constants used
const int PRECISION = 2;
const int PERCENTAGE = 100;
const int DAYS_IN_YEAR = 365;
const int WIDTH_BEGINNING_BALANCE = 14, WIDTH_INTEREST_EARNED = 16, WIDTH_ENDING_BALANCE = 17;
const int FAIL_NUM = 0;
const string FAIL_STRING = "000000000";

int main()
{
	// Initialize Input and Output text files
	ifstream accountTerms;
	ofstream outputFile;
	accountTerms.open("Input.txt");
	outputFile.open("Output.txt");

	// Error if either one of them fail to open
	if (!accountTerms || !outputFile)
	{
		cout << "Unable to open file" << endl;

		// Close files, we don't want them to be left open.
		accountTerms.close();
		outputFile.close();

		return EXIT_FAILURE;
	}

	// Break out of loop when end of document is reached. Else, keep writing to Output file.
	while (true)
	{
		string acctNum;
		float principle, term, rate;

		if (!ReadInputRecord(accountTerms, acctNum, principle, term, rate)) break;

		WriteOutputRecord(outputFile, acctNum, principle, term, rate);
	}

	outputFile << "END OF REPORT" << endl;

	// Close files.
	accountTerms.close();
	outputFile.close();

	return EXIT_SUCCESS;
}

// ReadInputRecord reads one line of record, in the line, sequentially, are Acctnum, principle, term, and rate. Write to reference variables to the main program.
bool ReadInputRecord(ifstream& accountTerms, string& acctNum, float& principle, float& term, float& rate)
{
	// Write each value to each variable. 
	accountTerms >> acctNum;
	accountTerms >> principle;
	accountTerms >> term;
	accountTerms >> rate;

	// Check if the end of statement has been reached
	if (acctNum == FAIL_STRING && principle == FAIL_NUM && term == FAIL_NUM && rate == FAIL_NUM) return false;

	return true;
}

// WriteOutputRecord takes in each parameter we need to write to the Output. 
void WriteOutputRecord(ofstream& outputFile, string acctNum, float principle, float term, float rate)
{
	outputFile << fixed << setprecision(PRECISION);
	outputFile << "Account Number: " << acctNum << endl;
	outputFile << endl; // Skip 1 lines

	outputFile << "Beginning Balance: " << setw(WIDTH_BEGINNING_BALANCE) << right << principle << endl;
	float interestEarned = (principle * ((rate / PERCENTAGE) * (term / DAYS_IN_YEAR))); // I = principle * rate * time
	interestEarned = trunc(interestEarned * PERCENTAGE) / PERCENTAGE;
	outputFile << "Interest Earned: " << setw(WIDTH_INTEREST_EARNED) << right << interestEarned << endl;
	outputFile << "Ending Balance: " << setw(WIDTH_ENDING_BALANCE) << right << interestEarned + principle << endl;
	outputFile << endl << endl; // Skip 2 lines
}
