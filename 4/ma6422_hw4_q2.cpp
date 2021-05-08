#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	// Variables.
	int input = 0;

	// Get input.
	cout << "Enter decimal number:" << endl;
	cin >> input;

	// Process & Output.
	cout << input << " is ";

	while(input > 0) {
		if(input >= 1000) {
			int m = input / 1000;
			for(int n = 0; n < m; n++) {
				cout << "M";
			}
			input %= 1000;
		} else if(input >= 500) {
			int d = input / 500;
			for(int n = 0; n < d; n++) {
				cout << "D";
			}
			input %= 500;
		} else if(input >= 100) {
			int c = input / 100;
			for(int n = 0; n < c; n++) {
				cout << "C";
			}
			input %= 100;
		} else if(input >= 50) {
			int l = input / 50;
			for(int n = 0; n < l; n++) {
				cout << "L";
			}
			input %= 50;
		} else if(input >= 10) {
			int x = input / 10;
			for(int n = 0; n < x; n++) {
				cout << "X";
			}
			input %= 10;
		} else if(input >= 5) {
			int v = input / 5;
			for(int n = 0; n < v; n++) {
				cout << "V";
			}
			input %= 5;
		} else {
			int i = input / 1;
			for(int n = 0; n < i; n++) {
				cout << "I";
			}
			input %= 1;
		}
	}

	cout << endl;

	// End.
	return 0;
}