#include <iostream>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string code,uncode;
    for(int i=0;i<n;i++)
    {
        int moves=0;
        cin>>code>>uncode;
        int sizet=code.length();
        int realzero=0,needzero=0;
        int realone=0,needone=0;
        int aux=0;
        if(code==uncode)
        {
            cout<<"Case "<<i+1<<": "<<0<<endl;
            continue;
        }
        else
        {
            //counting ?
            for(int j=0;j<sizet;j++)
            {
                if(code[j]=='0')
                    needzero++;
                else if(code[j]=='1')
                    needone++;
                else
                      aux++;
                if(uncode[j]=='0')
                    realzero++;
                else
                    realone++;
            }
            if(needone>realone)
            {
                cout<<"Case "<<i+1<<": "<<-1<<endl;
                continue;
            }
            if(aux>0)
            {
                //Deleting ?
                for(int j=0;j<sizet;j++)
                {
                    if(code[j]=='?')
                    {
                        moves++;
                        if(uncode[j]=='1' && realone>needone)
                        {
                            needone++;
                            code[j]='1';
                        }
                        else if(uncode[j]== '0' && realzero>needzero)
                        {
                            needzero++;
                            code[j]='0';
                        }
                        else if(realzero>needzero)
                        {
                            needzero++;
                            code[j]='0';
                        }
                        else if(realone>needone)
                        {
                            needone++;
                            code[j]='1';
                        }
                    }
                }



                if(code==uncode)
                {
                    cout<<"Case "<<i+1<<": "<<moves<<endl;
                    continue;
                }
            }

            //SWAPPING
            for(int j=0;j<sizet;j++)
            {
                if(code[j]!=uncode[j])
                {

                    for(int z=j+1;z<sizet;z++)
                    {
                        if(code[j]!=code[z] && uncode[j]!=uncode[z])
                        {
                            //cout<<"Pos j:"<<j<<"Pos z:"<<z<<endl;
                            //ERRO
                            moves++;
                            char tmp=code[j];
                            code[j]=code[z];
                            code[z]=tmp;
                            break;
                        }
                    }
                }
            }
            if(code==uncode)
            {

                cout<<"Case "<<i+1<<": "<<moves<<endl;
                continue;
            }
            else
            {
                //subs
                for(int j=0;j<sizet;j++)
                {
                    if(code[j]=='0' && code[j]!=uncode[j])
                    {
                        moves++;
                        code[j]=='1';
                    }
                }
                cout<<"Case "<<i+1<<": "<<moves<<endl;
                continue;
            }


        }

    }



    return 0;
}
