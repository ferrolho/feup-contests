/*
ID: migueel1
PROG: beads
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int countColar(string colar, int pos, int direction, int counts_left)
{
  int count_1 = 0, count_2 = 0; // count in mode 1, count in mode 2
  int count_mode; // 1-> count as blue, 2-> count as red, 3-> count both (because we found w first)

  int counts_left_in_mode = counts_left;

  // pos is the right extreme of the "cut", put the pos in the right position ready to count:
  if (!direction)
  {
    pos--;

    if (pos == -1)
      pos = colar.size() - 1;
  }

  if (counts_left) // if we have counts to count
  {

    //save position
    int original_pos = pos;

    if (colar[pos] == 'b')
      count_mode = 1;
    else if (colar[pos] == 'r')
      count_mode = 2;
    else
      count_mode = 3;

    if (count_mode == 1 || count_mode == 3) // if we're considering blue ones
    {
      do
      {
        if (colar[pos] == 'b' || colar[pos] == 'w')
        {
          count_1++;
          counts_left_in_mode--;

          if (direction)
            pos++;
          else
            pos--;
        }
        else
          break;

        // AJUSTE DOS EXTREMOS
        if (pos == (int) colar.size())
          pos = 0;
        else if (pos == -1)
          pos = colar.size() - 1;

        if (!counts_left_in_mode) // if we looked at the entire string
          break;

      } while(true);
    }

    counts_left_in_mode = counts_left; // refill variable
    pos = original_pos;

    if (count_mode == 2 || count_mode == 3) // if we're considering red ones
    {
      do
      {
        //printf("estou a com a direcao %d, e a pos %d\n",direction,pos);
        //getchar();

        if (colar[pos] == 'r' || colar[pos] == 'w')
        {
          count_2++;
          counts_left_in_mode--;

          if (direction)
            pos++;
          else
            pos--;
        }
        else
          break;

        // AJUSTE DOS EXTREMOS
        if (pos == (int) colar.size())
          pos = 0;
        else if (pos == -1)
          pos = colar.size() - 1;

        if (!counts_left_in_mode) // if we looked at the entire string
          break;

      } while(true);
    }
  }

  return max(count_1, count_2);
}

int main()
{
  string colar;
  int lixo;

  //cin >> lixo;
  //cin >> colar;
  //cout << "a string eh " << colar << endl;

  ifstream input("beads.in");
  input >> lixo;
  input >> colar;

  input.close();

  int max_contas=0;

  for (unsigned int i=0; i < colar.size(); i++)
  {
    int contas_dir = countColar(colar,i,1,colar.size());
    int contas_esq = countColar(colar,i,0,colar.size() - contas_dir);

    if ((contas_dir + contas_esq) > max_contas)
      max_contas = contas_dir + contas_esq;

    //printf("calculou estas contas: %d\n", contas_dir + contas_esq);
  }

  //printf("Consegui %d contas!!!\n",max_contas);

  ofstream output("beads.out");
  output << max_contas << endl;

  return 0;
}
