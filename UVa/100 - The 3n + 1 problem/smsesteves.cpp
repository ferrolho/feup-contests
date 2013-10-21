#include <iostream>

using namespace std;

int main()
{
    long long  n1,n2;
    while(cin>>n1>>n2)
    {
        bool yes=false;
        if(n1>n2)
        {
            int tmp=n1;
            n1=n2;
            n2=tmp;
            yes=true;
        }
        long long max=-1;
        for(int i=n1;i<=n2;i++)
        {
            long long c=0;
            long long tmp=i;
            while(tmp!=1)
            {
                if(tmp%2==0)
                {
                    tmp=tmp/2;
                }
                else
                {
                    tmp=3*tmp+1;
                }
                c++;
            }
            c++;
            if(c>max)
            {
                max=c;
            }
        }
        if(yes)
        {
            cout<<n2<<" "<<n1<<" "<<max<<endl;
        }
        else
        {
            cout<<n1<<" "<<n2<<" "<<max<<endl;
        }

    }


    return 0;
}
