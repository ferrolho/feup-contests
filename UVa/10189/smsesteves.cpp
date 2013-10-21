#include <iostream>

using namespace std;

char matrix[102][102];
int final[102][102];
int n1,n2;

void increment(int i,int j,int x,int y)
{
    if(i+x>=0 && i+x<n1 && j+y>=0 && j+y<n2 && final[i+x][j+y]!=-1)
    {
        final[i+x][j+y]++;
    }
    final[i][j]=-1;
}


int main()
{

    int count=0;
    while(cin>>n1>>n2)
    {
        count++;
        if(n1==0 && n2==0)
        {
            return 0;
        }
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                cin>>matrix[i][j];
                final[i][j]=0;
            }
        }

        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                if(matrix[i][j]=='*')
                {
                    increment(i,j,1,0);
                    increment(i,j,1,1);
                    increment(i,j,0,1);
                    increment(i,j,-1,1);
                    increment(i,j,-1,0);
                    increment(i,j,-1,-1);
                    increment(i,j,0,-1);
                    increment(i,j,1,-1);

                }
            }
        }

        cout<<"Field #"<<count<<":"<<endl;
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                if(final[i][j]!=-1)
                    cout<<final[i][j];
                else
                        cout<<"*";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}
