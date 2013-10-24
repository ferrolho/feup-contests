#include <iostream>
#include <vector>
using namespace std;


char matrix[105][105];
int x, y;



struct Pos{
    int x;
    int y;
};

void limparobots(int posx,int posy,int direction,int inc)
{

    int pos;
    if(direction==1)
    {
        //X

        pos=posx;

        while(pos>=0 && pos<x && matrix[pos][posy]!='#')
        {

            matrix[pos][posy]='.';
            pos+=inc;
        }
    }
    else
    {




        pos=posy;
        while(pos>=0 && pos<y && matrix[posx][pos]!='#')
        {

            matrix[posx][pos]='.';
            pos+=inc;
        }
    }
}


void checkrobotsdirection(int posx,int posy)
{
    //baxo
    int pos=posx;
    int count=0;
    int max=count;
    int i=0;
    while(pos>=0 && pos<y && matrix[pos][posy]!='#')
    {
        if(matrix[pos][posy]=='*')
        {
            count++;
        }
        pos++;
    }
    if(count>max)
    {
        max=count;
    }

    pos=posy;
    count=0;
    while(pos>=0 && pos<x && matrix[posx][pos]!='#')
    {
        if(matrix[posx][pos]=='*')
        {
            count++;
        }
        pos++;
    }
    if(count>max)
    {
        max=count;
        i=1;
    }




    switch(i){
        case 0:
            {

                limparobots(posx,posy,1,1);
                break;
            }

        case 1:
            {
                limparobots(posx,posy,0,1);
                break;
            }
    }



}


int main()
{

    int numbertests;
    int robotsnumber;
    int obsnumber;
    Pos a;
    cin>>numbertests;
    while(true)
    {


    cin>>x>>y;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            matrix[i][j]='.';
        }
    }
    cin>>robotsnumber;
    //cout<<"Robots number: "<<robotsnumber<<endl;
    for(int i=0;i<robotsnumber;i++)
    {

        cin>>a.x>>a.y;
        matrix[--a.x][--a.y]='*';

        //cout<<"Robot : "<<i+1<<" "<<a.x<<":"<<a.y<<endl;
    }
    cin>>obsnumber;
   // cout<<"Obs number: "<<obsnumber<<endl;

    for(int i=0;i<obsnumber;i++)
    {
        cin>>a.x>>a.y;
        matrix[--a.x][--a.y]='#';

       // cout<<"Obs : "<<i+1<<" "<<a.x<<":"<<a.y<<endl;
    }


    int count=0;
    for(int i=0;i<x;i++)
    {
        for(int j=0;j<y;j++)
        {
            if(matrix[i][j]=='*')
            {
                count++;
                matrix[i][j]='.';
                checkrobotsdirection(i,j);
            }
        }
    }


    cout<<count<<endl;
    numbertests--;
    if(numbertests==0)
    {
        break;
    }
    }

    return 0;
}
