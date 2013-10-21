/*
ID: sergiom2
PROG: gift1
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main()
{

	int n,n2;

	vector<string> nomes;
	string aux,aux2;
	ifstream fin("gift1.in");
	ofstream fout("gift1.out");

	fin >> n;

	map<string,int> friends;

	for(int i=0;i<n;i++)
	{
		fin>>aux;
		nomes.push_back(aux);
		friends[aux]=0;
	}

	int op=n;
	while(op>0)
	{
		

		fin>>aux;

		fin>>n>>n2;

		
		n=(int)n/n2;

		for(int i=0;i<n2;i++)
		{
			fin>>aux2;
			friends[aux2]+=n;
			friends[aux]-=n;
		}
		
		op--;


	}

	for(int i=0;i<nomes.size();i++)
	{
		fout<< nomes[i] << " "<< friends[nomes[i]]<<"\n";
	}

	fin.close();
	fout.close();

	return 0;
}