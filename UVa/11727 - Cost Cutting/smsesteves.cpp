#include <iostream>

using namespace std;

int main()
{
    int n,n1,n2,n3;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>n1>>n2>>n3;
        if(n1>n2)
        {
            if(n1>n3)
            {
                if(n2>n3)
                {
                    cout<<"Case "<<i+1<<": "<<n2<<endl;
                }
                else
                {
                    cout<<"Case "<<i+1<<": "<<n3<<endl;
                }
            }
            else
            {
                cout<<"Case "<<i+1<<": "<<n1<<endl;
            }
        }
        else if(n2>n3)
        {
            if(n2>n3)
            {
                if(n1>n3)
                {
                    cout<<"Case "<<i+1<<": "<<n1<<endl;
                }
                else
                {
                    cout<<"Case "<<i+1<<": "<<n3<<endl;
                }
            }

        }
        else
        {
            if(n2>n1)
            {
                cout<<"Case "<<i+1<<": "<<n2<<endl;
            }
            else
            {
                cout<<"Case "<<i+1<<": "<<n1<<endl;
            }
        }
    }

    return 0;
}
