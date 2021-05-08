#include <iostream>

using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main(int argc, char const *argv[]) {
	// Some driver code to test it.
	int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
	cout << "Sum of Squares: " << sumOfSquares(arr, 10) << endl;
	if(isSorted(arr, 10)) {
		cout << "Array is sorted!" << endl;
	} else {
		cout << "Array is not sorted!" << endl;
	}
	return 0;
}

int sumOfSquares(int arr[], int arrSize) {
	int index = arrSize - 1;
	if(arrSize <= 1) {
		return arr[0] * arr[0]; // Base case occurs at index #0, which is arraySize #1.
	} else {
		return sumOfSquares(arr, index) + (arr[index] * arr[index]);
	}
}

bool isSorted(int arr[], int arrSize) {
	if(arrSize <= 1) {
		return true; // Check if we only have 1 or no elements left.
	}
	if(arr[arrSize - 1] < arr[arrSize - 2]) {
		return false; // If it's unsorted we return a false;
	}
	return isSorted(arr, arrSize - 1); // Check next set.
}