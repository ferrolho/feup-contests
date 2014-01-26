/*
ID: migueel1
PROG: dualpal
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

unsigned int N, S;

string changeBase(unsigned int num, unsigned int base) // in base 10
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

bool isValidNumber(unsigned int num)
{
  unsigned int num_bases = 0;

  for(unsigned int i=2; i <= 10; i++)
  {
    if(checkPalindromo(changeBase(num,i)))
      num_bases++;

    if (num_bases == 2)
      return true;
  }
  return false;
}

int main()
{
  // receive input
  ifstream input("dualpal.in");
  input >> N >> S;
  input.close();

  // SAVE OUTPUT
  ofstream output("dualpal.out");

  for(unsigned int i=1; N != 0; i++)
  {
    if(isValidNumber(S+i))
    {
      output << S+i << endl; N--;
    }
  }
  output.close();

  return 0;
}
