#include <iostream>

using namespace std;

// Function that prints a triangle line count n, with a shift of m and a given symbol.
void printShiftedTriangle(int n, int m, char symbol) {
	// The initial spaces for the top most row are 1 less than line count, plus the shift.
	int initial_spaces = n - 1 + m;
	// Maximum characters start at 1 and end at some other odd integer.
	int max_chars = 1;

	// Print the triangle out.
	for(int i = 0; i < n; i++) {
		for(int s = 0; s < initial_spaces; s++) {
			cout << " ";
		}
		for(int j = 0; j < max_chars; j++) {
			cout << symbol;
		}
		cout << endl;
		max_chars += 2;
		initial_spaces -= 1;
	}
}

// Function that constructs a tree. Accounts for the correct shifting and symbols.
void printPineTree(int n, char symbol) {
	// We will have triangles from 2 till n. And the maximum shift is going to be n - 1 and decreasing till 0.
	int shift = n - 1;
	for(int i = 2; i <= n + 1; i++, shift--) {
		printShiftedTriangle(i, n - i + 1, symbol);
	}
}

int main(int argc, char const *argv[]) {
	int n; 
	char symbol;
	cout << "Please enter the number of triangles in the tree and a symbol in one line. (e.g. 5 %): ";
	cin >> n >> symbol;
	printPineTree(n, symbol);
	return 0;
}