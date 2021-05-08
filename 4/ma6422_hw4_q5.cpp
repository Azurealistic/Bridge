#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	// Variables and get input.
	int n; 
	cout << "Please enter a positive integer: ";
	cin >> n;

	// Prints top half.
	int spaces = 0;
	for(int t = n; t > 0; t--) {
		for(int s = 0; s < spaces; s++) {
			cout << " ";
		}
		for(int j = 0; j < (t * 2 - 1); j++) {
			cout << "*";
		}
		spaces++;
		if(t != 1) {
			cout << endl;
		}
	}

	// Prints bottom half.
	spaces = n;
	for(int t = 0; t <= n; t++) {
		for(int s = spaces; s > 0; s--) {
			cout << " ";
		}
		for(int j = 0; j < (t * 2 - 1); j++) {
			cout << "*";
		}
		spaces--;
		cout << endl;
	}

	// End.
	return 0;
}
