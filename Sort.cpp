#include "Sort.h"

#define UNSORTED_VARIANCE 15
#define SORTED_VARIANCE 10

Sort::Sort()
{
	//Nothing for now
	//Initializing this way doesn't work yet
}

Sort::Sort(unsigned int size)
{
	this->data_size = size;
	this->intArray = new int[size];
}

Sort::~Sort()
{
	delete this->intArray;
	Node* temp;
	while (this->head != nullptr)
	{
		temp = this->head;
		this->head = this->head->next;
		delete temp;
	}
}

void Sort::SetRandomSeed(unsigned int seed)
{
	srand(seed);
}

void Sort::InitUnsortedArray()
{
	int negativeMultiplier;
	for (unsigned int i = 0; i < this->data_size; i++)
	{
		if (rand() % 2 == 1)
		{
			negativeMultiplier = -1;
		}
		else
		{
			negativeMultiplier = 1;
		}
		this->intArray[i] = ((rand() % UNSORTED_VARIANCE) * negativeMultiplier);
	}
}

void Sort::InitSortedArray()
{
	intArray[0] = rand() % SORTED_VARIANCE;
	for (unsigned int i = 1; i < this->data_size; i++)
	{
		this->intArray[i] = this->intArray[i - 1] + (rand() % SORTED_VARIANCE);
	}
}

int Sort::at(unsigned int x)
{
	if (x < this->data_size)
	{
		return this->intArray[x];
	}
	else
	{
		std::cout << std::endl<< "out of bounds try again" << std::endl;
		return 0;
	}
}

void Sort::InitUnsortedList()
{
	Node* temp = nullptr;

	int val = rand() % UNSORTED_VARIANCE;
	this->head = new Node(val);

	temp = this->head;
	int negativeMultiplier;
	for (unsigned int i = 0; i < this->data_size; i++)
	{
		val = rand() % UNSORTED_VARIANCE;
		if (rand() % 2 == 1)
		{
			val *= -1;
		}

		temp->next = new Node(val);
		temp->next->previous = temp;
		temp = temp->next;
	}
}

void Sort::InitUnsortedVector()
{
	this->intVector.clear();
	unsigned int size = this->data_size;
	for (unsigned int i = 0; i < size; ++i)
	{
		int negativeMultiplier;
		if (rand() % 2 == 1)
		{
			negativeMultiplier = -1;
		}
		else
		{
			negativeMultiplier = 1;
		}
		this->intVector.push_back((rand() % UNSORTED_VARIANCE) * negativeMultiplier);
	}
}

void Sort::arrayInsertionSort()
{
	int temp;
	for (unsigned int i = 1; i < this->data_size; ++i)
	{
		unsigned int j = i-1;
		temp = this->intArray[i];

		while (temp < intArray[j])
		{
			intArray[j + 1] = intArray[j];
			if(j == 0)
			{
				break;
			}
			--j;
		}
		intArray[j + 1] = temp;
	}
}

void Sort::linkedListInsertionSort()
{
	if (this->head->next == nullptr)
	{
		return;
	}
	Node* current =  this->head;
	Node* back;
	Node* front = current->next;
	while (front != nullptr)
	{
		current = front;
		front = current->next;
		
		back = current->previous;
		if (current->nodeData < back->nodeData)
		{
			current->previous->next = current->next;
			if (current->next != nullptr)
			{
				current->next->previous = current->previous;
			}
			while (current->nodeData < back->nodeData && back->previous != nullptr)
			{
				back = back->previous;
			}
			if (back->previous == nullptr)	//Reached begining
			{
				current->previous = back->previous;
				current->next = back;
				this->head = current;
			}
			else //meaning current data !< back data
			{
				current->previous = back;
				current->next = back->next;
				back->next->previous = current;
				back->next = current;
			}
		}
		else	//In right place	
		{
			//Don't move, nothing for now
		}
	}
}

void Sort::swap(int& a, int& b)	//FIXED
{
	int temp = a;
	a = b;
	b = temp;
}


