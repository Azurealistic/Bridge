#include <iostream>
#include <cmath>

using namespace std;

// Take a number greater than or equal to 2, and update nums with amount of divisors and total sum.
// What is the point of a variable that is never used anywhere else in the program? outCountDivs??!?
void analyzeDividors(int num, int& outCountDivs, int& outSumDivs) {
	// Reset the variables since they may be different when going into program.
	outCountDivs = 1; // First and last are always a given.
	outSumDivs = 1;
	// Loop through and calculate everything, and update the correct variables as needed.
	for(int i = 2; i <= sqrt(num); i++) {
		if(num % i == 0) {
			// If it is a divisor we update count by 1.
			outCountDivs += 1;
			// Update the sum with the correct value.
			if(i == (num / i)) {
				outSumDivs += i;
			} else {
				outSumDivs += (i + (num / i));
				outCountDivs += 1; // An extra divisor has to be accounted for here.
			}
		}
	}
}

// Perfect numbers simply have their own value as the sum of their proper divisors.
bool isPerfect(int num) {
	int count, sum;
	analyzeDividors(num, count, sum); // THIS is called N times.
	return (num == sum);
}

int main(int argc, char const *argv[]) {
	int n;
	cout << "Please enter a number >= 2: ";
	cin >> n;
	int count;
	cout << "Perfect numbers from 2 to " << n << " are: ";

	// Iterate from 2 to N
	for(int i = 2; i <= n; i++) {
		if(isPerfect(i)) { // Called N times. 
			cout << i << " ";
		}
	}
	// overall above (analyze is called N times => O(n))
	cout << endl;

	// This is O(scary), but seems quick enough in practice.
	cout << "Amicable pairs from 2 to " << n << " are: " << endl;
	// Iterating from 2 to N
	for(int i = 2; i <= n; i++) {

		int first = i;
		analyzeDividors(i, count, first); // The first call is for example call #1 

		if(first > i && first <= n) {
			int second;
			analyzeDividors(first, count, second);  // Call #2 So we have two total calls
			
			if(second == i) {
				cout << i << " " << first << endl; 
			}
		}
	}
	// Total times analyze dividors is called is 2 * N = 2N => O(2N) => O(N)

	return 0;
}