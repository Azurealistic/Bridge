#include <iostream>

using namespace std;

// Runs in O(n), fastest we're probably gonna get.
int minInArray(int arr[], int arrSize) {
	int curr_minimum = 2147483647; // This is the maximum value an integer can hold, so any number will probably be smaller than this initially and we can not worry about first input.
	for(int i = 0; i < arrSize; i++) {
		if(arr[i] < curr_minimum) {
			curr_minimum = arr[i];
		}
	}
	return curr_minimum;
}

void printIndices(int arr[], int target, int arrSize) {
	for(int i = 0; i < arrSize; i++) {
		if(arr[i] == target) {
			cout << i << " ";
		}
	}
	cout << endl;
} 

int main(int argc, char const *argv[]) {
	// Get input
	int const ARR_SIZE = 20; // This is not a global because it is only used in main and it is good habit to keep them in the correct scope.
	int arr[ARR_SIZE]; // We know this size and it's in the problem statement.
	cout << "Please enter 20 integers separated by a space: ";
	for(int i = 0; i < ARR_SIZE; i++) {
		cin >> arr[i];
	}

	// Output
	int min = minInArray(arr, ARR_SIZE);
	cout << "The minimum value is " << min << ", and it is located in the following indices: ";
	printIndices(arr, min, ARR_SIZE);
	int currIndex = 0;
	while(currIndex != -1) {
		currIndex = printNextMinimum(arr, min, ARR_SIZE, currIndex);
		cout << currIndex;
	}
	return 0;
}