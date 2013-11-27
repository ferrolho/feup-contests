/*
ID: migueel1
PROG: friday
LANG: C++
 */

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

typedef unsigned int uint;

int days[7] = {0,0,0,0,0,0,0};

int main()
{
  ifstream in("friday.in"); ofstream out("friday.out");
  int year_final;
  in >> year_final; year_final += 1900-1;
  int day_week = 5; // 0->monday 1->tuesday .... 6-> sunday
  int year=1900, month=1;

  while (year <= year_final)
  {
    days[day_week]++; // this is the 13th

    // advance X days, depending on the month and year
    int days_to_advance;
    if (month == 9 || month == 4 || month == 6 || month == 11)
      days_to_advance = 30;

    else if (month == 2)
    {
      if (year%100 == 0) // if it's a century year
      {
        if (year%400 == 0)
          days_to_advance = 29;
        else days_to_advance = 28;
      }
      else
      {
        if (year%4 == 0)
          days_to_advance = 29;
        else days_to_advance = 28;
      }
    }

    else days_to_advance = 31;

    // advance till the next 13th
    if (month == 12)
    {
      month = 1;
      year++;
    }
    else month++;

    // advance week day
    day_week = day_week + (days_to_advance % 7);
    day_week = day_week % 7;

    //cout << "DIA DA SEMANA: " << day_week << "YEAR: " << year << "YEAR FINAL: " << year_final << endl;
  }

  out << days[5] << " " << days[6] << " " << days[0] << " " <<  days[1] << " " << days[2] << " "
      << days[3] << " " << days[4] << endl;
      
      out.close(); in.close();

  return 0;
}