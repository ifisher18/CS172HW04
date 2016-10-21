//////////////////////
// Ian Fisher
// CS 172 HW04 EX02
// 10/12/16
/////////////////////

#include <iostream>
using namespace std;

// Function that doubles the size of an array
int* doubleCapacity(const int* list, int size)
{
	int* Doublearray = new int[(2 * size)]; // creates a pointer that doubles the size of each memory location
	for (int i = 0; i < size; i++) // for loop that accesses the array and creates a copy of Doublearray in list
	{
		Doublearray[i] = list[i]; // copy of Doublearray in list
	}
	delete list;
	return Doublearray; // returns the new array of twice the size
}

int main ()
{
	int*list = new int[3];
	// {1, 2, 3}

	list = doubleCapacity(list, 3);
	delete list;
	return 0;
}