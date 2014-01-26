/*
ID: migueel1
PROG: namenum
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

set<string> dictionary;
set<string> namesFound;

void nameSearch(string cowCode, string name)
{
  if (cowCode.empty())
  {
    if(dictionary.find(name) != dictionary.end())
      namesFound.insert(name);
    return;
  }

  string name1=name, name2=name, name3=name; // possible names
  char code = cowCode[0]; cowCode.erase(cowCode.begin()); // next code

  switch(code)
  {
  case '2':
    name1.push_back('A');
    nameSearch(cowCode,name1);
    name2.push_back('B');
    nameSearch(cowCode,name2);
    name3.push_back('C');
    nameSearch(cowCode,name3);
    break;

  case '3':
    name1.push_back('D');
    nameSearch(cowCode,name1);
    name2.push_back('E');
    nameSearch(cowCode,name2);
    name3.push_back('F');
    nameSearch(cowCode,name3);
    break;

  case '4':
    name1.push_back('G');
    nameSearch(cowCode,name1);
    name2.push_back('H');
    nameSearch(cowCode,name2);
    name3.push_back('I');
    nameSearch(cowCode,name3);
    break;

  case '5':
    name1.push_back('J');
    nameSearch(cowCode,name1);
    name2.push_back('K');
    nameSearch(cowCode,name2);
    name3.push_back('L');
    nameSearch(cowCode,name3);
    break;

  case '6':
    name1.push_back('M');
    nameSearch(cowCode,name1);
    name2.push_back('N');
    nameSearch(cowCode,name2);
    name3.push_back('O');
    nameSearch(cowCode,name3);
    break;

  case '7':
    name1.push_back('P');
    nameSearch(cowCode,name1);
    name2.push_back('R');
    nameSearch(cowCode,name2);
    name3.push_back('S');
    nameSearch(cowCode,name3);
    break;

  case '8':
    name1.push_back('T');
    nameSearch(cowCode,name1);
    name2.push_back('U');
    nameSearch(cowCode,name2);
    name3.push_back('V');
    nameSearch(cowCode,name3);
    break;

  case '9':
    name1.push_back('W');
    nameSearch(cowCode,name1);
    name2.push_back('X');
    nameSearch(cowCode,name2);
    name3.push_back('Y');
    nameSearch(cowCode,name3);
    break;
  }
}

int main()
{
  // LOAD DICTIONARY ************
  ifstream dict("dict.txt");
  string lineTxt;

  while(getline(dict,lineTxt))
    dictionary.insert(lineTxt);

  cout << "saiu\n";
  getchar();

  dict.close();

  // LOAD INPUT *************
  string cowCode;

  ifstream input("namenum.in");
  getline(input,cowCode);
  input.close();

  nameSearch(cowCode,""); // search the name

  // SAVE OUTPUT
  ofstream output("namenum.out");

  if (namesFound.empty())
    output << "NONE" << endl;
  else
  {
    set<string>::const_iterator itr = namesFound.begin();

    while(itr != namesFound.end())
    {
      output << (*itr) << endl;
      itr++;
    }
  }

  return 0;
}