void Sort::selectionSort()
{
	int largest;
	unsigned int i, j, index_of_largest;

	if (this->data_size == 0)
	{
		return;
	}

	for (i = this->data_size - 1; i > 0; --i)
	{
		largest = this->intArray[0];
		index_of_largest = 0;
		for (j = 1; j <= i; ++j)
		{
			if (this->intArray[j] > largest)
			{
				largest = this->intArray[j];
				index_of_largest = j;
			}
		}
		if (i != index_of_largest)
		{
			swap(this->intArray[i], this->intArray[index_of_largest]);
		}
	}

	/*int temp, min_index;	//Sorting it the wrong way I guess
	unsigned int i, j;
	for (i = 0; i < this->data_size; ++i)
	{
		min_index = i;
		for (j = i + 1; j < this->data_size; ++j)
		{
			if (this->at(j) < this->at(min_index))
			{
				min_index = j;
			}
		}
		if (min_index != i)
		{
			temp = this->intArray[i];
			this->intArray[i] = this->intArray[min_index];
			this->intArray[min_index] = temp;
		}
	}*/
}

void Sort::merge(int data[], unsigned int n1, unsigned int n2)
{
	int* temp;
	unsigned int copied = 0;
	unsigned int copied1 = 0;
	unsigned int copied2 = 0;
	unsigned int i;

	//Allocate memory for the temporary dynamic array
	temp = new int[n1 + n2];

	//Merge elements, copying from two halves of data to the temporary array
	while ((copied < n1) && (copied2 < n2))
	{
		if (data[copied] < (data + n1)[copied2])
		{
			temp[copied++] = data[copied1++];
		}
		else
		{
			temp[copied++] = (data + n1)[copied2++];
		}
	}

	//Copy any remaining entries in the left and right subarrays
	while (copied1 < n1)
	{
		temp[copied++] = data[copied1++];
	}
	while (copied2 < n2)
	{
		temp[copied++] = (data + n1)[copied2++];
	}

	//Copy from temp back to the data array, and release temp's memory
	for (i = 0; i < n1 + n2; ++i)
	{
		data[i] = temp[i];
	}
	delete[] temp;
}


void Sort::mergeSort(int data[], unsigned int size)
{
	unsigned int n1, n2;
	if (size > 1)
	{
		//Compute sizes of subarrays
		n1 = size / 2;
		n2 = size - n1;

		mergeSort(data, n1);		//Sort from data[0] to data[n1-1]
		mergeSort(data + n1, n2);	//Sort from data[n] to end

		//Merge the two sorted halves
		merge(data, n1, n2);
	}
}

void Sort::mergeSort()
{
	this->mergeSort(this->intArray, this->data_size);
}


unsigned int Sort::partition(int data[], unsigned int lowIndex, unsigned int highIndex)
{	//Helped out with Psudo code from Dana Doggett
	bool done = false;
	int pivot = data[lowIndex + (highIndex - lowIndex) / 2];
	while (!done)
	{
		while (data[lowIndex] < pivot)
		{
			++lowIndex;
		}
		while (pivot < data[highIndex])
		{
			--highIndex;
		}
		//Check for all done
		if (lowIndex >= highIndex)
		{
			done = true;
		}
		else
		{
			//Swap low index value with high index value
			int temp;
			temp = data[lowIndex];
			data[lowIndex] = data[highIndex];
			data[highIndex] = temp;
			++lowIndex;
			--highIndex;
		}
	}
	return highIndex;
}

void Sort::quickSort(int data[], unsigned int lowIndex, unsigned int highIndex)
{
	unsigned int size = highIndex - lowIndex;
	if (size == 0 || size == 1)
	{
		return;
	}
	unsigned int midIndex = partition(data, lowIndex, highIndex);
	quickSort(data, lowIndex, midIndex);
	quickSort(data, midIndex + 1, highIndex);
}

void Sort::quickSort()
{
	this->quickSort(this->intArray, 0, this->data_size);
}

void Sort::vectorSort()
{
	struct myclass 
	{
		bool operator() (int i, int j) { return (i<j); }
	} myobject;
	std::sort(this->intVector.begin(), this->intVector.end(), myobject);
}

unsigned int Sort::getSize()
{
	return this->data_size;
}


std::ostream & operator<<(std::ostream & out, /*const*/ Sort& s)
{
	out << std::endl;
	for (unsigned int i = 0; i < s.getSize(); i++)
	{
		out << s.at(i) << ", ";
	}
	out << std::endl;
	return out;
}
