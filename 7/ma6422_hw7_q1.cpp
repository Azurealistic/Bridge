#include <iostream>
#include <string>

using namespace std;

// Prints the month with an offset for the starting day.
// 1 = Mon, 7 = Sunday. 
int printMonthCalender(int numOfDays, int startingDay) {
	cout << "Mon\tTue\tWed\tThr\tFri\tSat\tSun" << endl;
	// Week 1, empty offset.
	for(int s = 1; s < startingDay; s++) {
		cout << "\t";
	}
	// Week 1, first few days from start till Sunday.
	for(int c = 1; c <= 8 - startingDay; c++) {
		cout << c << "\t";
	}
	// Weeks 2 and onwards.
	int days = 9 - startingDay;
	for(int c = 1; c <= numOfDays && days <= numOfDays; c++, days++) {
		// If it's a new week we check via mod 7 and print a new line.
		if(c % 7 == 1) {
			cout << endl;
		}
		cout << days << "\t";
	}
	int last = (startingDay + numOfDays - 1) % 7;
	return (last == 0) ? 7 : last;
}

// Quick maths!
bool isLeapYear(int year) {
	return (((year % 100 != 0) && (year % 4 == 0)) || (year % 400 == 0));
}

// I'm sorry. I'll come back for you my beloved arrays. One day.
string getMonth(int month) {
	string m = "";
	switch(month) {
		case 1:
			m = "January";
			break;
		case 2:
			m = "February";
			break;
		case 3:
			m = "March";
			break;
		case 4:
			m = "April";
			break;
		case 5:
			m = "May";
			break;
		case 6:
			m = "June";
			break;
		case 7:
			m = "July";
			break;
		case 8:
			m = "August";
			break;
		case 9:
			m = "September";
			break;
		case 10:
			m = "October";
			break;
		case 11:
			m = "November";
			break;
		case 12:
			m = "December";
			break;
	}
	return m;
}

// Another function that should honestly just be an array.
// I pass year to this to make it easier about leap years.
int getDaysInMonth(int month, int year) {
	// Jan, Mar, May, Jul, Aug, Oct, Dec
	if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		return 31;
	} else if(month == 2) {
		if(isLeapYear(year)) {
			return 29;
		} else {
			return 28;
		}
	} else {
		return 30;
	}
}

void printYearCalender(int year, int startingDay) {
	for(int m = 1; m <= 12; m++) {
		cout << getMonth(m) << " " << year << endl;
		startingDay = printMonthCalender(getDaysInMonth(m, year), startingDay) + 1;
		startingDay = (startingDay % 7 == 0) ? 1 : (startingDay % 7);
		cout << endl << endl;
	}
}

int main(int argc, char const *argv[]) {
	int year, day;
	cout << "Please enter a year followed by starting day of the week. (yyyy day):" << endl;
	cout << "Make sure day is between 1 & 7 >: ";
	cin >> year >> day;
	printYearCalender(year, day);
	return 0;
}