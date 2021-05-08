#include <iostream>

using namespace std;

/*
arr = [5, 2, 11, 7, 6, 4]
so desired result is 5, 11, 7, 4, 6, 2
*/

void printArray(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

void swap_nums(int& a, int& b) {
    int t = a;
    a = b;
    b = t;
}

void oddsKeepEvensFlip(int arr[], int arrSize) {
    int* temp = new int[arrSize];
    int min = 0, max = arrSize - 1;
    for(int i = 0; i < arrSize; i++) {
        if(arr[i] % 2 == 1) {
            temp[min++] = arr[i];
        } else {
            temp[max--] = arr[i];
        }
    }
    for(int i = 0; i < arrSize; i++) {
        arr[i] = temp[i];
    }
    delete[] temp;
}

int main(int argc, char const *argv[]) {
	const int ARR_SIZE = 6;
	int arr[ARR_SIZE] = {1, 2, 3, 4, 5, 6};
	oddsKeepEvensFlip(arr, ARR_SIZE);
	printArray(arr, ARR_SIZE);
	return 0;
}