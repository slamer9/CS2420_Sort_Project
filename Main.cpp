/********************************************************************************************
**	Project: Sort
**  Programmer: Duncan Reeves
**  Course:		cs2420
**	Section:	002
**	Assignment: 5, Sort Project
**	Data:		February, 20th, 2018
**
**	I certify that I wrote all code in this project except that which was
**	provided by the instructor.
**
***********************************************************************************************/

///Finished (attempt 2.1)

#include <iostream>
#include "Sort.h"
#include "Timer.h"
#define RANDOM_SEED 12345

using namespace std;

int main()
{
	const int DATA_SIZE = 80000;	// you will have to adjust this to suit the speed of your machine.
	Sort *sort = new Sort(DATA_SIZE);
	Timer ti;

	sort->SetRandomSeed(RANDOM_SEED);

	sort->InitUnsortedArray();
	cout << "starting InsertionSort" << endl;
	ti.Start();
	sort->arrayInsertionSort();
	ti.End();
	cout << "Insertion sort duration: " << ti.DurationInMilliSeconds() << "ms" << endl;

	sort->InitUnsortedList();
	cout << "starting InsertionSortList()" << endl;
	ti.Start();
	sort->linkedListInsertionSort();
	ti.End();
	cout << "Insertion sort list duration: " << ti.DurationInMilliSeconds() << "ms" << endl;

	sort->InitUnsortedArray();
	cout << "starting SelectionSort" << endl;
	ti.Start();
	sort->selectionSort();
	ti.End();
	cout << "SelectionSort duration: " << ti.DurationInMilliSeconds() << "ms" << endl;

	sort->InitUnsortedArray();
	cout << "starting MergeSort" << endl;
	ti.Start();
	sort->mergeSort();
	ti.End();
	cout << "MergeSort duration: " << ti.DurationInMilliSeconds() << "ms" << endl;

	sort->InitUnsortedArray();
	cout << "starting QuickSort" << endl;
	ti.Start();
	sort->quickSort();		//Where heap thing happens	DR
	ti.End();
	cout << "QuickSort duration: " << ti.DurationInMilliSeconds() << "ms" << endl;

	sort->InitUnsortedVector();
	cout << "starting std::sort() of Vector<int>" << endl;
	ti.Start();
	sort->vectorSort();
	ti.End();
	cout << "std::sort() duration: " << ti.DurationInMilliSeconds() << "ms" << endl;

	delete sort;

	cout << endl <<"Press [Enter] key to exit";
	getchar();
}