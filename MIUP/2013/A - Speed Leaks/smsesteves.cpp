#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

class Veiculo
{

public:
    string matricula;
    vector<int> speeds;

    Veiculo(string matricula,vector<int> speeds);

};

Veiculo::Veiculo(string matricula,vector<int>speeds)
{
    this->matricula=matricula;
    this->speeds=speeds;
}

bool Comparaction (const Veiculo &v,const Veiculo &v1)
{
    int l1=v.speeds.size();
    int l2=v1.speeds.size();
    for(int i=0;i<l1;i++)
    {
        if(i>=l2)
        {
            return true;
        }
        if(v.speeds[i]>v1.speeds[i])
        {
            return true;
        }
        else if(v.speeds[i]<v1.speeds[i])
        {
            return false;
        }
    }
    if(l1<l2)
    {
        return false;
    }
    if(v.matricula<v1.matricula)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    string aux;
    int speedaux;
    map<string,vector<int> >::iterator ret;
    map< string, vector<int> > records;
    while(cin>>aux>>speedaux)
    {

        ret=records.find(aux);
        if(ret==records.end())
        {
            vector<int> speeds;
            speeds.push_back(speedaux);
            records.insert(pair<string,vector<int> >(aux,speeds));
        }
        else
        {
            ret->second.push_back(speedaux);
        }
    }
    vector<Veiculo> veiculos;
    int i=0;
    for(ret=records.begin();ret!=records.end();ret++)
    {
        veiculos.push_back(Veiculo(ret->first,ret->second));
        sort(veiculos[i].speeds.rbegin(),veiculos[i].speeds.rend());
        i++;
    }
    sort(veiculos.begin(),veiculos.end(),Comparaction);
    for(int j=0;j<i;j++)
    {
        cout<<veiculos[j].matricula<<" ";
        unsigned int z=0;
        for(z=0;z<veiculos[j].speeds.size()-1;z++)
        {
            cout<<veiculos[j].speeds[z]<<" ";
        }
        cout<<veiculos[j].speeds[z];
        cout<<endl;
    }
    return 0;
}
