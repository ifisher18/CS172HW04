///////////////////////////////
// Ian Fisher
// CS 172 HW04 EX04_01
// 10/12/16
///////////////////////////////

#include <iostream>
using namespace std;

double numAver(int*nums, int sizenum);
int numAbove(int*nums, int sizenum);
int main ()
{
	int num_size; // creates a variable called num_size that 
	cout << "Welcome! This is a math program that takes the average of a given set of numbers." << endl;
	cout << endl;
	cout << "Enter the amount of numbers that you'd like to enter: ";
	cin >> num_size;
	cout << endl;
	cout << "Now enter each number that you'd like to find the average of: ";
	int numbers[100];

	// loop that enters each number into array
	for (int i = 0; i < num_size; i++) { 
		cin >> numbers[i];
	}

	// outputs the average of the numbers in the given array
	cout << "The average of the entered numbers is: " << numAver(numbers, num_size) << "." << endl;

	// outputs the amount of numbers in the array that are above the average
	cout << "The amount of numbers that is above the calculated average is: " << numAbove(numbers, num_size) << "." << endl;

	return 0;

}

// function that calculates the average of the user-entered numbers in array "numbers"
double numAver(int*nums, int sizenum)
{
	int sum = 0;
	for (int i = 0; i < sizenum; i++) { // loop that checks through the array
		sum += *(nums + i); // x = x + *(nums + i) (adds each number in array to each other)
	}
	 
	return ((double) sum / sizenum); // casts x to a double value so decimals will be included-- this is the basic average calculation: sum/number of nums
}

// function that find out how many numbers are above the average in the array "numbers"
int numAbove (int*nums, int sizenum)
{
	int checknum = 0;
	double x = numAver(nums, sizenum);
	for (int i = 0; i < sizenum; i++) { // loop that checks through the array
		if ((double)*(nums + i) > x) { // is the same as (double)nums[i]
			checknum++;
		}
	}
	return checknum;
}