#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string parse(std::ifstream& input) {
	string res;
	string line;
	while(getline(input, line)) {
		res.append(line);
	}
	return res;
}

std::string add(std::string n1, std::string n2) {
	// Make sure that the larger string is n2.
	if(n1.length() > n2.length()) {
		std::swap(n1, n2);
	}

	string res = "";

	// Reverse the numbers so carry and stuff is easier.. honestly there are better ways to handle this but this is what I came up with on the fly.
	reverse(n1.begin(), n1.end());
	reverse(n2.begin(), n2.end());

	int carry = 0;
	for(int i = 0; i < n1.length(); i++) {
		int sum = (n1[i] - '0') + (n2[i] - '0') + carry;
		res.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	for(int i = n1.length(); i < n2.length(); i++) {
		int sum = (n2[i] - '0') + carry;
		res.push_back(sum % 10 + '0');
		carry = sum / 10;
	}

	if(carry > 0) {
		res.push_back(carry + '0');
	}

	// Reverse again.
	reverse(res.begin(), res.end());
	return res;
}

int main(int argc, char const *argv[]) {
	ifstream input1("num1.txt");
	ifstream input2("num2.txt");
	ofstream output("res.txt");
	
	auto n1 = parse(input1);
	auto n2 = parse(input2);

	input1.close();
	input2.close();

	output << add(n1, n2);
	output.close();
	return 0;
}