/*
ID: migueel1
PROG: palsquare
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

unsigned int base;

string changeBase(unsigned int num) // in base 10
{
  string num_in_base;

  while(num > 0)
  {
    unsigned int mod = num % base;
    char numer_char;

    if (mod >= 10) // if we have to use 'A', 'B', 'C's, etc...
    {
      mod -= 10; numer_char = mod + 'A';
    }
    else
      numer_char = mod + '0';

    num_in_base.insert(num_in_base.begin(),numer_char); // add to the front of the string

    num = (unsigned int) num / base;
  }

  return num_in_base;
}

bool checkPalindromo(string num) // in base 10
{
  for (unsigned int i=0; i < (unsigned int) num.size()/2; i++)
  {
    if (num[i] != num[num.size() - 1 - i])
      return false;
  }

  return true;
}

int main()
{
  // receive input
  ifstream input("palsquare.in");
  input >> base;
  input.close();

  // SAVE OUTPUT
  ofstream output("palsquare.out");

  for(unsigned int i=1; i <= 300; i++)
  {
    unsigned int square = i*i;

    string square_s = changeBase(square);

    if (checkPalindromo(square_s))
    {
      string i_s = changeBase(i);
      output << i_s << ' ' << square_s << endl;
    }
  }

  output.close();

  return 0;
}
