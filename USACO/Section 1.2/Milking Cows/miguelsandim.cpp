/*
ID: migueel1
PROG: milk2
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

struct OcorrenciaMilk
{
  char type;
  int time;

  bool operator<(const OcorrenciaMilk &oc2) const
  {
    if (time < oc2.time)
      return true;
    else if (time == oc2.time)
      return type > oc2.type;
    else
      return false;
  }
};

int main()
{
  ifstream input("milk2.in");

  vector<OcorrenciaMilk> reg; int N; input >> N;

  while (N--)
  {
    OcorrenciaMilk oc1; oc1.type = 'S'; input >> oc1.time;
    OcorrenciaMilk oc2; oc2.type = 'F'; input >> oc2.time;

    reg.push_back(oc1);
    reg.push_back(oc2);
  }

  input.close();

  //printf("ESTOU COM %u ELEMENTOS\n",reg.size());
  //getchar();

  sort(reg.begin(),reg.end());

  // ************* the longest time without milking + longest with milking :p
  unsigned int no_milk_max = 0, milk_max = 0;
  unsigned int no_milk_start_time = 0, milk_start_time = reg[0].time;

  unsigned int s_n=0, f_n=0;
  bool no_milk_time_flag = false;

  for (unsigned int i=0; i < reg.size(); i++)
  {
    if (reg[i].type == 'S')
      s_n++;
    else f_n++;

    if (no_milk_time_flag) // if it's a end of a "no milk period" / start of "milk period"
    {
      no_milk_time_flag = false;

      milk_start_time = reg[i].time;

      if (reg[i].time - no_milk_start_time > no_milk_max)
        no_milk_max = reg[i].time - no_milk_start_time;
    }

    if (s_n == f_n) // if it's a start of a "no milk period" / end of "milk period"
    {
      no_milk_time_flag = true;
      no_milk_start_time = reg[i].time;

      if (reg[i].time - milk_start_time > milk_max)
        milk_max = reg[i].time - milk_start_time;
    }
  }

  ofstream output("milk2.out");

  output << milk_max << " " << no_milk_max << endl;

  return 0;
}
