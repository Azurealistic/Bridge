#include <iostream>

/*
Finding the sum of individual digits in an integer, no negative or double numbers will be given.
*/

using namespace std;

int main(int argc, char const *argv[]) {
	// Two variables, one to grab input and one to hold the sum. We will need to initialize the sum with 0 to begin with.
	int input, sum = 0;

	// Grab input from user.
	cout << "Enter a number: ";
	cin >> input;

	// Calculate the sum of digits and then print it out.
	while(input > 0) { // This loop will repeat until input is 0, or lower.
		// In this loop we want to grab each digit of the number, and add it to the sum.
		// Grabbing the last digit is easier than the first, and we can do so via num % 10.
		sum += input % 10;
		// Once we added the last digit, we need to actually get rid of it from the number. So we divide by 10.
		input /= 10;
	}
	cout << "The sum of the digits is: " << sum << endl;

	return 0;
}
