#include <iostream>
#include <string>
#include <iomanip> // setprecision

using namespace std;

int main(int argc, char const *argv[]) {
	// Easier to have rates defined as a multipler we can reference.
	const double DAY_RATE = 0.40;
	const double NIGHT_RATE = 0.25;
	const double WEEKEND_RATE = 0.15;

	// Define variables to hold information, time, day, minutes.
	int hour, minutes, duration; // Duration is length of call (number of minutes.)
	string day;
	char placeholder; // Used for input of time, unused after.

	// Get input.
	cout << "Please enter call start time in 24 hour format (HH:MM): ";
	cin >> hour >> placeholder >> minutes;
	cout << "Please enter day of the week (Mo Tu We Th Fr Sa Su): ";
	cin >> day;
	cout << "Please enter duration of call in minutes: ";
	cin >> duration;

	// Make sure we always display 2 decimal places for cents.
	cout << fixed << setprecision(2);

	// Process and output.
	if(day == "Sa" || day == "Su") {
		cout << "This call will cost: $" << (WEEKEND_RATE * duration) << endl;
	} else { // Otherwise it's a weekday, since we can trust input here.
		/*
		We need to check to see if the time is between 8:00 and 18:00, or outside of this range. 
		So will need to nest a couple of if-else statements to account for all the possibilities here.
		*/
		if(hour >= 8 && hour <= 18) {
			// If the hour is 6:00 PM we need to check to make sure we don't let anyone after 6:00 PM, i.e. 6:01PM at day rate.
			if(hour == 18 && minutes != 0) {
				cout << "This call will cost: $" << (NIGHT_RATE * duration) << endl; // This is charged at night rate.
			} else { // Everything else should be valid and fine.
				cout << "This call will cost: $" << (DAY_RATE * duration) << endl; // Charged at day rate.
			}
		} else {
			cout << "This call will cost: $" << (NIGHT_RATE * duration) << endl; // Charged at night rate.
		}
	}

	// End.
	return 0;
}
