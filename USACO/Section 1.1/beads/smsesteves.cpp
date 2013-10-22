/*
ID: sergiom2
LANG: C++
TASK: beads
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	int n;
	string aux;
	
	ifstream fin("beads.in");
	
	fin>>n;
	fin>>aux;
	vector<int> resultado(n, 2);

	int pos;

	char temp;

	for(int i=0;i<n;i++) {
		
		int acc=0;

		if(i+1==n)
			pos=0;
		else
			pos=i+1;
		temp=aux[i];

		while(true) {
			if(aux[pos]=='w') {
				resultado[i]++;
			}
			else if(temp=='w') {
				temp=aux[pos];
				resultado[i]++;
			}
			else if(aux[pos]==temp) {
				resultado[i]++;
			}
			else {
				break;
			}

			if(resultado[i]>=n) {
				ofstream fout("beads.out");
				fout<<n<<endl;

				return 0;
			}
			
			pos++;
			acc++;
			if(pos==n) {
				pos=0;
			}
		}

		if(i-1<0)
			temp = aux[n-1];
		else
			temp = aux[i-1];

		pos = i-2;
		if (pos < 0)
			pos = n + pos;

		
		while(true) {
			if(aux[pos]=='w') {
				resultado[i]++;
			}
			else if(temp=='w') {
				temp=aux[pos];
				resultado[i]++; }
			else if(aux[pos]==temp) {
				resultado[i]++;
			}
			else {
				break;
			}


			
			pos--;
			
			if(resultado[i]>=n) {
				ofstream fout("beads.out");
				fout<<n<<endl;

				return 0;
			}


			if(pos<0) {
				pos=n-1;
			}
		}
	}

	int max=-1;
	for(int i=0;i<n;i++)
	{
		//cout<<resultado[i]<<endl;
		if(resultado[i]>max)
		{
			max=resultado[i];
		}
	}

	ofstream fout("beads.out");
	fout<<max<<endl;

	return 0;
}