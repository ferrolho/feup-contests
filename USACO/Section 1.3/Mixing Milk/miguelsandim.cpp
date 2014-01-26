/*
ID: migueel1
PROG: milk
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

struct Seller
{
  unsigned int price, qt;

  bool operator<(const Seller &a) const
  {
    if (price < a.price)
      return true;
    else if (price == a.price)
      return qt > a.qt;
    else
      return false;
  }
};

vector<Seller> sellers;
unsigned int milkRemaining, checkValue;

int main()
{
  checkValue = 0;

  // receive input
  ifstream input("milk.in");
  unsigned int M;

  input >> milkRemaining >> M;
  while(M--)
  {
    Seller s; input >> s.price >> s.qt; sellers.push_back(s);
  }
  input.close();

  sort(sellers.begin(),sellers.end()); // poderia ter sido usado count sort, porque preço <= 1,000

  for(unsigned int i=0; milkRemaining > 0; i++)
  {
    if (sellers[i].qt <= milkRemaining) // se ainda vai sobrar, tira tudo o seller
    {
      milkRemaining -= sellers[i].qt;
      checkValue += (sellers[i].price * sellers[i].qt);
    }

    else // se nao vamos gastar tudo do seller, tiramos só o que precisamos :p
    {
      checkValue += (sellers[i].price * milkRemaining);
      milkRemaining = 0;
    }
  }

  // SAVE OUTPUT
  ofstream output("milk.out");
  output << checkValue << endl;
  output.close();

  return 0;
}
