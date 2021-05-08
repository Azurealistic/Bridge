#include <iostream>

using namespace std;

int main() {
	// Define variables.
	int coins;
	int total = 0; // We only need to keep track of two variable, everything else can just overwrite the input one over and over again. Total is calculating value in cents.

	// Get input.
	cout << "Please enter number of coins: " << endl;
	cout << "# of quarters: ";
	cin >> coins; 
	total += (coins * 25); // Each quarter is worth 25 cents.

	cout << "# of dimes: ";
	cin >> coins; 
	total += (coins * 10); // Each dime is worth 10 cents.

	cout << "# of nickels: ";
	cin >> coins; 
	total += (coins * 5); // Each nickel is worth 5 cents.

	cout << "# of pennies: ";
	cin >> coins; 
	total += coins; // Each penny is worth 1 cent.

	// Calculate and display results.
	int dollars = (total / 100);
	int cents = total - (dollars * 100);

	cout << "The total is " << dollars << " dollars and " << cents << " cents.";

	// End of program.
	return 0;
}