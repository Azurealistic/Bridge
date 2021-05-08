#include <iostream>

using namespace std;

int min(int x, int y);
int lowestCost(int arr[], int arrSize);

int main(int argc, char const *argv[]) {
	int arr[] = {0, 3, 80, 6, 57, 10, 3, 50, 60, 1000, 1001, 50, 9};
	cout << lowestCost(arr, 13) << endl;
	return 0;
}

int min(int x, int y) {
	return (x < y) ? x : y;
}

int lowestCost(int arr[], int arrSize) {
	// Can always finish on next move at this point.
	if(arrSize <= 3) {
		return arr[arrSize - 1];
	}
	// Compute cost of each branch and compare, add to current final index and go from there.
	return min(lowestCost(arr, arrSize - 1), lowestCost(arr, arrSize - 2)) + arr[arrSize - 1];
}