#include <iostream>

/*
For this problem we are going to print a diamond that has spaces between each star.
Let us treat n = 5, and n = 6 and examine:

N = 5.

....*
...* *
..* * *
.* * * *
* * * * *
.* * * *
..* * *
...* *
....*

N = 6.

.....*
....* *
...* * *
..* * * *
.* * * * *
* * * * * *

.* * * * *
..* * * *
...* * *
....* *
.....*

Key observations:
1. First being that the number of maximum spaces is going to be N - 1, and lowest is going to be 0.
2. There are going to be 2N - 1 total rows. 
3. Rows 0 to N - 1 are increasing, rows N to 2N - 2 decreasing.

So using this information we can start coding up a solution.
*/

using namespace std;

int main(int argc, char const *argv[]) {

	int n;
	std::cout << "Enter a number: ";
	cin >> n;

	int spaces = n - 1; // Spaces variable holds the number of spaces needed, either as starting point or limit.

	// Draw the top half + middle row.
	for(int t = 1; t <= n; t++) { // Going from row 0 to row 5. So we use <=, not <.
		for(int s = spaces; s > 0; s--) { // Spaces start at N and go down to N - 1.
			cout << ' ';
		}
		for(int j = 0; j < t; j++) { // We just need to go to t, since we want every star and no skipped lines/extra stars per line.
			cout << "* "; // Just throw an extra at end of the star.
		}
		spaces--; // Decrease max possible spaces.
		cout << endl;
	}

	// Draw the bottom half.
	spaces = 0;
	for(int t = n - 1; t > 0; t--) { // start at n - 1 and go down since we don't include middle row.
		for(int s = 0; s <= spaces; s++) { // If we do < it's offset by 1.
			cout << " ";
		}
		for(int j = 0; j < t; j++) {
			cout << "* "; // Same idea as before.
		}
		spaces++; // Increase max possible spaces, since we're going other way.
		cout << endl; 
	}

	return 0;
}