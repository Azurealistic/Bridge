#include <iostream>

using namespace std;

// A bunch of consecutive loops and I hate it, but hey, it's O(n).
int* findMissing(int arr[], int n, int& resArrSize) {
	resArrSize = 0; // Reset it.
	int* flags = new int[n + 1](); // Create an array of size n + 1, to hold all numbers upto n.
	for(int i = 0; i < n; i++) { // Loop through this array and mark the flag array whenever you find the number in this array.
		flags[arr[i]] += 1;
	}
	for(int i = 0; i < n + 1; i++) { // Loop through this array and count how many 0s there are are.
		if(flags[i] == 0) {
			resArrSize += 1;
		}
	}
	int* missing = new int[resArrSize];
	for(int i = 0, j = 0; i < n + 1; i++) {
		if(flags[i] == 0) {
			missing[j++] = i;
		}
	}
	delete[] flags;
	return missing;
}

int main(int argc, char const *argv[]) {
	int arr[] = {3, 1, 3, 0, 6, 4};
	int resArrSize;
	int* missing = findMissing(arr, 6, resArrSize);
	cout << "Missing Count: " << resArrSize << endl;
	cout << "Missing Numbers: ";
	for(int i = 0; i < resArrSize; i++) {
		cout << missing[i] << ' ';
	}
	cout << endl;
	delete[] missing;
	return 0;
}