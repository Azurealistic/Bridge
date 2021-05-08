#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	// Variables and get input.
	int n; 
	cout << "Please enter a positive integer: ";
	cin >> n;

	for(int k = 1; k <= n; k++) { // Need to loop through all numbers from 1 to N.
		int curr = k; // What is the current number we are dealing with?
		int odds = 0, evens = 0; // Need to count even and odd digits, so we will keep two integers as tracking counters.
		while(curr > 0) {
			int remainder = curr % 10; // Gets last digit.
			if(remainder % 2 == 0) {
				evens++;
			} else {
				odds++;
			}
			curr /= 10;
		}
		if(evens > odds) {
			cout << k << endl;
		}
	}

	// End.
	return 0;
}
