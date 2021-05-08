#include <iostream>

using namespace std;

int main() {
	// Define variables.
	int first, second;

	// Get input.
	cout << "Please enter two positive integers, separated by a space:" << endl;
	cin >> first >> second;

	// Display results.
	cout << first << " + " << second << " = " << (first + second) << endl;
	cout << first << " - " << second << " = " << (first - second) << endl;
	cout << first << " * " << second << " = " << (first * second) << endl;
	cout << first << " / " << second << " = " << ((float) first / (float) second) << endl;
	cout << first << " div " << second << " = " << (first / second) << endl;
	cout << first << " mod " << second << " = " << (first % second) << endl;

	// End of program.
	return 0;
}