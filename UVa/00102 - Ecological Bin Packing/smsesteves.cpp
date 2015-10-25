#include <iostream>
#include <algorithm>
#include "stdio.h"
#include <vector>
using namespace std;




int main()
{
    long long a1,a2,a3,b1,b2,b3,c1,c2,c3;
    while(scanf("%lld %lld %lld %lld %lld %lld %lld %lld %lld",&a1,&a2,&a3,&b1,&b2,&b3,&c1,&c2,&c3)==9)
    {
        long long min;
        string res;
        vector<long long> count(6);

        count[0]=b1 + c1 + a3 + c3 + a2 + b2; //BCG
        min=count[0];

        res="BCG";

        count[1]=b1 + c1 + a2 + c2 + a3 + b3; //BGC
        if(count[1]<min)
        {
            min=count[1];

            res="BGC";
        }
        count[2]=b3 + c3 + a1 + c1 + a2 + b2; //CBG
        if(count[2]<min)
        {
            min=count[2];

            res="CBG";
        }
        count[3]=b3 + c3 + a2 + c2 + a1 + b1; //CGB
        if(count[3]<min)
        {
            min=count[3];

            res="CGB";
        }
        count[4]=b2 + c2 + a1 + c1 + a3 + b3; //GBC
        if(count[4]<min)
        {
            min=count[4];

            res="GBC";
        }
        count[5]=b2 + c2 + a3 + c3 + a1 + b1; //GCB
        if(count[5]<min)
        {
            min=count[5];

            res="GCB";
        }
        cout<<res<<" "<<min<<endl;
    }
    return 0;
}
