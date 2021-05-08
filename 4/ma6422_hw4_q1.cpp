#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	// Section A. While loop.
	cout << "section a" << endl;

	// Variables and get input.
	int n; 
	cout << "Please enter a positive integer: ";
	cin >> n;
	int num = 0; // First even number is always 2.
	while(n > 0) {
		cout << (num += 2) << endl;
		n--;
	}

	// Section B. For loop.
	cout << "section b" << endl;

	// Variables and get input.
	cout << "Please enter a positive integer: ";
	cin >> n;
	for(int k = 2; k <= (n * 2); k += 2) {
		cout << k << endl;
	}

	// End.
	return 0;
}