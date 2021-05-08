#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[]) {
	// Set up variables and seed random function.
	srand(time(0));
	int target = (rand() % 100) + 1; // Generate number from 1 to 100, inclusive.
	const int max_guesses = 5;
	int guesses_made = 0, min_guess = 1, max_guess = 100, guess;
	bool found = false;

	cout << "I thought of a number between 1 and 100! Try to guess it!" << endl;

	while(guesses_made < max_guesses) {
		cout << "Range: [" << min_guess << ", " << max_guess << "], Number of guesses left: " << (max_guesses - guesses_made) << endl;
		// Guess the actual number.
		cout << "Your guess: ";
		cin >> guess;
		guesses_made += 1;
		// Perform calculation and see if it is higher, lower or the actual number, and account for that.
		if(guess == target) { // If our guess is accurate we just say yes and stop!
			cout << "Congrats! You guessed my number in " << guesses_made << " guesses!" << endl;
			found = true;
			break; // To exit out of loop cause it's easier and makes sense over using an extra variable.
		} else if(guess < target) {  // If guess is smaller than target number, then we have to say that number is higher.
			if((max_guesses - guesses_made) != 0) {
				cout << "Wrong! My number is bigger." << endl;
				// Update only if guess number is larger than previous min_guess.
				if(min_guess < guess) {
					min_guess = guess + 1;
				}
			}
		} else { // If guess is larger than target, we have to say that number is lower.
			if((max_guesses - guesses_made) != 0) {
				cout << "Wrong! My number is smaller." << endl;
				if(max_guess > guess) {
					max_guess = guess - 1;
				}
			}
		}
	}

	// Runs only if we are out of guesses;
	if((max_guesses - guesses_made) == 0 && found == false) {
		cout << "Out of guesses! My number is " << target << "." << endl;
	}

	return 0;
}
