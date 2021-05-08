#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	// Given by problem.
	const int FLOOR_ROUND = 1;
	const int CEILING_ROUND = 2;
	const int ROUND = 3;

	double n; // The reason I chose the variable 'n' for input this time is both because it a number, but also because it looks cleaner and is easier to type when doing the calculations for floor/ceiling above.
	int choice;

	// Get input.
	cout << "Please enter a real number: ";
	cin >> n;
	cout << "Choose your rounding method:\n1. Floor round\n2. Ceiling round\n3. Round to the nearest whole number" << endl;
	cin >> choice;

	// Calculate ceiling and floor ahead of time. The below makes use of the fact that we do not have the ability to take modulus of two doubles or a double and an integer in cpp.
	// So my solution was to implement my own version of the modulus that takes care of this. Normally I would make this into a function, but we haven't "learned" that yet.
	// So I simply just re-wrote the modulus each time, which is the ((n - (int)(n/1.0) * 1.0)) section, to get the modulus of n % 1, which is what I need.
	// Lastly the ceiling is simply same as: ceil = -floor(-n), so I simply negated all of the inputs for the ceiling calculations and that solved that problem.
	double floor, ceil;

	if((n - (int)(n / 1.0) * 1.0) >= 0) { 
		floor = n - (n - (int)(n / 1.0) * 1.0);
	} else {
		floor = n - (1 + (n - (int)(n / 1.0) * 1.0));
	}

	if((-n - (int)(-n / 1.0) * 1.0) >= 0) { 
		ceil = n - (-n - (int)(-n / 1.0) * 1.0);
	} else {
		ceil = n - (1 + (-n - (int)(-n / 1.0) * 1.0));
	}

	// Display.
	switch (choice) {
	case FLOOR_ROUND:
		if(n == 0) {
			cout << "Output: " << 0 << endl;
		} else {
			cout << "Output: " << floor << endl;
		}
		break;
	case CEILING_ROUND:
		if(n == 0) {
			cout << "Output: " << 0 << endl;
		} else {
			cout << "Output: " << ceil << endl;
		}
		break;
	case ROUND: 
		if(n == 0) {
			cout << "Output: " << 0 << endl;
		} else if(n > 0) {
			cout << "Output: " << (int)(n + 0.5) << endl;
		} else {
			cout << "Output: " << (int)(n - 0.5) << endl;
		}
		break;
	default:
		std::cout << "Please enter a valid option!" << endl;
		break;
	}

	// End.
	return 0;
}