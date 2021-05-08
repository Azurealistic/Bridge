#include <iostream>
#include <string>

using namespace std;

bool isDigit(char c) {
	if(c < '0' || c > '9') {
		return false;
	}
	return true;
}

bool isSpace(char c) {
	return (c == ' ');
}

int findFirstDigit(std::string input, int startingPoint, bool inverse) {
	for(int i = startingPoint; i < input.length(); i++) {
		if(inverse == true) {
			if(!isDigit(input[i])) {
				return i;
			}
		} else {
			if(isDigit(input[i])) {
				return i;
			}
		}
	}
	return -1; 
}
 
string censor(string str) {
	int p, q = 0;
	while(q != str.length()) {
		p = findFirstDigit(str, q, false);
		if(p == -1) {
			break;
		}	
		q = findFirstDigit(str, p, true);
		if(q == -1) {
			q = str.length();
		}
		bool sB = (p == 0 || isSpace(str[p - 1]));
		bool sA = (q == str.length() || isSpace(str[q]));
		if(sB && sA) {
			for(int i = 0; i < (q - p); i++) {
				str[i + p] = 'x';
			}
		}
	}
	return str;
}

int main(int argc, char const *argv[]) {
	string line;
	cout << "Please enter a line of text:" << endl;
	getline(cin, line);
	cout << censor(line) << endl;
	return 0;
}