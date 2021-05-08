#include <iostream>
#include <string>

using namespace std;

bool isAlpha(char c) {
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int getWordCount(string sentence) {
	int wordCount = 0;
	char last = ' ';
	// Count number of words.
	for(int i = 0; i < sentence.length(); i++) {
		if(sentence[i] != ' ' && last == ' ') {
			wordCount += 1;
		}
		last = sentence[i];
	}
	return wordCount;
}

string* createWordArray(string sentence, int& outWordsArrSize) {
	outWordsArrSize = getWordCount(sentence); // O(n) operation.
	string* words = new string[outWordsArrSize]();
	// Add to words, also O(n).
	for(int i = 0, j = 0; i < sentence.length(); i++) {
		if(sentence[i] == ' ') {
			j += 1;
		} else {
			if(isAlpha(sentence[i]) || sentence[i] == '-') {
				words[j] += sentence[i];
			}
		}
	}
	return words;
}

int main(int argc, char const *argv[]) {
	string input;
	int wordCount = 0;
	cout << "Please enter a sentence: ";
	getline(cin, input);
	string* res = createWordArray(input, wordCount);
	cout << "Word count: " << wordCount << endl;
	cout << "Words:" << endl;
	for(int i = 0; i < wordCount; i++) {
		cout << res[i] << endl;
	}
	delete[] res;
	return 0;
}