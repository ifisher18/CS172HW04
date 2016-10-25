//////////////////////
// Ian Fisher
// CS 172 HW04
// 10/23/16
/////////////////////

#include <iostream>
#include "Course.h"
using namespace std;

// in additional to below, need to implement the destructor and copy constructor to perform a deep copy in the class

// Creates an constructor called Course which has parameters courseName and capacity
Course::Course(const string& courseName, int capacity)
{
    numberOfStudents = 0;
    this->courseName = courseName;
    this->capacity = capacity;
    students = new string[capacity]{""};
}

// deep copy of the class (special syntax)
Course::Course(const Course &copy) :
    numberOfStudents(copy.numberOfStudents), // creates a deep copy of numberOfStudents
    courseName(copy.courseName), // creates a deep copy of courseName
    capacity(copy.capacity) { // creates a deep copy of capacity-- in this case since capcity is a pointer there is special syntax
    students = new string[copy.capacity]; // creates a deep copy of students, also creates a new string that copies capacity
    // for loop that creates a deep copy of the array students, needs loop to go through each element of the array
    for (int i = 0; i < copy.capacity; i++) {
        if (copy.students[i] != "") {
            students[i] = copy.students[i];
        }
    }
}

// destructor
Course::~Course()
{
    delete[] students; // deletes all memory in the students array
}

// function called getCourseName that returns the course name
string Course::getCourseName() const
{
    return courseName;
}

// function that adds a student
// if the number of students exceeds the array size, the array is doubled
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

// Function that drops a student (a.k.a. clears the memory of the student that is dropped)
void Course::dropStudent(const string& name)
{
    for (int i = 0; i < capacity; i++){
        if (students[i] == name) {
            students[i].clear();
        }
    }

}

// function that returns the students (getStudents)
string* Course::getStudents() const
{
    return students; // returns students
}

// function called getNumberofStudents that returns the number of students
int Course::getNumberOfStudents() const
{
    return numberOfStudents; // returns numberOfStudents
}

// function that removes all students from the course
void Course::clear()
{
    // removes all students from the course a.k.a. clears the memory location for each student
    for (int i = 0; i < students->size(); i++) {
        students[i].clear();
    }
}

// function created for fun that loops through the array and checks if the a memory location is empty or not
// created to help with debugging
int getN(string* array) {
    int i = 0;
    for (int j = 0; j < array->size(); j++) {
        if (array[j] != "") {
            i++;
        }
    }
    return i;
}

// function that prints the given input...in this case it is used to output the students
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
