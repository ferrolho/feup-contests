/*
ID: henriqu13
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

const int numDays = 7;
enum { sat, sun, mon, tue, wed, thu, fri };
enum { jan = 31, feb = 28, mar = 31, apr = 30, may = 31, jun = 30, jul = 31, aug = 31, sep = 30, oct = 31, nov = 30, dez = 31 };

bool isLeap(int Year) {
    if (Year%100 == 0) {
        if (Year%400 == 0) {
            return true;
        } else {
            return false;
        }
    } else {
        if (Year%4 == 0) {
            return true;
        } else {
            return false;
        }
    }
}

void incWeekDay(int &day) {
    day++;
    if (day > fri)
        day = sat;
}

void goToNextDay(Date &date, int &weekDay) {
    incWeekDay(weekDay);

    // incrementing day
    date.day++;
    // if on feb
    if (date.month == 2) {
        if (isLeap(date.year) && date.day > 29)
            date.day = 1;
        else if (!isLeap(date.year) && date.day > 28)
            date.day = 1;
    }
    // if month has 30 days
    else if (date.day > 30 && (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11))
        date.day = 1;
    // if month has 31 days
    else if (date.day > 31 && date.month != 2)
        date.day = 1;

    // incrementing month if needed
    if (date.day == 1)
        date.month++;

    // incrementing year
    if (date.month > 12) {
        date.month = 1;
        date.year++;
    }
}

void display(int ar[]) {
    for (int i = 0; i < numDays; i++) {
        cout << ar[i] << " ";
    }
    cout << endl;
}

void printDate(Date &date) {
    cout << date.day << "-" << date.month << "-" << date.year << endl;
}

bool datesAreDifferent(Date &a, Date &b) {
    // if dates are equal, return true
    if (a.day == b.day && a.month == b.month && a.year == b.year)
        return false;
    else
        return true;
}

int main() {
    // reading input
    ifstream fin ("friday.in");
    int N;
    fin >> N;

    // setting start date
    Date start;
    start.day = 1;
    start.month = 1;
    start.year = 1900;

    // setting end date
    Date end;
    end.day = 31;
    end.month = 12;
    end.year = 1900 + N - 1;

    // setting current date
    Date currentDate = start;
    int currentWeekDay = mon;

    // initialing results counter
    int counter[numDays];
    for (int i = 0; i < numDays; i++) {
        counter[i] = 0;
    }
    //display(counter);

    /////////////////////
    // processing data //
    /////////////////////

    while (datesAreDifferent(currentDate, end)) {
        /*
        cout << "Current date: ";
        printDate(currentDate);
        cout << "Current day of the week: " << currentWeekDay << endl;
        */

        if (currentDate.day == 13)
            counter[currentWeekDay]++;

        goToNextDay(currentDate, currentWeekDay);
    }
    //display(counter);

    // outputting data
    ofstream fout ("friday.out");
    for (int i = 0; i < numDays; i++) {
        fout << counter[i];
        if (i < numDays-1)
            fout << " ";
    }
    fout << endl;

    return 0;
}
