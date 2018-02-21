#pragma once

///Temp
#include <vector>
#include <iostream>
#include <iomanip>
#include <cassert>

#include <algorithm>
#include <functional>
#include <array>

#define RAND_VAL 1234

class Node
{
public:
	Node(int input) { this->nodeData = input; this->next = nullptr; this->previous = nullptr;};
	~Node() {};

	Node* next;
	Node* previous;
	int nodeData;
};

class Sort
{
public:
	Sort();
	Sort(unsigned int size);
	~Sort();

	void SetRandomSeed(unsigned int seed = RAND_VAL);

	//Array Stuff
	void InitUnsortedArray();//Init to sort
	void InitSortedArray();
	int at(unsigned int x);

	//Linked List Stuff
	void InitUnsortedList();//Init to sort

	//Vector Stuff
	void InitUnsortedVector();//Init to sort

	// debugging operator
	friend std::ostream& operator<< (std::ostream& out, /*const*/ Sort& s);

	//Sorts
	void arrayInsertionSort();
	void linkedListInsertionSort();
	void selectionSort();
	void mergeSort(int data[], unsigned int size);
	void mergeSort();
	void quickSort(int data[], unsigned int lowIndex, unsigned int highIndex);
	void quickSort();
	void vectorSort();

	//General
	unsigned int getSize();

private:
	//Private helper functions
	void swap(int& a, int&b);	//Selection Sort Helper
	void merge(int data[], unsigned int n1, unsigned int n2);	//Merge sort helper
	unsigned int partition(int data[], unsigned int lowIndex, unsigned int highIndex);	//Quick sort Helper

	//Private data members
	int* intArray;
	unsigned int data_size;
	Node* head;
	std::vector<int> intVector;
	int seedValue = RAND_VAL;
};