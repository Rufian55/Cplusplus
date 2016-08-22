#include"SearchSort.hpp"
#include<iostream>
using std::cout;
using std::cin;
using std::endl;


/**********************************************************************************
*                           linerarSearch()
* This function performs a linear search on an integer array.  The list array,
* which has size elements, is searched for the number stored in value. If the
* number is found, its array subscript is returned. Otherwise, -1 is returned.
* c++ Early Objects, Gaddis, 8th Edition, Program 9-1 
**********************************************************************************/
int SearchSort::linearSearch(int list[], int size, int value){
	int index = 0;					// Used as a subscript to search array 
	int position = -1;				// Used to record position of search value 
	bool found = false;				// Flag to indicate if the value was found 

	while (index < size && !found) {
		if (list[index] == value){	// If value is found
			found = true;			// Set the found flag 
			position = index;		// Record the value's subscript 
		}
		index++;					// Go to the next element 
	}
	return position;				// Return the position, or -1 
}


/******************************************************************************
*                         binarySearch()
* This function performs a binary search on an integer array with size 
* elements whose values are stored in ascending order. The array is searched
* for the number stored in the value parameter. If the number is found, its
* array subscript is returned. Otherwise, -1 is returned.
* c++ Early Objects, Gaddis, 8th Edition, Program 9-2
******************************************************************************/
int SearchSort::binarySearch(int array[], int size, int value){
	int first = 0;						// First array element
	int	last = size - 1;				// Last array element
	int	middle;							// Midpoint of search
	int	position = -1;					// Position of search value
	bool found = false;					// found flag

	while (!found && first <= last){
		middle = (first + last) / 2;	// Calculate midpoint
		if (array[middle] == value){	// If value is found at mid
			found = true;
			position = middle;
		}
		else if (array[middle] > value)	// If value is in lower half
			last = middle - 1;
		else
			first = middle + 1;			// If value is in upper half
	}
	return position;
}


/***************************************************************************
*                        bubbleSort()
* This function performs an ascending-order bubble sort on an array. The
* parameter size holds the number of elements in the array.
* c++ Early Objects, Gaddis, 8th Edition, Program 9-4
****************************************************************************/
void SearchSort::bubbleSort(int array[], int size){
	int  temp;
	bool swap;

	do{
		swap = false;
		for (int count = 0; count < (size - 1); count++) {
			if (array[count] > array[count + 1]) {
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);  // Loop again if a swap occurred on this pass.
}


/****************************************************************************
*                        selectSort()
* This function performs an ascending-order selection sort on an array. The
* parameter size holds the number of elements in the array.
*****************************************************************************/
void SearchSort::selectSort(int array[], int size){
	int startScan;
	int minIndex;
	int minValue;

	for (startScan = 0; startScan < (size - 1); startScan++) {
		minIndex = startScan;
		minValue = array[startScan];
		for (int index = startScan + 1; index < size; index++) {
			if (array[index] < minValue) {
				minValue = array[index];
				minIndex = index;
			}
		}
		array[minIndex] = array[startScan];
		array[startScan] = minValue;
	}
}


/**************************************************************************
*                        showArray()
* This function displays the contents of array. The parameter size holds
* the number of elements in the array.
**************************************************************************/
void SearchSort::showArray(int array[], int size){
	for (int count = 0; count < size; count++)
		cout << array[count] << " ";
	cout << endl;
}


/***************************************************************************
*                        bubbleSort()
* This function performs an ascending-order bubble sort on an array of
* object pointers. The parameter size holds the number of elements in the
* array.  Modified from int sort to *Creature sort on getcScore() via C++
* Early Objects, Gaddis, 8th Edition, Program 9-4.
****************************************************************************
void Fight::bubbleSort(Creature* anArray[], int size) {
	Creature* temp;
	bool swap;

	do {
		swap = false;
		for (int count = 0; count < (size - 1); count++) {
			if (anArray[count]->getcScore() > anArray[count + 1]->getcScore()) {
				temp = anArray[count];
				anArray[count] = anArray[count + 1];
				anArray[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);  // Loop again if a swap occurred on this pass.
}


/****************************************************************************
*                        selectSort()
* This function performs an ascending-order selection sort on an array of
* object pointers. The parameter size holds the number of elements in the
* array.  Modified from int sort to *Creature sort on getcScore() via C++
* Early Objects, Gaddis, 8th Edition, Program 9-5.
*****************************************************************************
void Fight::selectSort(Creature* anArray[], int size) {
	int i;
	int minIdx;
	int minVal;
	Creature *temp;

	for (i = 0; i < (size - 1); i++) {
		minIdx = i;
		minVal = anArray[i]->getcScore();
		for (int index = i + 1; index < size; index++) {
			if (anArray[index]->getcScore() < minVal) {
				minVal = anArray[index]->getcScore();
				minIdx = index;
			}
		}
		temp = anArray[minIdx];
		anArray[minIdx] = anArray[i];
		anArray[i] = temp;
	}
}
*/