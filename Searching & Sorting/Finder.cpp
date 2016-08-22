#include "SearchSort.hpp"
#include<fstream>
using std::fstream;
using std::ios;
#include<string>
using std::string;
#include<iostream>
using std::cout;
using std::cin;
using std::endl;
#include<cstdlib>


int main() {
	int anInt;		// Utility int for reading in ints.
	int count = 0;		// Utiltiy var for determining number of ints in txt file.
	fstream inFile;		// Our input stream for reading.
	fstream inFile2;	// Our second input stream object.
	fstream outFile;	// Our output stream for writing.
	SearchSort my;		// A SearchSort object!
	int i;			// For loop utility var.
	int seek;		// The Int we seek.
	int result;		// The subscript location returned.
	int file;		// Which file to read cin collection var.
	string fileName;	// Utility string for reading in user file to write to.
	int check;		// Utiliy user menu control var for cin collection.
	int sorter;		// Utility user menu control var for which sort algorithm to use.

	// USER MENU FOR SEARCH
	cout << endl << "WELCOME TO THE SEARCH DEMO!" << endl << endl
		<< "What int do you seek? (Range of ints is 0 - 25," << endl
		<< "except fileNone.txt, which has no \"0\".)" << endl;
	cin >> seek;
	cout << "Which file would you like to search?" << endl
		<< "The name refers to where the \"0\" is located!" << endl
		<< "Select 1 for fileFront.txt" << endl
		<< "Select 2 for fileMiddle.txt" << endl
		<< "Select 3 for fileEnd.txt" << endl
		<< "Select 4 for fileNone.txt" << endl
		<< "Select 0 to quit!" << endl;
	cin >> file;

	// Input validation.
	while (file < 0 || file > 4) {
		cout << "Error!" << endl
			<< "Which file would you like to search?" << endl
			<< "Select 1 for fileFront.txt" << endl
			<< "Select 2 for fileMiddle.txt" << endl
			<< "Select 3 for fileEnd.txt" << endl
			<< "Select 4 for fileNone.txt" << endl
			<< "Select 0 to Quit!" << endl;
		cin >> file;
	}

	// Exit if Quit selected.
	if (file == 0) { exit(EXIT_SUCCESS); }

	// Open chosen file name.
	switch (file) {
	case 1:
		inFile.open("fileFront.txt");
		break;
	case 2:
		inFile.open("fileMiddle.txt");
		break;
	case 3:
		inFile.open("fileEnd.txt");
		break;
	case 4:
		inFile.open("fileNone.txt");
		break;
	}

	// Handle file not found error.
	if (inFile.fail()) {
		cout << endl << "File not found!" << endl;
	}else{
		// Determine how many ints are in the text file and update count var.
		while (inFile.good()) {
			inFile >> anInt;
			count++;
		}
		inFile.clear();				// Clear EOF flag
		inFile.seekg(0L, ios::beg);		// Rewind txt file to beginning.

		// Our holding array for read in int values from the text file.
		int *anArray = new int[count];

		// Read in the text file int values to our anArray.
		while (inFile.good()) {
			for (i = 0; i < count; i++) {
				inFile >> anArray[i];
			}
		}

		result = my.linearSearch(anArray, count, seek);

		if (result != -1)
			cout << endl << "Using a linear search, I've found the int " << seek << " at array subscript location: " << result << endl;
		else
			cout << endl << "Using a linear search, I could not find " << seek << " in the file" << endl;

		cout << endl << "Here are the values that I read in from the file so you can check!" << endl;

		my.showArray(anArray, count);

		delete[] anArray;
		*anArray = 0;
	}
	inFile.close();

	//Reset count.
	count = 0;


	// USER MENU FOR SORT
	cout << endl << "WELCOME TO THE SORT DEMO!" << endl << endl
		<< "Which file would you like to sort?" << endl
		<< "Select 1 for fileFront.txt" << endl
		<< "Select 2 for fileMiddle.txt" << endl
		<< "Select 3 for fileEnd.txt" << endl
		<< "Select 4 for fileNone.txt" << endl
		<< "Select 0 to quit!" << endl;
	cin >> file;

	// Input validation.
	while (file < 0 || file > 4) {
		cout << "Error!" << endl
			<< "Which file would you like to sort?" << endl
			<< "Select 1 for fileFront.txt" << endl
			<< "Select 2 for fileMiddle.txt" << endl
			<< "Select 3 for fileEnd.txt" << endl
			<< "Select 4 for fileNone.txt" << endl
			<< "Select 0 to Quit!" << endl;
		cin >> file;
	}

	// Exit if Quit selected.
	if (file == 0) { exit(EXIT_SUCCESS); }

	// Open chosen file name.
	switch (file) {
	case 1:
		inFile.open("fileFront.txt");
		break;
	case 2:
		inFile.open("fileMiddle.txt");
		break;
	case 3:
		inFile.open("fileEnd.txt");
		break;
	case 4:
		inFile.open("fileNone.txt");
		break;
	}

	// Handle file not found error.
	if (inFile.fail()) {
		cout << endl << "File not found!" << endl;
	}else{
		// Determine how many ints are in the text file and update count var.
		while (inFile.good()) {
			inFile >> anInt;
			count++;
		}
		inFile.clear();				// Clear EOF flag
		inFile.seekg(0L, ios::beg);		// Rewind txt file to beginning.

		// Our holding array for read in int values from the text file.
		int *anArray = new int[count];

		// Read in the text file int values to our anArray.
		while (inFile.good()) {
			for (i = 0; i < count; i++) {
				inFile >> anArray[i];
			}
		}
		cout << "Which algorithm would you like to use for the sort?" << endl
			<< "Enter 1 for BubbleSort." << endl
			<< "Enter 2 for SelectionSort." << endl
			<< "Enter 0 to Quit!" << endl;
		cin >> sorter;
		while (sorter < 0 || sorter > 2) {
			cout << endl << "Error!" << endl
				<< "Enter 1 for BubbleSort." << endl
				<< "Enter 2 for SelectionSort." << endl
				<< "Enter 0 to Quit!" << endl;
			cin >> sorter;
		}
		// Exit if Quit chossen.
		if (sorter == 0) { exit(EXIT_SUCCESS); }
		if (sorter == 1) {
			my.bubbleSort(anArray, count);
		}
		else if (sorter == 2) {
			my.selectSort(anArray, count);
		}
		cout << endl << "Here is the contents of the file sorted in ascending order!" << endl;
		my.showArray(anArray, count);

		// User Selects file to write to.
		cout << "Please enter the filename to be written to." << endl;
		cin >> fileName;
		outFile.open(fileName.c_str(), ios::out);

		for (i = 0; i < count; i++) {
			outFile << anArray[i] << "\n";
		}

		delete[] anArray;
		*anArray = 0;

		outFile.close();

		//Reset count.
		count = 0;

		cout << endl << "Would you like to read in and display the contents of: " << fileName << endl
			<< "Contents will be read in and displayed as is (not re-sorted)" << endl
			<< "Enter 1 for yes, 0 to Quit" << endl;
		cin >> check;
		if (check < 0 || check >1) {
			cout << endl << "Error!" << endl
				<< "Would you like to read in and display the contents of: " << fileName << endl
				<< "Contents will read in and displayed as is (not re-sorted)" << endl
				<< "Enter 1 for yes, 0 to Quit" << endl;
			cin >> check;
		}
		if (check == 0) {
			exit(EXIT_SUCCESS);
		}else{
			inFile2.clear();
			inFile2.open(fileName.c_str(), ios::in);
		}

		// Handle file not found error.
		if (!fileName.c_str()) {
			cout << endl << "File not found!" << endl;
		}else{
			// Determine how many ints are in the text file and update count var.
			// Using while(inFile.good()) reads an extra line!
			while (inFile2 >> anInt) {
				count++;
			}
			inFile2.clear();			// Clear EOF flag
			inFile2.seekg(0L, ios::beg);		// Rewind txt file to beginning.

			// Our holding array for read in int values from the text file.
			int *someArray = new int[count];

			// Read in the text file int values to our someArray.
			while (inFile2.good()) {
				for (i = 0; i < count; i++) {
					inFile2 >> someArray[i];
				}
			}

			// Show user's file contents.
			cout << endl << "Here are the un-altered contents of your file: " << fileName << endl;
			my.showArray(someArray, count);

			cout << endl << "Would you like to perform a binary search on: " << fileName << endl
				<< "Enter 1, for yes, 0 to Quit!" << endl;
			cin >> check;
			if (check < 0 || check >1) {
				cout << endl << "Error!" << endl
					<< "Would you like to perform a binary search on: " << fileName << endl
					<< "Enter 1 for yes, 0 to Quit" << endl;
				cin >> check;
			}
			if (check == 0) { exit(EXIT_SUCCESS); }
			else{
				cout << "What int do you seek?" << endl;
				cin >> seek;
				result = my.binarySearch(someArray, count, seek);
				if (result != -1)
					cout << endl << "I've found the int " << seek << " at array subscript location: " << result << endl;
				else
					cout << endl << "I could not find " << seek << " in: " << fileName << endl;

				cout << endl << "Here are the values that I read in from " << fileName << " so you can check!" << endl;
				my.showArray(someArray, count);
			}
			delete[] someArray;
			*someArray = 0;
		}
		inFile2.close();
	}
	cout << endl;
}
