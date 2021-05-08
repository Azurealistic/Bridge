#include <iostream>

using namespace std;

// Function that takes a given integer n and returns an approximation of e.
// We use the sum of the first n + 1 elements to the inf series.
double eApprox(int n) {
	// We need to get factorials so that will be one loop. 
	double factorial = 1.0, e = 1.0;
	for(int i = 1; i <= n; i++) {
		// Since we already know what i is, we can just keep a running factorial going and use that.
		factorial *= i;
		e += (1.0 / factorial);
	}
	return e;
}

int main(int argc, char const *argv[]) {
	cout.precision(30);
	for(int n = 1; n <= 15; n++) {
		cout << "n = " << n << "\t" << eApprox(n) << endl;
	}
	return 0;
}
