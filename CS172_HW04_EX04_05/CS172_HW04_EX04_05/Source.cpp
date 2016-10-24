//////////////////////
// Ian Fisher
// CS 172 HW04
// 10/23/16
/////////////////////

#include <iostream>
#include "Course.h"
using namespace std;

// in additional to below, need to implement the destructor and copy constructor to perform a deep copy in the class

Course::Course(const string& courseName, int capacity)
{
	numberOfStudents = 0;
	this->courseName = courseName;
	this->capacity = capacity;
	students = new string[capacity];
}

Course::~Course()
{
	delete[] students;
}

string Course::getCourseName() const
{
	return courseName;
}

void Course::addStudent(const string& name)
{
	students[numberOfStudents] = name;
	numberOfStudents++;

	// increase the array size if the number of students in the array exceeds array's capacity...? hmmm
	// Function that doubles the size of an array
	int* doubleCapacity(const int* list, int size)
	{
		int* Doublearray = new int[(2 * size)]; // creates a pointer that doubles the size of each memory location
		for (int i = 0; i < size; i++) // for loop that accesses the array and creates a copy of Doublearray in list
		{
			Doublearray[i] = list[i]; // copy of Doublearray in list
		}
		delete list; // deletes list since it is old memory space
		return Doublearray; // returns the new array of twice the size..
	}
}

void Course::dropStudent(const string& name)
{
	// left as exercise
}

string* Course::getStudents() const
{
	return students;
}

int Course::getNumberOfStudents() const
{
	return numberOfStudents;
}

void clear()
{
	// removes all students from the course
}

int main ()
{
	// test program
	// creates a course, adds three students, removes one, displays the students in the course
}