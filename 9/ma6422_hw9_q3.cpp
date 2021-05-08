#include <iostream>

using namespace std;

void printArray(int arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		cout << arr[i] << ' ';
	}
	cout << endl;
}

// It's going to return an array, it takes an array input, integer, and a reference to the logical size.
int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
	int* temp = new int[arrSize];
	int pos = 0;
	for(int i = 0; i < arrSize; i++) {
		if(arr[i] > 0) {
			temp[pos++] = arr[i];
		}
	}
	outPosArrSize = pos; // Update logical size.
	return temp;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
	int* temp = new int[arrSize];
	int pos = 0;
	for(int i = 0; i < arrSize; i++) {
		if(arr[i] > 0) {
			temp[pos++] = arr[i];
		}
	}
	*outPosArrSizePtr = pos;
	return temp;
}

// int*& is a reference to a pointer that is an int.
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
	int pos = 0;
	outPosArr = new int[arrSize];
	for(int i = 0; i < arrSize; i++) {
		if(arr[i] > 0) {
			outPosArr[pos++] = arr[i];
		}
	}
	outPosArrSize = pos;
}

// So outPosArrPtr is a pointer to a pointer to the beginning of the array.
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
	int* temp = new int[arrSize];
	int pos = 0;
	for (int i = 0; i < arrSize; i++) {
		if (arr[i] > 0) {
			temp[pos++] = arr[i];
		}
	}
	outPosArrSizePtr = &pos;
	*outPosArrPtr = temp;
}

int main(int argc, char const *argv[]) {
	// Static array to test stuff with.
	int arr[] = {3, -1, -3, 0, 6, 4};
	const int SIZE = 6;
	cout << "Original Array: ";
	printArray(arr, SIZE);

	cout << "Section A: ";
	int outPosArrSize = 0;
	int* k = getPosNums1(arr, SIZE, outPosArrSize);
	printArray(k, outPosArrSize);
	delete[] k;

	cout << "Section B: ";
	int j = 0;
	int* outPosArrSizePtr = &j; // We need to have the pointer point to something before we dereference it.
	int* r = getPosNums2(arr, SIZE, outPosArrSizePtr);
	printArray(r, *outPosArrSizePtr);
	delete[] r;

	cout << "Section C: ";
	int* outPosArr; // We can use the outPosArrSize from Section A.
	getPosNums3(arr, SIZE, outPosArr, outPosArrSize);
	printArray(outPosArr, outPosArrSize);
	delete[] outPosArr;

	cout << "Section D: ";
	// Reuse outPosArrSizePtr from Section B.
	outPosArrSizePtr = &outPosArrSize; // So assign it to the relevant variable.
	int** outPosArrPtr = &outPosArrSizePtr; // It doesn't matter what this is set to, it's overwritten anyways, it just can't be nullptr to begin with.
	getPosNums4(arr, SIZE, outPosArrPtr, outPosArrSizePtr);
	printArray(*outPosArrPtr, *outPosArrSizePtr);
	delete[] *outPosArrPtr;

	return 0;
}