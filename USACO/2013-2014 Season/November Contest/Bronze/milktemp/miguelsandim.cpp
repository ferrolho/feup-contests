/*
ID: migueel1
PROG: milktemp
LANG: C++
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;

typedef unsigned int uint;

struct OcorrenciaDeLeite
{
  char tipo;
  int temp;

  bool operator<(const OcorrenciaDeLeite o2) const
  {
    if (temp < o2.temp)
      return true;
    else if (o2.temp == temp)
    {
      if (tipo > o2.tipo)
        return true;
      else return false;
    }
    return false;
  }
};

int N, X, Y, Z, leiteotimo=0;

int main()
{
  ifstream in("milktemp.in");

  in >> N >> X >> Y >> Z; vector<OcorrenciaDeLeite> ocorrencias;

  int ntemp = N;
  while (ntemp--)
  {
    OcorrenciaDeLeite o1; in >> o1.temp; o1.tipo = 'Y';
    OcorrenciaDeLeite o2; in >> o2.temp; o2.tipo = 'Z'; o2.temp++; // (a vaca produz menos na temperatura a seguir à do Z)
    ocorrencias.push_back(o1); ocorrencias.push_back(o2);
  }

  in.close();

  sort(ocorrencias.begin(),ocorrencias.end()); // ordenar por temperaturas,
  // as Z tem de aparecer primeiro

  int leiteproduzido = N*X; // n vacas a produzir X (too cold)

  for(uint i=0; i < ocorrencias.size(); i++)
  {
    if (ocorrencias[i].tipo == 'Y')
      leiteproduzido += (Y-X);
    else // se for Z, uma vaca deixou de produzir na proxima temperatura porque o intervalo é fechado
      leiteproduzido -= (Y-Z);

    if (leiteproduzido > leiteotimo)
      leiteotimo = leiteproduzido; // actualizar valor optimo de leite
  }

  ofstream out("milktemp.out");
  out << leiteotimo;
  out.close();
}
