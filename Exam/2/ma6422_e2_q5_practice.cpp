#include <iostream>

/*
So let us break down this function into it's parts and see what happens.

The declaration of this function is: int f(int* n, int m);
Which basically means that the result returned is going to be an integer, it takes a pointer to an integer, as well as a non-pointer, which will be copied.
If we pass a variable to int* n, we need to use the reference operator to do so (or simply pass a pointer), since it is going to be expecting an address.
*/
int f(int* n, int m) {
	*n = 10; // Dereferences the pointer to access the value at the original location of the variable and change it to 10.
	m = 10; // Change the value of m, which is a copy of a variable passed to it to 10. Original is untouched.
	return *n + m; // Return their sum.
}

int main(int argc, char const *argv[]) {
	int n = 5; // Set n and m to 5 to begin with.
	int m = 5;
	// Since the function returns an integer, we can do int res = f() to get the return value into the variable res.
	// Since 'n' is not a pointer, we must pass it to the function via a reference.
	// So to this function we are going to pass the values we set earlier. So n = 5, and m = 5, and we pass the address of n, and value of m = 5 to function.
	int res = f(&n, m); // Returns 20.
	// The function will then overwrite n with a value of 10, and add it to a copy of m, which is also 10. However our m in main is unaffected.
	std::cout << res + n + m << std::endl; // Thus this will print out 20 + 10 + 5 = 35.
	return 0;
}