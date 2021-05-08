#include <fstream>
#include <sstream>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool validityChecker(fstream& fs);

int main(int argc, char const *argv[]) {
	string filename;
	fstream fs;
	bool valid = false;
	cout << "Please enter the file name: ";
	cin >> filename;
	fs.open(filename);
	if(fs.fail()) {
		cout << "File \"" << filename << "\" does not exist" << endl;
		exit(1);
	} else {
		valid = validityChecker(fs);
		if(valid) {
			cout << "The symbols in this file are balanced." << endl;
		 } else {
			cout << "The symbols in this file are not balanced." << endl;
		 }
	}
	fs.close();
	return 0;
}

bool validityChecker(fstream& fs) {
	stack<string> s; // I don't have a better name for it.
	string l, r; // These strings are for push/pop operations and matching stuff.
	while(fs >> r) { // Goes until end of file pretty much, reading in one token at a time. Tokens are separated by white-space.
		if(r == "BEGIN" || r == "begin") {
			s.push(r);
		} else if(r == "END;" || r == "end;" || r == "END." || r == "end." || r == "END" ||  r == "end") {
			if(s.empty()) {
				return false;
			} else {
				l = s.top();
				s.pop();
				if(l != "BEGIN" && l != "begin") {
					return false;
				}
			}
		}  else {
			for(const auto& c : r) {
				string y = string(1, c);
				if(y == "(" || y == "{" || y == "[") {
					s.push(y);
				} else if(y == ")" || y == "}" || y == "]") {
					if(s.empty()) {
						return false;
					} else if(y == ")") {
						l = s.top();
						s.pop();
						if(l != "(") {
							return false;
						}
					} else if(y == "}") {
						l = s.top();
						s.pop();
						if(l != "{") {
							return false;
						}
					} else if(y == "]") {
						l = s.top();
						s.pop();
						if(l != "[") {
							return false;
						}
					} else {
						s.pop();
					}
				}
			}
		}
	}
	if(s.empty()) {
		return true;
	} else { 
		return false;
	}
}