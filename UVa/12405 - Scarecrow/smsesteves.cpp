#include <iostream>

using namespace std;

int main()
{
    int n;
    int c;
    int count;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        count=0;
        cin>>c;
        string s;
        cin>>s;
        for(int j=0;j<c;j++)
        {
            if(s[j]=='.')
            {
                count++;
                j+=2;
            }
        }
        cout<<"Case "<<i+1<<": "<<count<<endl;
    }
    return 0;
}
