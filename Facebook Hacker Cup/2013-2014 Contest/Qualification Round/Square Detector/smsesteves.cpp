#include <iostream>

using namespace std;

int main()
{
    char matrix[21][21];
    int n;
    int numbercases;
    int c=0;
    cin>>numbercases;
    while(c!=numbercases)
    {


        cin>>n;
        int posi=-1;
        int posj=-1;
        int numberblack=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>matrix[i][j];
                if(posi==-1 && matrix[i][j]=='#')
                {
                    posi=i;
                    posj=j;
                }
                if(matrix[i][j]=='#')
                {
                    numberblack++;
                }
            }
        }
    
        int i=posi;
        int j=posj;
        int counti=0;
        int countj=0;
        bool yes=true;
        //Linhas
        for(i=posi;i<n;i++)
        {
            if(matrix[i][posj]=='#')
            {
                counti++;
            }
            else
            {
                break;
            }
        }
        if(counti==0)
        {
            yes=false;
        }
        else
        {   //Colunas
            for(j=posj;j<n;j++)
            {
                if(matrix[posi][j]=='#')
                {
                    countj++;
                }
                else
                {
                    break;
                }
            }
            
            if(countj!=counti || numberblack!=counti*countj)
            {
                yes=false;
            }
            else
            {
                for(int i=posi;i<posi+counti;i++)
                {
                    for(int j=posj;j<posj+countj;j++)
                    {
                        if(matrix[i][j]!='#')
                        {
                            yes=false;
                            break;
                        }
                    }
                }
            }
        }
    
        if(yes==true)
        {
            cout<<"Case #"<<c+1<<": "<<"YES"<<endl;
        }
        else
        {
            cout<<"Case #"<<c+1<<": "<<"NO"<<endl;
        }
        c++;
    }



    return 0;
}
