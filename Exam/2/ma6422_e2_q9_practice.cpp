#include <iostream>

/*
This function is similar to Q5.. so it returns an integer, takes a pointer to an int n, and an int m.
*/
int g(int* n, int m) {
	*n += 12; // Adds 12 to the original number stored wherever the pointer is pointing.
	m = 6; // Makes the copy of m equal to 6, but original untouched.
	return *n + 4 * m; // Returns (n + 12) + (4 * 6) = (n + 12) + (24) = n + 36
}

// Takes a pointer to an integer, and a reference, which means that both numbers are going to affect the original.
int f(int* n, int& m) { 
	m += 4; // Add 4 to the m.
	*n = 5; // Changes the n to 5.
	return g(n, m); // Returns the value of g(n, m) = g(5, m + 4).. which should be 5 + 36 = 41?
}

int main() {
	int n = 12; // Define n and m as 12 and 3
	int m = 3;

	/*
	n = 12;
	m = 3;
	Pass the value of f(12, 3) to the function.
	So then what happens is originals are changed to be similar to...
	n = 5;
	m = 7;
	Pass the values to the function g(5, 7) which results in.. return value of 41 and that n will become 5 + 12 = 17.
	Result should be 41, 17, 7
	*/
	std::cout << f(&n, m) << " " << n << " "<< m << std::endl;
}