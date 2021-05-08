#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
	// Input.
	int n;
	cout << "Please enter a positive integer:" << endl;
	cin >> n;

	// Process and display.
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << i * j << "\t";
		}
		cout << endl;
	}

	// End.
	return 0;
}