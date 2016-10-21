///////////////////////////////
// Ian Fisher
// CS 172 HW04 EX03
// 10/12/16
///////////////////////////////

#include <iostream>
using namespace std;

// find the smallest element
int smallestNum(int*nums);

int main ()
{
	cout << "**Welcome! This program finds the smallest element in an array of integers.**" << endl;
	cout << endl;
	cout << "Enter a series of integers: ";
	int numbers[100];

	// loops that enters each number into the array
	for (int i = 0; i < 100; i++)
	{
		cin >> numbers[i]; // cin's each entry into the array
	}

	cout << "The smallest element in this list of numbers is: " << smallestNum(numbers) << "." << endl; // cout statement that outputs the smallest number of the inputed values

}

// function that returns the smallest number after comparing to the entire array
int smallestNum (int*nums)
{
	for (int i = 0; i < 100; i++)
	{
		if ()
	}
}