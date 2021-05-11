#include <iostream>
#include <string>
#include <stack>
#include <map>

int main() {
	std::string input, output;
	std::cout << "Infix: ";
	std::cin >> input;

	std::stack<char> ops;

	std::map<char, int> lookup = {
		{'^', 3},
		{'/', 2},
		{'*', 2},
		{'+', 1},
		{'-', 1}
	};

	for (auto const& c : input) {
		if (std::isdigit(c)) {
			output += c;
		} else if (c == '(') {
			ops.push(c);
		} else if (c == ')') {
			while (!ops.empty() && ops.top() != '(') {
				output += ops.top();
				ops.pop();
			}
			ops.pop();
		} else {
			while (!ops.empty() && lookup[c] <= lookup[ops.top()]) {
				output += ops.top();
				ops.pop();
			}
			ops.push(c);
		}
	}

	while (!ops.empty()) {
		output += ops.top();
		ops.pop();
	}

	std::cout << output << std::endl;

	return 0;
}