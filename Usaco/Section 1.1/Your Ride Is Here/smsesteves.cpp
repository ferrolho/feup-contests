/*
ID: sergiom2
PROG: ride
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{

	int acc=1,acc2=1;

	ifstream fin("ride.in");
	ofstream fout("ride.out");

	string s,s1;

	fin >> s >> s1;

	for(int i=0;i<s.length();i++)
	{
		acc*=(int)(s[i]-'A'+1);
	}

	for(int i=0;i<s1.length();i++)
	{
		acc2*=(int)(s1[i]-'A'+1);
	}

	if(acc%47==acc2%47)
	{
		fout << "GO\n";
	}
	else
	{
		fout << "STAY\n";
	}

	fin.close();
	fout.close();

	return 0;
}