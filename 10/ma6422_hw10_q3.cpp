#include <iostream>
#include <vector>
#include <algorithm> // Need for std::find.

using namespace std;

int* resize(int arr[], int arrSize, int factor) {
	int newSize = arrSize * factor;
	int* new_arr = new int[newSize]();
	for (int i = 0; i < arrSize; i++) {
		new_arr[i] = arr[i];
	}
	delete[] arr;
	return new_arr;
}

void print(int arr[], int size) {
	for(int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

// Non-vector version
void main1() {
	int curr = 0, c_max = 10, input = 0, search;
	int* arr = new int[c_max];
	cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
	cout << "End your input by typing -1." << endl;
	while(input != -1) {
		if (input != -1) {
			cin >> input;
			arr[curr++] = input;
		}
		if (curr == c_max) {
			arr = resize(arr, c_max, 2);
			c_max *= 2;
		}
	}
	cout << "Please enter a number you want to search." << endl;
	cin >> search;
	int count = 0; // Count how many instances there are ahead of time, so I know when to place the period.
	for (int i = 0; i < curr; i++) {
		if (arr[i] == search) {
			count += 1;
		}
	}
	if (count == 0) {
		cout << search << " does not exist in the sequence." << endl; // Display if it does exist.
	} else {
		cout << search << " shows in lines ";
		for (int i = 0; i < curr; i++) {
			if (arr[i] == search) {
				cout << i + 1;
				if (count != 1) {
					cout << ", ";
				}
				else {
					cout << ".";
				}
				count -= 1;
			}
		}
	}
	delete[] arr;
}

// Vector version
void main2() {
	vector<int> nums;
	int curr = 0, search;
	cout << "Please enter a sequence of positive integers, each in a separate line." << endl;
	cout << "End your input by typing -1." << endl;
	while (curr != -1) {
		if (curr != -1) {
			cin >> curr;
			nums.push_back(curr);
		}
	}
	cout << "Please enter a number you want to search." << endl;
	cin >> search;
	int count = 0; // Count how many instances there are ahead of time, so I know when to place the period.
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == search) {
			count += 1;
		}
	}
	if (count == 0) {
		cout << search << " does not exist in the sequence." << endl; // Display if it does exist.
	}
	else {
		cout << search << " shows in lines ";
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == search) {
				cout << i + 1;
				if (count != 1) {
					cout << ", ";
				}
				else {
					cout << ".";
				}
				count -= 1;
			}
		}
	}
}

int main(int argc, char const* argv[]) {
	int version;
	cout << "Please enter which version to test: " << endl;
	cout << "1. Non-vector." << endl << "2. Vector." << endl;
	cin >> version;
	if (version == 1) {
		main1();
	}
	else if (version == 2) {
		main2();
	}
	else {
		cout << "Invalid choice!" << endl;
	}
	cin >> version;
	return 0;
}