// Lab9.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "HashTable.h"
#include "Patient.h"

void buildTable(HashTable*, int, string);

int main()
{
	//HashTable* tableBad;
	//HashTable* tableBetter = new HashTable();
	//HashTable* tableBest = new HashTable();
	int choice = 0;
	bool good = true;

	while (choice != 4) {
		cout << "Select the hash type to process: " << endl;
		cout << "\t1 - Bad Hash Function" << endl;
		cout << "\t2 - Better Hash Function" << endl;
		cout << "\t3 - Best Hash Function" << endl;
		cout << "\t4 - Exit" << endl;

		cin >> choice;
		
		while (choice < 1 || choice > 4) {
			cout << "You entered an invalid option. Please select a number between 1-4." << endl;
			cin >> choice;
		}
		HashTable* tableBad = new HashTable();
		HashTable* tableBetter = new HashTable();
		HashTable* tableBest = new HashTable();

		switch (choice) {
		case 1:
			buildTable(tableBad, 1, "patientsPriorities.csv");
			tableBad->displayHashTable();
			
			break;
		case 2:
			buildTable(tableBetter, 2, "patientsPriorities.csv");
			tableBetter->displayHashTable();
			
			break;
		case 3:
			buildTable(tableBest, 3, "patientsPriorities.csv");
			tableBest->displayHashTable();
			
			break;
		case 4:
			exit(0);
		default:
			break;

		}
		delete(tableBad);
		delete(tableBetter);
		delete(tableBest);
	}
}	//end of main


/**
This method takes input from a file and populates a hashTable with the data in the file.

@param table – the HashTable to store data
@param hashFunction - an int corresponding to the has function to use (1 = bad, 2 = better, 3 = best);
@param inputFile - the filename to use for input data

*/
void buildTable(HashTable* table, int hashFunction, string inputFile) {

	ifstream infile;
	string temp = "";


	try {
		infile.open(inputFile);
	}//end of try
	catch (const ifstream::failure& e) {
		cout << "Error opening file." << e.what() << endl;
		return;

	}//end of catch
	getline(infile, temp);	//get headers from input file

	while (!infile.eof()) {

		// read the line
		getline(infile, temp);
		if (!temp.empty()) {
			Patient* pat = new Patient(temp);
			table->insert(*pat, hashFunction);
			//cout << "inserted patient " << pat->getPatientName() << "into hashtable." << endl;
		}

	}
	infile.close();

}//end buildTable()


