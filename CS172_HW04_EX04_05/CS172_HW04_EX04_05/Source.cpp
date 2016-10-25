//////////////////////
// Ian Fisher
// CS 172 HW04
// 10/23/16
/////////////////////

#include <iostream>
#include "Header.h"
using namespace std;

// in additional to below, need to implement the destructor and copy constructor to perform a deep copy in the class

// Creates an object called Course which has parameters courseName and capacity
Course::Course(const string& courseName, int capacity)
{
    numberOfStudents = 0;
    this->courseName = courseName;
    this->capacity = capacity;
    students = new string[capacity]{""};
}

// deep copy of the class
Course::Course(const Course &copy) :
    numberOfStudents(copy.numberOfStudents),
    courseName(copy.courseName),
    capacity(copy.capacity) {
    students = new string[copy.capacity];
    for (int i = 0; i < copy.capacity; i++) {
        if (copy.students[i] != "") {
            students[i] = copy.students[i];
        }
    }
}

//
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
    // increase the array size if the number of students in the array exceeds array's capacity...? hmmm
    // Function that doubles the size of an array, in this case students
    if (numberOfStudents > students->size())
    {
        string* Doublearray = new string[(2 * numberOfStudents)]; // creates a pointer that doubles the size of each memory location
        for (int i = 0; i < numberOfStudents; i++) // for loop that accesses the array and creates a copy of Doublearray in list
        {
            Doublearray[i] = students[i]; // copy of Doublearray in students
        }
        students = Doublearray; // asigns students to Doublearray (twice the size)
        
        delete[] Doublearray; // deletes students since it is old memory space
        // returns the new array of twice the size..
    }
    students[numberOfStudents] = name;
    numberOfStudents++;
}

void Course::dropStudent(const string& name)
{
    for (int i = 0; i < capacity; i++){
        if (students[i] == name) {
            students[i].clear();
        }
    }

}

string* Course::getStudents() const
{
    return students;
}

int Course::getNumberOfStudents() const
{
    return numberOfStudents;
}

// function that removes all students from the course
void Course::clear()
{
    // removes all students from the course
    for (int i = 0; i < students->size(); i++) {
        students[i].clear();
    }
}

int getN(string* array) {
    int i = 0;
    for (int j = 0; j < array->size(); j++) {
        if (array[j] != "") {
            i++;
        }
    }
    return i;
}

void print(string* array) {
    for (int j = 0; j < sizeof(array); j++) {
        cout << array[j] << endl;
    }
}

int main ()
{
    cout << "** This test program creates a course, adds three students, removes one, and displays the students in the course **" << endl;
    cout << endl;
    
    // creates a new course called "c"
    Course* c = new Course("Math-455", 6);
    
    // adds three students (Elvis, Ian, and Santa) to the course
    c->addStudent("Elvis");
    c->addStudent("Ian");
    c->addStudent("Santa");
    
    // Removes one student (Elvis)
    c->dropStudent("Elvis");
    
    // Displays the students in the course
    print(c->getStudents());
    
    delete c;
}
