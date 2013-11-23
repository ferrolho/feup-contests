#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <conio.h>
#include <sstream>
#include <cmath>
#include <conio.h>

using namespace std;

int N;

bool pertoDeCombinacao(int CombChave[], int CombMinha[])
{
  if (abs(CombChave[0]-CombMinha[0]) > 2 && N-abs(CombChave[0]-CombMinha[0]) > 2)
    return false;

  if (abs(CombChave[1]-CombMinha[1]) > 2 && N-abs(CombChave[1]-CombMinha[1]) > 2)
    return false;

  if (abs(CombChave[2]-CombMinha[2]) > 2 && N-abs(CombChave[2]-CombMinha[2]) > 2)
    return false;

  return true;
}

int main()
{
  //ifstream in("combo.in"), out("combo.out");
  int JohnC[3], MasterC[3];

  cin >> N >> JohnC[0] >> JohnC[1] >> JohnC[2] >> MasterC[0] >> MasterC[1] >> MasterC[2];

  int total=0;

  for (int i=1; i <= N; i++)
    for (int j=1; j <= N; j++)
      for (int k=1; k <= N; k++)
      {
        int combMinha[] = {i,j,k};

        if (pertoDeCombinacao(JohnC,combMinha) || pertoDeCombinacao(MasterC,combMinha))
          total++;
      }


  cout << total;
}
