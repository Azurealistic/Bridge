#include <iostream>
#include <cmath>

using namespace std;

// Print the divisors of a given number.
// We only need to worry about going upto and also starting from the square root of the num.
void printDivisors(int num) {
	// Lower-set of divisors.
	for(int i = 1; i * i < num; i++) {
		if(num % i == 0) { // Divisor.
			cout << i << " ";
		} 
	}
	
	// Upper sets.
	for(int i = sqrt(num); i >= 1; i--) {
		if(num % i == 0) { // Divisor.
			cout << (num / i) << " ";
		} 
	}
	cout << endl;
}

int main(int argc, char const *argv[]) {
	// Get input and process/return output.
	int input;
	cout << "Please enter a positive integer >= 2: ";
	cin >> input;
	printDivisors(input);
	return 0;
}