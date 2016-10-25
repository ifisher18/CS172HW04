///////////////////////////////
// Ian Fisher
// CS 172 HW04 EX03
// 10/12/16
///////////////////////////////

#include <iostream>
#include <limits>
using namespace std;

// find the smallest element
int smallestNum(int*nums);

int main ()
{
    // prompts the user to enter values into an array
    cout << "** Welcome! This program finds the smallest element in an array of integers. **" << endl;
    cout << endl;
    cout << "Enter a series of integers: ";
    int numbers[8]; // creates an array of size 8
    
    // loops that enters each number into the array
    for (int i = 0; i < 8; i++)
    {
        cin >> numbers[i]; // cin's each entry into the array
    }
    
    cout << "The smallest element in this list of numbers is: " << smallestNum(numbers) << "." << endl; // cout statement that outputs the smallest number of the inputed values
    
}

// function that returns the smallest number after comparing to the entire array
// funtion returns an integer
int smallestNum (int*nums) // function with the parameter of the pointer to each number
{
    int currentsmall = numeric_limits<int>::max(); // sets the intial value equal to greatest value in C++
    for (int i = 0; i < 8; i++) // for loop that checks each value in the array
    {
        if (nums[i] < currentsmall) { // if statement that checks if the current value in array is less than the current smallest number
            currentsmall = nums[i]; // if it is less, then the smallest number is set to that value
        }
        
    }
    return currentsmall; // returns the smallest value after the loop is complete.
}
