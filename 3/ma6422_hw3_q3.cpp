#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
	// Setting up variables.
	double a, b, c; // Three real numbers, double because they can be negative, or decimals.
	int num_solutions; // Contains number of solutions, depends on result of b * b - 4 * a * c.

	// Process input/get output.
	cout << "Please enter value of a: ";
	cin >> a;
	cout << "Please enter value of b: ";
	cin >> b;
	cout << "Please enter value of c: ";
	cin >> c;

	if ((a == 0) && (b == 0) & (c == 0)) { // Infinite solutions.
		cout << "There are an infinite number of solutions." << endl;
	} else if(a == 0) { // No solution.
		cout << "There are no solutions." << endl;
	} else { // Possible solutions.
		if(((b * b) - 4 * a * c) > 0) { // 2 solution.
			double solution_one, solution_two;
			solution_one = ((-b) + sqrt(((b * b) - 4 * a * c)))/(2 * a);
			solution_two = ((-b) - sqrt(((b * b) - 4 * a * c)))/(2 * a);
			cout << "This equation has two real solutions: x = " << solution_one << " & " << solution_two << endl;
		} else if(((b * b) - 4 * a * c) == 0) { // 1 solution. 
			// We don't need square root here because square root of 0 is 0.
			cout << "This equation has a single real solution: x = " << ((-b) / (2 * a)) << endl;
		} else { // 0 solutions that are real. Has imaginary solutions.
			cout << "There are no real solutions." << endl;
		}
	}

	// End.
	return 0;
}