#include <iostream>
#include <string>

using namespace std;

// Returns lowercase version of the letter.
char getLower(char c) {
	if(c >= 'A' && c <= 'Z') {
		return c + 32;
	}
	return c;
}

// Check if a given character is a letter in the alphabet.
bool isAlpha(char c) {
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// Check if it is a delimiter
bool isDelim(char c) {
	return (c == '.' || c == ' ' || c == '\n' || c == '\t' || c == ',');
}

// Function that breaks down a string into it's letter components, and returns the word count in the string. Input array is size 26, for alphabet.
int breakdown(string str, int arr[]) {
	int wordCount = 0;
	char last = '.'; // Set this to period to start with because it doesn't actually matter. Just need it to be a delimiter.
	for(int i = 0; i < str.length(); i++) {
		if(!isDelim(str[i]) && isDelim(last)) {
			wordCount += 1; // Count words.
		}
		last = str[i]; 
		if(isAlpha(str[i])) {
			arr[getLower(str[i]) - 'a'] += 1;
		}
	}
	return wordCount; 
}

int main(int argc, char const *argv[]) {
	// An array that is 26 long to hold character counts. Since there are 26 letters in the alphabet.
	const int AB_SIZE = 26;
	int arr[AB_SIZE] = {}; // Initialize all to 0.
	cout << "Please enter a line of text:" << endl;
	string line;
	getline(cin, line);
	cout << "words\t" << breakdown(line, arr) << endl;
	for(char i = 'a', j = 0; i <= 'z'; i++, j++) {
		if(arr[j] > 0) {
			cout << i << "\t" << arr[j] << endl;
		}
	}
	return 0;
}