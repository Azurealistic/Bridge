#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
	// Setting up variables.
	int curr_year, grad_year;
	string name;

	// Get input.
	cout << "Please enter your name: ";
	cin >> name;
	cout << "Please enter your graduation year: ";
	cin >> grad_year;
	cout << "Please enter current year: ";
	cin >> curr_year;

	// Process and output.
	if(curr_year >= grad_year) {
		cout << name << ", you have graduated! Congratulations!";
	} else if((curr_year + 4) == grad_year) {
		cout << name << ", you are a Freshman!" << endl;
	} else if((curr_year + 3) == grad_year) {
		cout << name << ", you are a Sophmore!" << endl;
	} else if((curr_year + 2) == grad_year) {
		cout << name << ", you are a Junior!" << endl;
	} else if((curr_year + 1) == grad_year) {
		cout << name << ", you are a Senior!" << endl;
	} else {
		cout << name << ", you are not in college yet!" << endl;
	}
 
	// End.
	return 0;
}
