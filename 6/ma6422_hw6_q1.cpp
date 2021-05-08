#include <iostream>

using namespace std;

// Return the n'th element of the Fibonacci sequence.
// 1, 1, 2, 3, 5, 8, 13, 21, 34, 55.
int fib(int n) {
	// If n is less than or equal to 1, we just return n. That handles the starting case.
	if(n <= 1) {
		return n;
	}
	
	// Fib numbers are calculated by doing F(i) = F(i - 1) + F(i - 2).
	// So we start with previous being 0 and curr being 1, and go from there.
	int prev = 0, curr = 1;
	for (int i = 0; i < n - 1; i++)
	{
		int next = prev + curr;
		prev = curr;
		curr = next;
	}

	// Print out the n'th fib number.
	return curr;
}

int main(int argc, char const *argv[]) {
	// Get input.
	int n; 
	cout << "Please enter a positive integer: ";
	cin >> n;
	// Print result.
	cout << fib(n) << endl;
	// End.
	return 0;
}