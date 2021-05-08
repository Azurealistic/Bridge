#include <iostream>

// Similar to HW8 Q3... shouldn't need much explanation.
void swap(int& a, int& b) {
	int t = a;
	a = b;
	b = t;
}

void moveZeros(int nums[], int arrSize) {
	for(int i = 0, j = 0; i < arrSize; i++) {
		if(nums[i] != 0) {
			swap(nums[i], nums[j++]);
		}
	}
}

void printArray(int arr[], int arrSize) {
	for(int i = 0; i < arrSize; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
	int arr[] = {0, 2, 0, 1, 0};
	printArray(arr, 5);
	moveZeros(arr, 5);
	printArray(arr, 5);
	return 0;
}