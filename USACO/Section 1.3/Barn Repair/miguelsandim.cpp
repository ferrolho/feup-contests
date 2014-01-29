/*
ID: migueel1
PROG: barn1
LANG: C++
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

struct Stall
{
  unsigned int number;
  unsigned int free_area; // free area in the back of the stall that is between 2 stalls

  bool operator<(const Stall &a) const
  { return free_area > a.free_area; }
};

bool compareNumber(const Stall &a1, const Stall &a2)
{
  return a1.number < a2.number;
}

vector<Stall> barn; unsigned int M,S,C,covered_stalls;

int main()
{
  // receive input
  ifstream input("barn1.in");
  input >> M >> S >> C;

  for(unsigned int i=0; i < C; i++)
  {
    Stall s1; input >> s1.number;

    barn.push_back(s1);
  }
  input.close();

  sort(barn.begin(),barn.end(),compareNumber);

  for(unsigned int i=0; i < C; i++)
  {
    if (!i)
      barn[i].free_area = 0;
    else
      barn[i].free_area = barn[i].number - barn[i-1].number -1;
  }

  covered_stalls = S - (barn[0].number - 1) - (S - barn[barn.size() - 1].number);

  sort(barn.begin(),barn.end()); // sorted by areas covered between stalls used

  for(unsigned int i=2; i <= M; i++)
  {
    if (i-2 >= barn.size())
      break;
    if (barn[i-2].free_area == 0)
      break;

    covered_stalls -= barn[i-2].free_area;
  }

  // SAVE OUTPUT
  ofstream output("barn1.out");
  output << covered_stalls << endl;
  output.close();

  return 0;
}