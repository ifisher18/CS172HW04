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
    delete list; // deletes list since it is old memory space
    return Doublearray; // returns the new array of twice the size..
}

int main ()
{
    // creates a new point/array
    int*list = new int[3];
    list [0] = 1; // asigns 1 at location 0 in the array
    list [1] = 2; // asigns 2 at location 1 in the array
    list [2] = 3; // asigns 3 at location 2 in the array
    // {1, 2, 3}
    
    // for loop that checks the orig. values in the array (before the doubleCapacity)
    cout << "Before the implementation of doubleCapacity, the array values are:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << list[i] << endl; // couts the values in list array
    }
    
    cout << endl;
    cout << endl;
    list = doubleCapacity(list, 3); // applies the doubleCapacity to double the size of the array list
    
    // for loop that checks the array values (after the doubleCapacity function is implemented)
    cout << "After the implementation of doubleCapacity, the array values (and additional spaces) are:" << endl;
    for (int i = 0; i < 6; i++) {
        cout << list[i] << endl; // couts the values in list array
    }
    
    delete list; // deletes list since it is old memory space
    return 0;
}
