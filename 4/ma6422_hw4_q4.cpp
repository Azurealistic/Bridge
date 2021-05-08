#include <iostream>
#include <cmath>
#include <iomanip>

// value = pow(value, 1/rootvalue)

using namespace std;

int main(int argc, char const *argv[]) {
	// Input variable.
	int input = 0;

	// Section A.
	cout << "section a" << endl;
	int length;
	cout << "Please enter the length of the sequence: ";
	cin >> length;
	cout << "Please enter your sequence: " << endl;

	double value = 1.0; // We can't use 0 because if we multiply by zero we get nothing, so we need to start with one.

	for(int i = 0; i < length; i++) {
		cin >> input;
		value *= input;
	}

	cout << "The geometric mean is: " << setprecision(5) << pow(value, (1 / (double) length)) << endl;

	// Section B.
	cout << "section b" << endl;
	cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1: " << endl;
	 
	// Reset value and input to 0.
	value = 1.0;
	input = 0;
	int counter = 0;

	// Get input;
	while(input != -1) {
		cin >> input;
		value *= input;
		counter++;
	}

	cout << "The geometric mean is: " << setprecision(5) << pow(-value, (1 / (double) (counter - 1))) << endl;

	// End.
	return 0;
}