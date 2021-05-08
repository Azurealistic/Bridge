#include <iostream>

using namespace std;

void printSymbol(int n, char c);
void printTriangle(int n);
void printOppositeTriangles(int n);
void printRuler(int n);

int main(int argc, char const *argv[]) {
	int n;
	cout << "Input a positive integer: ";
	cin >> n;
	cout << "Section A:" << endl;
	printTriangle(n);
	cout << "Section B:" << endl;
	printOppositeTriangles(n);
	cout << "Section C:" << endl;
	printRuler(n);
	return 0;
}

void printSymbol(int n, char c) {
	for(int i = n; i > 0; i--) {
		cout << c;
	}
	cout << endl;
}

void printTriangle(int n) {
	if(n == 0) {
		return; // Assume that the base case is printing nothing.
	}
	printTriangle(n - 1); // If this is before the for loop we print out increasing number of *, if it's after we print decreasing number of *.
	printSymbol(n, '*');
}

void printOppositeTriangles(int n) {
	if(n == 0) {
		return;
	} 
	printSymbol(n, '*');
	printOppositeTriangles(n - 1);
	printSymbol(n, '*');
}

void printRuler(int n) {
	if(n == 0) {
		return; 
	}
	printRuler(n - 1);
	printSymbol(n, '-');
	printRuler(n - 1);
}
