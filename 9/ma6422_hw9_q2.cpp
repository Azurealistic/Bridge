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

// Checks if two strings are anagrams, punctuation ignored.
bool areAnagrams(string first, string second) {
	const int AB_SIZE = 26;
	int arr[AB_SIZE] = {}; // Set array equal to 0s.
	for(int i = 0; i < first.length(); i++) {
		if(isAlpha(first[i])) {
			arr[getLower(first[i]) - 'a']++;
		}
	}
	for(int i = 0; i < second.length(); i++) {
		if(isAlpha(second[i])) {
			arr[getLower(second[i]) - 'a']--;
		}
	}
	for(int i = 0; i < AB_SIZE; i++) {
		if(arr[i] != 0) {
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[]) {
	string sentence1, sentence2;
	cout << "Please enter first string: ";
	getline(cin, sentence1);
	cout << "Please enter second string: ";
	getline(cin, sentence2);
	if(areAnagrams(sentence1, sentence2)) {
		cout << "These sentences are anagrams!" << endl;
	} else {
		cout << "These sentences are not anagrams!" << endl;
	}
	return 0;
}
