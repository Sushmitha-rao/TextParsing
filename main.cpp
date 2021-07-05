/*
 * This is a program to read a text file which contains data about students,
 * and parse the text to obtain student's names and print the same on console.
 */

// Standard (system) header files
#include <iostream>
#include <stdlib.h>
#include <fstream>

// Add more standard header files as required
#include <string>
#include <vector>

using namespace std;

// Main program
int main(void)
{
	// TODO: Add your program code here
	ifstream file; //input file stream object
	string text;
	string data;
	string delimiter = ": ";
	vector<string> names; //A vector to store names of all the students

	//Open the text file
	file.open("data.txt");


	//Iterate over the text file to read every line
	for (int i = 0; file.eof() != true; i = i + 1)
	{
		//Read one line from the file to the string text
		getline(file, text);

		//Parse the data in every 5th line to get name of the student
		if (i % 5 == 0)
		{
			data = text.substr(text.find(": ") + delimiter.length());
			names.push_back(data);
		}
	}

	//Iterate over the names vector to print names of every student
	for (unsigned int j = 0; j < names.size(); j++)
	{
		cout << "Name of the student " << j + 1 << " is: " << names[j] << endl;
	}

	file.close();

	return 0;
}
