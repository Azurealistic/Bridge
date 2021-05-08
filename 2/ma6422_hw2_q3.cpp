#include <iostream>

using namespace std;

int main() {
	// Define variables.
	int days_john, hours_john, minutes_john;
	int days_bill, hours_bill, minutes_bill;

	// Get input.
	cout << "Please enter the number of days John has worked: ";
	cin >> days_john;
	cout << "Please enter the number of hours John has worked: ";
	cin >> hours_john;
	cout << "Please enter the number of minutes John has worked: ";
	cin >> minutes_john;

	cout << endl << "Please enter the number of days Bill has worked: ";
	cin >> days_bill;
	cout << "Please enter the number of hours Bill has worked: ";
	cin >> hours_bill;
	cout << "Please enter the number of minutes Bill has worked: ";
	cin >> minutes_bill;

	// Process results;
	int total_minutes = minutes_bill + minutes_john; // Total amount of minutes both have.

	int total_hours = hours_bill + hours_john + (total_minutes / 60); // Total hours is their combined hours plus the minutes into hours.

	total_minutes %= 60; // Remaining minutes left.

	int total_days = days_bill + days_john + (total_hours / 24); // Same as above.

	total_hours %= 24;

	// Display results.
	cout << endl << "The total time both of them worked together is: " << total_days << " days, " << total_hours << " hours and " << total_minutes << " minutes." << endl;

	// End of program.
	return 0;
}