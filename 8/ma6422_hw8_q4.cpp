#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Creates a random mapping for the integers in an array.
void scramble(int arr[], int arrSize) {
	for(int i = 0; i < arrSize; i++) {
		arr[i] = (rand() % 3) + 1; // Random number from 1 to 3.
	}
}

bool auth(int arr[], int arrSize, const int PIN[], int pinSize, int input) {
	pinSize -= 1; // Start at index 4 of array.
	while(input > 0) {
		int digitNum = input % 10; // Get last digit of number.
		int digitPin = PIN[pinSize];
		if(digitNum != arr[digitPin]) {
			return false;
		}
		input /= 10;
		pinSize -= 1;
	}
	return true;
}

void printMapping(int arr[], int arrSize) {
	cout << "PIN:\t0 1 2 3 4 5 6 7 8 9" << endl;
	cout << "NUM:\t";
	for(int i = 0; i < arrSize; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(int argc, char const *argv[]) {
	// Defining constants in correct scope.
	const int ARR_SIZE = 10;
	const int PIN_SIZE = 5;
	const int PIN[PIN_SIZE] = {0, 8, 0, 8, 5}; 

	srand(time(0)); // Set up time seed/randomly.

	int input;
	int arr[ARR_SIZE] = {0, 0, 0, 0, 3, 0, 0, 0, 0, 0}; // Doesn't matter if it's all 0, it gets redefined in a second.
	scramble(arr, ARR_SIZE);

	cout << "Please enter your PIN according to the following mapping:" << endl;
	printMapping(arr, ARR_SIZE);
	cin >> input;

	if(auth(arr, ARR_SIZE, PIN, PIN_SIZE, input)) {
		cout << "Your PIN is correct" << endl;
	} else {
		cout << "Your PIN is not correct" << endl;
	}

	return 0;
}