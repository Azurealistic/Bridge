#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	// Defining constants to multiply against for conversions needed.
	const double KILOGRAMS = 0.453592; // 1 lb is this many kg.
	const double METERS = 0.0254; // 1 inch is this many meters.

	// Get input/define variables.
	double weight, height;
	cout << "Please enter weight (in pounds): ";
	cin >> weight;
	cout << "Please enter height (in inches): ";
	cin >> height;

	// Calculate results and output using an if/else statement for the various statuses.
	double bmi = (weight * KILOGRAMS) / ((height * METERS) * (height * METERS));

	if(bmi < 18.5) {
		cout << "The weight status is: Underweight" << endl;
	} else if(bmi >= 18.5 && bmi < 25) {
		cout << "The weight status is: Normal" << endl;
	} else if(bmi >= 25 && bmi < 30) {
		cout << "The weight status is: Overweight" << endl;
	} else {
		cout << "The weight status is: Obese" << endl;
	}

	// End.
	return 0;
}
