/*
ID: migueel1
PROG: calfflac
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cctype>

using namespace std;

string s, filtered, pal;
int reg_positions[20000];
int max_pal;

bool validChar(unsigned char ch)
{
  ch = toupper(ch);

  return ch >= 'A' && ch <= 'Z';
}

void filterText()
{
  unsigned int j=0;

  for(unsigned int i=0; i < s.size(); i++)
  {
    if (validChar(s[i]))
    {
      filtered += toupper(s[i]);
      reg_positions[j] = i; // associo a este char na filtered, uma posicao real na "s"
      j++;
    }
  }
}

void nuclearPal(int pos)
{
  int left=pos,right=pos;

  while(left >= 0 && right < (int) filtered.size())
  {
    if (toupper(filtered[left]) != toupper(filtered[right]))
      break;
    else // we have a pal
    {
      left--; right++;
    }
  }

  // so we ended the loop, lets check the last pal ...
  left++;
  int left_in_s = reg_positions[left];
  right--;
  int right_in_s = reg_positions[right];

  string new_pal = s.substr(left_in_s,right_in_s - left_in_s + 1);

  if (right-left+1 > max_pal) // é um pal .. mas vale a pena anotar?!
  {
    pal = new_pal; max_pal = right-left+1;
  }


  if (pos != (int) s.size()) // pal com núcleo duplo..
  {
    int left=pos,right=pos+1;

    while(left >= 0 && right < (int) filtered.size())
    {
      if (toupper(filtered[left]) != toupper(filtered[right]))
        break;
      else // we have a pal
      {
        left--; right++;
      }
    }

    // so we ended the loop, lets check the last pal ...
    left++;
    int left_in_s = reg_positions[left];
    right--;
    int right_in_s = reg_positions[right];

    string new_pal = s.substr(left_in_s,right_in_s - left_in_s + 1);

    if (right-left+1 > max_pal) // é um pal .. mas vale a pena anotar?!
    {
      pal = new_pal; max_pal = right-left+1;
    }

  }
}

int main()
{
  max_pal = 0;
  // receive input
  ifstream input("calfflac.in");
  string lineTxt;

  while(getline(input,lineTxt))
    s += lineTxt + '\n';
  input.close();

  filterText();

  for(int i=0; i < (int) s.size(); i++)
    nuclearPal(i);

  //SAVE OUTPUT
  ofstream output("calfflac.out");

  output << max_pal << endl << pal << endl;

  output.close();

  return 0;
}
