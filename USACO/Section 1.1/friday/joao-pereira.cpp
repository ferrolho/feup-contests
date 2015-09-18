/*
 ID: pereira1
 PROG: friday
 LANG: C++11
 */

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int howManyDays(int m, int isLeap) {
	// 31 days
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		return 31;
	// 30 days
	else if (m == 4 || m == 6 || m == 9 || m == 11)
		return 30;
	// leap year -> 29 days
	else if (isLeap)
		return 29;
	// February with 28 days
	else
		return 28;
}

int isLeapYear(int year) {
	// leap year ??
	if (year % 4 == 0) {
		// is century year ??
		if (year % 100 == 0) {
			// is leap century year
			if (year % 400 == 0)
				return 1;
			else
				return 0;
		} else
			return 1;
	} else
		return 0;
}

int main() {

	ifstream in("friday.in");
	ofstream out("friday.out");

	int nYears, nDays, leap = 0, currentYear = 1900, currentMonth = 1,
			currentDay = 1, currentWeekDay = 2, days[7] = { 0 };

	in >> nYears;

	in.close();

	while (nYears != 0) {

		leap = isLeapYear(currentYear);

		cout << "year: " << currentYear << " leap: " << leap << endl;

		while (currentMonth < 13) {

			nDays = howManyDays(currentMonth, leap);

			while (currentDay <= nDays) {

				if (currentDay == 13)
					days[currentWeekDay % 7]++;

				currentWeekDay++;
				currentDay++;
			}

			currentDay = 1;
			currentMonth++;
		}

		currentMonth = 1;
		currentYear++;
		nYears--;
	}

	out << days[0];

	for (unsigned int i = 1; i < sizeof(days) / sizeof(int); i++)
		out << " " << days[i];

	out << endl;

	out.close();

	return 0;
}
