#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str) {
	for(int i = 0; i < str.length(); i++) {
		if(str[i] != str[str.length() - i - 1]) {
			return false;
		} 
	}
	return true;
}

int main(int argc, char const *argv[]) {
	// Input.
	string input;
	cout << "Please enter a word: ";
	cin >> input;

	// Output.
	if(isPalindrome(input)) {
		cout << input << " is a palindrome" << endl;
	} else {
		cout << input << " is not a palindrome" << endl;
	}

	return 0;
}