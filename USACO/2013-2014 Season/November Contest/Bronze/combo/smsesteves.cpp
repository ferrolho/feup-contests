/*
ID: smsesteves
PROG: combo
LANG: C++
*/

#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main()
{
    ifstream fin("combo.in");
	ofstream fout("combo.out");

    int n;
	fin >> n;

    int jonhkey[3];
    int masterkey[3];

    map<int,int>  resultados;



    fin>>jonhkey[0]>>jonhkey[1]>>jonhkey[2];
    fin>>masterkey[0]>>masterkey[1]>>masterkey[2];



    for(int i=0;i<5;i++)
    {
        int newvalue=jonhkey[0];

        switch(i)
        {
            case 0:
                    break;
            case 1:
                    if(jonhkey[0]==n)
                    {
                        newvalue=1;
                    }
                    else
                    {
                        newvalue=jonhkey[0]+1;
                    }
                    break;
            case 2:

                    if(jonhkey[0]==1)
                    {
                        newvalue=n;
                    }
                    else
                    {
                        newvalue=jonhkey[0]-1;
                    }
                    break;
            case 3:

                    if(jonhkey[0]==n-1)
                    {
                        newvalue=1;
                    }else if(jonhkey[0]==n)
                    {
                        newvalue=2;
                    }else
                    {
                        newvalue=jonhkey[0]+2;
                    }
                    break;

            case 4:
                    if(jonhkey[0]==1)
                    {
                        newvalue=n-1;
                    }else if(jonhkey[0]==2)
                    {
                        newvalue=n;
                    }else
                    {
                        newvalue=jonhkey[0]-2;
                    }
                    break;
        }
        for(int j=0;j<5;j++)
        {
                int newvalue2=jonhkey[1];
                switch(j)
                {
                case 0:
                        break;
                case 1:
                        if(jonhkey[1]==n)
                        {
                            newvalue2=1;
                        }
                        else
                        {
                            newvalue2=jonhkey[1]+1;
                        }
                        break;
                case 2:

                        if(jonhkey[1]==1)
                        {
                            newvalue2=n;
                        }
                        else
                        {
                            newvalue2=jonhkey[1]-1;
                        }
                        break;
                case 3:

                        if(jonhkey[1]==n-1)
                        {
                            newvalue2=1;
                        }else if(jonhkey[1]==n)
                        {
                            newvalue2=2;
                        }else
                        {
                            newvalue2=jonhkey[1]+2;
                        }
                        break;

                    case 4:
                        if(jonhkey[1]==1)
                        {
                            newvalue2=n-2;
                        }else if(jonhkey[1]==2)
                        {
                            newvalue2=n;
                        }else
                        {
                            newvalue2=jonhkey[1]-2;
                        }
                        break;
            }
            for(int k=0;k<5;k++)
            {
                int newvalue3=jonhkey[2];
                switch(k)
                {
                        case 0:
                                break;
                        case 1:
                                if(jonhkey[2]==n)
                                {
                                    newvalue3=1;
                                }
                                else
                                {
                                    newvalue3=jonhkey[2]+1;
                                }
                                break;
                        case 2:

                                if(jonhkey[2]==1)
                                {
                                    newvalue3=n;
                                }
                                else
                                {
                                    newvalue3=jonhkey[2]-1;
                                }
                                break;
                        case 3:

                                if(jonhkey[2]==n-1)
                                {
                                    newvalue3=1;
                                }else if(jonhkey[2]==n)
                                {
                                    newvalue3=2;
                                }else
                                {
                                    newvalue3=jonhkey[2]+2;
                                }
                                break;

                            case 4:
                                if(jonhkey[2]==1)
                                {
                                    newvalue3=n-2;
                                }else if(jonhkey[2]==2)
                                {
                                    newvalue3=n;
                                }else
                                {
                                    newvalue3=jonhkey[2]-2;
                                }
                                break;
                        }

                        resultados.insert(pair<int,int> (newvalue*10000+newvalue2*100+newvalue3,1));
            }
        }
    }
        for(int i=0;i<5;i++)
    {
        int newvalue=masterkey[0];

        switch(i)
        {
            case 0:
                    break;
            case 1:
                    if(masterkey[0]==n)
                    {
                        newvalue=1;
                    }
                    else
                    {
                        newvalue=masterkey[0]+1;
                    }
                    break;
            case 2:

                    if(masterkey[0]==1)
                    {
                        newvalue=n;
                    }
                    else
                    {
                        newvalue=masterkey[0]-1;
                    }
                    break;
            case 3:

                    if(masterkey[0]==n-1)
                    {
                        newvalue=1;
                    }else if(masterkey[0]==n)
                    {
                        newvalue=2;
                    }else
                    {
                        newvalue=masterkey[0]+2;
                    }
                    break;

            case 4:
                    if(masterkey[0]==1)
                    {
                        newvalue=n-1;
                    }else if(masterkey[0]==2)
                    {
                        newvalue=n;
                    }else
                    {
                        newvalue=masterkey[0]-2;
                    }
                    break;
        }
        for(int j=0;j<5;j++)
        {
                int newvalue2=masterkey[1];
                switch(j)
                {
                case 0:
                        break;
                case 1:
                        if(masterkey[1]==n)
                        {
                            newvalue2=1;
                        }
                        else
                        {
                            newvalue2=masterkey[1]+1;
                        }
                        break;
                case 2:

                        if(masterkey[1]==1)
                        {
                            newvalue2=n;
                        }
                        else
                        {
                            newvalue2=masterkey[1]-1;
                        }
                        break;
                case 3:

                        if(masterkey[1]==n-1)
                        {
                            newvalue2=1;
                        }else if(masterkey[1]==n)
                        {
                            newvalue2=2;
                        }else
                        {
                            newvalue2=masterkey[1]+2;
                        }
                        break;

                    case 4:
                        if(masterkey[1]==1)
                        {
                            newvalue2=n-2;
                        }else if(masterkey[1]==2)
                        {
                            newvalue2=n;
                        }else
                        {
                            newvalue2=masterkey[1]-2;
                        }
                        break;
            }
            for(int k=0;k<5;k++)
            {
                int newvalue3=masterkey[2];
                switch(k)
                {
                        case 0:
                                break;
                        case 1:
                                if(masterkey[2]==n)
                                {
                                    newvalue3=1;
                                }
                                else
                                {
                                    newvalue3=masterkey[2]+1;
                                }
                                break;
                        case 2:

                                if(masterkey[2]==1)
                                {
                                    newvalue3=n;
                                }
                                else
                                {
                                    newvalue3=masterkey[2]-1;
                                }
                                break;
                        case 3:

                                if(masterkey[2]==n-1)
                                {
                                    newvalue3=1;
                                }else if(masterkey[2]==n)
                                {
                                    newvalue3=2;
                                }else
                                {
                                    newvalue3=masterkey[2]+2;
                                }
                                break;

                            case 4:
                                if(masterkey[2]==1)
                                {
                                    newvalue3=n-2;
                                }else if(masterkey[2]==2)
                                {
                                    newvalue3=n;
                                }else
                                {
                                    newvalue3=masterkey[2]-2;
                                }
                                break;
                        }

                        resultados.insert(pair<int,int> (newvalue*10000+newvalue2*100+newvalue3,1));
            }
        }
    }
    fout<<resultados.size()<<endl;
    fin.close();
    fout.close();
    return 0;
}


