#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

struct Registo
{
  string matricula;
  vector <unsigned int> velocidades;
  bool operator<(const Registo &r) const
  {
    unsigned int i=0;

    while (i < velocidades.size() && i < r.velocidades.size())
    {
      if (velocidades[i] > r.velocidades[i])
        return true;
      else if (velocidades[i] < r.velocidades[i])
        return false;
      else
        i++;
    }

    return velocidades.size() > r.velocidades.size();
  }
};

typedef map<string,vector<unsigned int> >::iterator map_it;
typedef set<Registo>::iterator setreg_it;

bool decrescente(unsigned int i, unsigned int k)
{
  return i>k;
}

int main()
{
  string data_string;
  unsigned int velocidade;

  map<string,vector<unsigned int> > registos;

  while(cin >> data_string >> velocidade)
    registos[data_string].push_back(velocidade);

  set <Registo> registos_set;

  // ordenar os vectores das velocidades de cada matricula
  for (map_it itr = registos.begin(); itr != registos.end(); itr++)
  {
    sort(itr->second.begin(),itr->second.end(),decrescente);
    Registo reg; reg.matricula = itr->first; reg.velocidades = itr->second; registos_set.insert(reg);
  }

  // imprimir vector de registos
  for (setreg_it itr = registos_set.begin(); itr != registos_set.end(); itr++)
  {
    cout << itr->matricula;

    for (size_t k=0; k < itr->velocidades.size(); k++)
    {
      cout << " " << itr->velocidades[k];
    }

    if (itr != --registos_set.end())
      cout << endl;
  }
}
