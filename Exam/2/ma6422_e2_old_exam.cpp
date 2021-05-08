/*
Make a function that takes two sorted arrays and in linear time (n1 + n2) constructs an XOR array.
1 2 3 5 7 8
2 5 6 9
-----------
1 3 6 7 8 9

1 < 2 = T

V:	1 
I:	0 

2 < 2
2 > 2

3 < 5
*/

#include <iostream>

using namespace std;

void makeXORArray(int* srtArr1, int* srtArr2, int n1, int n2, int** outXORArr, int* outN) {
	// First off we know that the maximum physical size of this array possible is if both input arrays are unique, thus n1 + n2.
	int* outArr = new int[n1 + n2];
	// Logical size starts off at zero.
	int size = 0;
	// Logic essentially follows that we just go through each array and if at any point both numbers are same, we skip over them. Else we add to the array.
	int s1 = 0, s2 = 0;
	while(s1 < n1 && s2 < n2) {
		// If the second array has a larger item, we increment the first array position and copy over that item.
		if(srtArr1[s1] < srtArr2[s2]) {
			outArr[size++] = srtArr1[s1++];
		} else if(srtArr1[s1] > srtArr2[s2]) {
			outArr[size++] = srtArr2[s2++];
		} else { // They are both equal.
			s1++;
			s2++;
		}
	}
	// Process any remaining numbers.
	while(s1 < n1){
		outArr[size++] = srtArr1[s1++];
	}
	while(s2 < n2){
		outArr[size++] = srtArr2[s2++];
	}
	// Copy over the size.
	*outN = size;
	*outXORArr = outArr;
	outArr = nullptr;
}

void print(int arr[], int size) {
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main(int argc, char const *argv[]) {
	int a1[] = {1, 2, 3, 5, 7, 8};
	int a2[] = {2, 5, 6, 9};
	print(a1, 6);
	print(a2, 4);
	int out;
	int* res;
	makeXORArray(a1, a2, 6, 4, &res, &out);
	print(res, out);
	return 0;
}
