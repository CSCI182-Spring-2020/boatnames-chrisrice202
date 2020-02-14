// BoatArrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <iostream>
#include <iomanip>
#include <fstream>

#define MAX_BOAT_COUNT 30

using namespace std;

struct Boat {
	int nYearBuilt;
	string Name;
};

void printFleet(Boat fleet[]) {

	for (int i = 0; i < MAX_BOAT_COUNT; i++) {

		cout << "Boat " << i + 1 << ": " << fleet[i].Name << " " << fleet[i].nYearBuilt << endl;

	}

}

int main()
{


	// Start by reading in the files
	ifstream inFile;

	inFile.open("BoatNames.txt");
	if (!inFile) {
		cout << "Unable to open file";
		exit(1); // terminate with error
	}


	Boat Fleet[MAX_BOAT_COUNT];

	// Put all the boat names into an array, then print them to the screen
	char tempName[80];
	int nYear;
	int importCount = 0;

	// Read the input file for each player
	while (!inFile.eof() && importCount < MAX_BOAT_COUNT) {
		// Read in line
		inFile >> tempName >> nYear;


		// Write to Fleet's Structure here
		Fleet[importCount].Name = tempName;
		Fleet[importCount].nYearBuilt = nYear;

		importCount++;
	}
	// Close the input file
	inFile.close();


	// Now, print out each boat name by calling a
	// function to print each array item

	printFleet(Fleet);


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
