#include <iostream>

using namespace std;

int main() {
	// Define variables.
	int dollars, cents;

	// Get input.
	cout << "Please enter your amount in the format of dollars and cents separated by a space: " << endl;
	cin >> dollars >> cents;

	// Process input.
	int total = (dollars * 100) + cents; // Convert everything to cents.
	int quarters = (total / 25); // Count number of each coin, largest denomination to smallest.
	total %= 25; // Make sure to update remaining total. We use modulus because we want the remainder.
	int dimes = (total / 10);
	total %= 10;
	int nickels = (total / 5);
	total %= 5;
	int pennies = total;

	// Display results.
	cout << dollars << " dollars and " << cents << " cents are: " << endl;
	cout << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels and " << pennies << " pennies." << endl;

	// End of program.
	return 0;
}