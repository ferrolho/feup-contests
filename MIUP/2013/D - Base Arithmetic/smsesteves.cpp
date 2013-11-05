#include <iostream>
#include "stdlib.h"
#include <vector>
using namespace std;

int toInt(char newint)
{
    int num;
    if(newint>='A')
    {
        num=(int)newint-55;
    }
    else
    {
        num=(int)newint-'0';
    }
    return num;
}

int convertminbase(string n1)
{
    int num;
    int max1=-1;
    for(unsigned int i=0;i<n1.size();i++)
    {
        num=toInt(n1[i]);
        if(num>max1)
        {
            max1=num;
        }
    }
    return max1+1;
}

int convertToBase(string num,int base)
{
    int result=0;
    for(unsigned int i=0;i<num.size();i++)
    {
        result=result*base;
        result=result+toInt(num[i]);
    }
    return result;
}

int main()
{
    string n1,n2,n3,n4;
    cin>>n1>>n2>>n3>>n4;
    vector<int> bases;
    int b1=convertminbase(n1);
    int b2=convertminbase(n2);
    int b3=convertminbase(n3);
    int b4=convertminbase(n4);
    bases.push_back(b1);
    bases.push_back(b2);
    bases.push_back(b3);
    bases.push_back(b4);
    int minbase=-1;
    for(int i=0;i<4;i++)
    {
        if(bases[i]>minbase)
        {
            minbase=bases[i];
        }
    }
    if(minbase<2){minbase=2;};
    for(int i=minbase;i<=36;i++)
    {
        int a=convertToBase(n1,i);
        int b=convertToBase(n2,i);
        int c=convertToBase(n3,i);
        int d=convertToBase(n4,i);
        if(a+b==c*d)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}
