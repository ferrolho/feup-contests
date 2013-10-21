/*
ID: sergiom2
PROG: friday
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

bool isleapyear(int n)
{
    return (n%4==0 && n%100!=0)|| (n%100==0 && n%400==0);
}


int numberofdays(int n,int year)
{
    switch(n)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;

    case 4:
    case 6:
    case 9:
    case 11:
        return 30;

    case 2:
        if(isleapyear(year))
            return 29;
        else
            return 28;
    }

}


int main()
{

	int n,i,j,c=1;


	ifstream fin("friday.in");
	ofstream fout("friday.out");

	fin >> n;

    cout<<n<<endl;

	vector<int> days(7,0);


    for(i=1900;i<1900+n;i++)
    {
        for(j=1;j<=12;j++)
        {
            cout << "C: " << c << endl;
            c = (c + 12) % 7;
            cout << "C2: " << c << endl;
            days[c]++;
            c = ( c + numberofdays(j,i) - 13 +1) % 7;
            cout<<numberofdays(j,i)<<endl;
        }
    }




    fout<<days[6] <<" ";

	for(i=0;i<5;i++)
	{
		fout<<days[i]<<" ";
	}
	fout<<days[5]<<endl;


	fin.close();
	fout.close();

	return 0;
}
