#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
	// Input.
	string first, middle, last;
	cout << "Please enter your full name: ";
	cin >> first >> middle >> last;
	// Output
	cout << last << ", " << first << " " << middle[0] << ".";
	return 0;
}