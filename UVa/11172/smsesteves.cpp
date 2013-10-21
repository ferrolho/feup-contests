#include <iostream>

using namespace std;

int main()
{
    long long a1,a2;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
    cin>>a1>>a2;
    if(a1>a2)
        cout<<">"<<endl;
    else if(a1<a2)
        cout<<"<"<<endl;
    else
        cout<<"="<<endl;

    }
    return 0;
}
