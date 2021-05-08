#include <iostream>

using namespace std; 

int main(int argc, char const *argv[]) {
	// Setting up variables.
	double price_first, price_second, tax_rate, total_price;
	char has_card;

	// Get input.
	cout << "Enter price of first item: ";
	cin >> price_first;
	cout << "Enter price of second item: "; 
	cin >> price_second;
	cout << "Does customer have a club card? (Y/N): ";
	cin >> has_card;
	cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
	cin >> tax_rate;

	// Process input/send output.
	cout << "Base price: " << (price_first + price_second) << endl;

	if(price_first > price_second) { // We need to check which of the two prices are lower, and cut that in half and add it to other.
		total_price = price_first + (price_second / 2);
	} else { // Else if second is equal or greater than first, we just do it the other way around.
		total_price = (price_first / 2) + price_second;
	}

	if(has_card == 'y' || has_card == 'Y') { // We only need to worry if it is a yes.
		total_price *= 0.9; // 10% off is same as multiplying by 0.9.
	}

	cout << "Price after discounts: " << total_price << endl;

	total_price *= ((tax_rate / 100) + 1); // Add tax to total price, for example: 8.25/100 + 1 = 1.0825, which we multiply total price by.

	cout << "Total price: " << total_price << endl;

	// End.
	return 0;
}