#include <iostream>
#include <cmath>

using namespace std; 

int main(int argc, char const *argv[]) {
	// Variables/get input.
	int input, num_bits = 0, storage;
	cout << "Enter decimal number: ";
	cin >> input;
	cout << "The binary representation of " << input << " is ";
	storage = input;

	// Get number of bits/digits in binary number.
	while(storage > 0) {
		storage /= 2;
		num_bits++;
	}

	if(input == 0) {
		cout << 0;
	}

	// Calculate binary.
	for(int i = num_bits - 1; i >= 0; i--) {
		int k = input / (int) pow(2, i); // Input / pow(2, i).. We want to see if the num5,4ber goes into it.
		cout << k;
		input %= (int) pow(2, i); // Need to get remaining number after removing the 2^i.
	}

	cout << endl;
	
	// End.
	return 0;
}