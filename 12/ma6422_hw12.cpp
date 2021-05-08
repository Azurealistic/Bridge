#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

class Money { // Mostly from the book with minor changes to fix some bad habits..
private:
	long _all_cents; // I prefer underscores to keep stuff easy for myself.

public:
	Money() : _all_cents{0} {}; // Value is $0.00

	Money(long dollars) {  // Value is dollars * 100
		this->_all_cents = dollars * 100; 
	}

	Money(long dollars, int cents) { // Value is dollars * 100 + cents.
		if(dollars * cents < 0) {
        	cout << "Illegal values for dollars and cents.\n";
        	exit(1); // I dislike this but it just makes it easier to exit out of the program.
    	}
		this->_all_cents = dollars * 100 + static_cast<long>(cents);
	}

	Money operator+(const Money& rhs) { // Adding two together.
		Money temp;
		temp._all_cents = this->_all_cents + rhs._all_cents;
		return temp;
	}

	Money operator-(const Money& rhs) { // Subtracting two from each other.
		Money temp;
		temp._all_cents = this->_all_cents - rhs._all_cents;
		return temp;
	}

	Money operator-() { // Overload the negation.
		Money temp;
		temp._all_cents = -(this->_all_cents);
		return temp;
	}

	Money operator+=(const Money& rhs) { // This one isn't in the book but lets us use the += operator as a running tally of deposits etc.
		this->_all_cents += rhs._all_cents;
		return *this;
	}

	bool operator==(const Money& rhs) { // Compare two values for equality
		return (this->_all_cents == rhs._all_cents);
	}

	bool operator<(const Money& rhs) { // Compare two values to see if left is less than right.
		return (this->_all_cents < rhs._all_cents);
	}

	friend istream& operator>>(istream& is, Money& target); 
	friend ostream& operator<<(ostream& os, const Money& target);
};

class Cheque {
private:
	int _id;
	bool _cashed;
	Money _amount;

public:
	Cheque() : _id {0}, _cashed {false} {};

	int get_id() const;
	bool get_cashed() const;
	Money get_amount() const;

	void set_id(const int& id);
	void set_cashed(const bool& cashed);
	void set_amount(const Money& amount); 

	bool operator<(const Cheque& rhs) {
		return (this->_id < rhs._id);
	}

	friend istream& operator>>(istream& is, Cheque& target);
	friend ostream& operator<<(ostream& os, const Cheque& target);
};

int to_digit(char c);

int main(int argc, char const *argv[]) {
	int count = 0;

	Money curr_balance, old_balance; // curr_balance is what the bank says it should be!
	
	vector<Cheque> cheques;

	Money total_deposits, total_cheques_cashed, new_balance, curr_deposit;
	Cheque curr_cheque;

	cout << "Welcome to the Bank!\nPlease enter your current bank balance ($##.##): ";
	cin >> curr_balance;
	cout << "Please enter your old bank balance ($##.##): ";
	cin >> old_balance;
	cout << "Please enter how many deposits you have (#): ";
	cin >> count;
	cout << "Please enter deposits, one per line ($##.##): " << endl;

	while(count) {
		cin >> curr_deposit;
		total_deposits += curr_deposit;
		count -= 1;
	}

	cout << "Please enter how many cheques you have for processing (#): ";
	cin >> count;
	cout << "Please enter cheques, one per line.\nFormat is (# $##.## #).\nWhere first number is id, second is amount, third is a Y/N if cashed or not." << endl;

	while(count) {
		cin >> curr_cheque;
		cheques.push_back(curr_cheque);
		if(curr_cheque.get_cashed()) {
			total_cheques_cashed += curr_cheque.get_amount();
		}
		count -= 1;
	}

	new_balance = old_balance + total_deposits - total_cheques_cashed;

	cout << endl << "Total value of cheques cashed: " << total_cheques_cashed << endl;
	cout << "Total value of all deposits made: " << total_deposits << endl << endl;
	cout << "New balance should be: " << new_balance << endl;
	cout << "Difference from bank balance is: " << curr_balance - new_balance << endl << endl;

	std::sort(cheques.begin(), cheques.end());

	cout << "List of all cashed cheques:\n\nID\tAmount\tStatus" << endl;
	for(int i = 0; i < cheques.size(); i++) {
		if(cheques[i].get_cashed()) {
			cout << cheques[i] << endl;
		}
	}

	cout << endl << "List of all non-cashed cheques:\n\nID\tAmount\tStatus" << endl;
	for(int i = 0; i < cheques.size(); i++) {
		if(!cheques[i].get_cashed()) {
			cout << cheques[i] << endl;
		}
	}

	return 0;
}

istream& operator>>(istream& is, Money& target) {
	char first_char, decimal, digit_one, digit_two;
	long dollars;
	int cents; 
	bool negative = false;

	is >> first_char; // Check to see if we deal with negatives or not.
	if(first_char == '-') {
		negative = true;
		is >> first_char;
	}

	is >> dollars >> decimal >> digit_one >> digit_two;

	if(first_char != '$' || decimal != '.' || !isdigit(digit_one) || !isdigit(digit_two)) {
		cout << "Illegal form of currency input!" << endl;
		exit(1);
	}

	cents = to_digit(digit_one) * 10 + to_digit(digit_two);
	target._all_cents = dollars * 100 + cents;

	if(negative) {
		target._all_cents = -target._all_cents;
	}

	return is;
}

ostream& operator<<(ostream& os, const Money& target) {
	long absolute_cents, dollars, cents;
	absolute_cents = labs(target._all_cents);
	dollars = absolute_cents / 100;
	cents = absolute_cents % 100;

	if(target._all_cents < 0) {
		os << "-"; 
	}

	os << "$" << dollars << ".";

	if(cents < 10) {
		os << "0";
	}

	os << cents;
	return os;
}

int to_digit(char c) {
	return (static_cast<int>(c) - static_cast<int>('0'));
}

int Cheque::get_id() const {
	return this->_id;
}

bool Cheque::get_cashed() const {
	return this->_cashed;
}

Money Cheque::get_amount() const {
	return this->_amount;
}

void Cheque::set_id(const int& id) {
	this->_id = id;
}

void Cheque::set_cashed(const bool& cashed) {
	this->_cashed = cashed;
}

void Cheque::set_amount(const Money& amount) {
	this->_amount = amount;
} 

istream& operator>>(istream& is, Cheque& target) {
	char cashed_status;
	is >> target._id >> target._amount >> cashed_status;
	if(cashed_status == 'Y' || cashed_status == 'y') {
		target.set_cashed(true);
	} else if(cashed_status == 'N' || cashed_status == 'n') {
		target.set_cashed(false);
	} else {
		cout << "Invalid check!" << endl;
		exit(1);
	}
	return is;
}

ostream& operator<<(ostream& os, const Cheque& target) {
	os << target._id << "\t" << target._amount << "\t";
	if(target._cashed) {
		os << "Cashed";
	} else {
		os << "Not Cashed";
	}
	return os;
}