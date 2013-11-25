#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Player{
public:
    string name;
    int shotratio;
    int height;
    int time;
    int number;
    Player(string name,int shotratio,int height);
    void operator = (const Player &v1)
    {
        name=v1.name;
        shotratio=v1.shotratio;
        height=v1.height;
        time=v1.time;
        number=v1.number;

    }
};




Player::Player(string name,int shotratio,int height)
{
    this->name=name;
    this->shotratio=shotratio;
    this->height=height;
    time=0;
}

bool ComparInput(const Player &p1,const Player &p2)
{
    if(p1.shotratio==p2.shotratio)
    {
        return p1.height>p2.height;
    }
    return p1.shotratio>p2.shotratio;
}

bool ComparTeam(const Player &p1,const Player &p2)
{
   return p1.name<p2.name;
}

bool ComparGameIn(const Player &p1,const Player &p2)
{
   if(p1.time==p2.time)
   {
        return p1.number>p2.number;
   }
   return p1.time>p2.time;
}

bool ComparGameTeam(const Player &p1,const Player &p2)
{
   if(p1.time==p2.time)
   {
        return p1.number<p2.number;
   }
   return p1.time<p2.time;
}


int main()
{
    int numbercases;
    int c;

    vector<Player> input;
    vector<Player> team1;
    vector<Player> team2;


    cin>>numbercases;
    //cout<<"Number cases: "<<numbercases<<endl;

    for(c=0;c<numbercases;c++)
    {
        int n;
        int minutes;
        int numberplayers;

        cin>>n>>minutes>>numberplayers;
        //cout<<"N: "<<n<<endl;
        //cout<<"Minutes: "<<minutes<<endl;;
        //cout<<"NumberPlayers: "<<numberplayers<<endl;


        for(int i=0;i<n;i++)
        {
            string a;
            int b;
            int b1;
            cin>>a>>b>>b1;
            Player aux(a,b,b1);
            input.push_back(aux);
            //cout<<"Player: "<<i+1<<" "<<input[i].name<<" "<<input[i].shotratio<<" "<<input[i].height<<endl;
        }

        sort(input.begin(),input.end(),ComparInput);

        for(int i=0;i<n;i++)
        {


            input[i].number=i+1;
            //cout<<"Player: "<<i+1<<" "<<input[i].name<<" "<<input[i].shotratio<<" "<<input[i].height<<" Number: "<<input[i].number<<endl;
            if(((i+1)%2)==0)
            {
                team2.push_back(input[i]);
            }
            else
            {
                team1.push_back(input[i]);
            }
        }



        vector<Player> ingame1;
        vector<Player> ingame2;

        for(int i=0;i<numberplayers;i++)
        {


            //cout<<"Player 1: "<<i+1<<" "<<team1[i].name<<" "<<team1[i].shotratio<<" "<<team1[i].height<<endl;
            //cout<<"Player 2: "<<i+1<<" "<<team2[i].name<<" "<<team2[i].shotratio<<" "<<team2[i].height<<endl;
            ingame1.push_back(team1[i]);
            ingame2.push_back(team2[i]);
        }
        team1.erase(team1.begin(),team1.begin()+numberplayers);
        team2.erase(team2.begin(),team2.begin()+numberplayers);

        //cout<<"TEAM SIZE 1:"<<team1.size()<<endl;
        //cout<<"TEAM SIZE 2:"<<team2.size()<<endl;

        //cout<<"IN GAME"<<endl;
        if(n/2>numberplayers)
        {
            while(minutes>0)
            {

                //cout<<"EQUIPAS"<<endl;
                for(int i=0;i<numberplayers;i++)
                {
                    ingame1[i].time++;
                    ingame2[i].time++;
                    //cout<<"Player: "<<i+1<<" "<<ingame1[i].name<<" "<<ingame1[i].shotratio<<" "<<ingame1[i].height<<endl;
                   // cout<<"Player: "<<i+1<<" "<<ingame2[i].name<<" "<<ingame2[i].shotratio<<" "<<ingame2[i].height<<endl;

                }

                //cout<<"Antes ordenar"<<endl;
                sort(team1.begin(),team1.end(),ComparGameTeam);
                sort(team2.begin(),team2.end(),ComparGameTeam);
                sort(ingame1.begin(),ingame1.end(),ComparGameIn);
                sort(ingame2.begin(),ingame2.end(),ComparGameIn);

                //cout<<"Antes atribuir"<<endl;
                Player toremove("",0,0);
                Player toadd("",0,0);


                //cout<<"ALTERACOES 1"<<endl;
                toremove=ingame1[0];
                toadd=team1[0];

                //cout<<toremove.name<<" "<<toremove.shotratio<<" "<<toremove.height<<" "<<toremove.time<<endl;
                //cout<<toadd.name<<" "<<toadd.shotratio<<" "<<toadd.height<<" "<<toadd.time<<endl;



                //cout<<"Depois atribuir"<<endl;

                team1[0]=toremove;
                ingame1[0]=toadd;


                //cout<<"ALTERACOES 2"<<endl;
                toremove=ingame2[0];
                toadd=team2[0];
                //cout<<toremove.name<<" "<<toremove.shotratio<<" "<<toremove.height<<" "<<toremove.time<<endl;
                //cout<<toadd.name<<" "<<toadd.shotratio<<" "<<toadd.height<<" "<<toadd.time<<endl;


                team2[0]=toremove;
                ingame2[0]=toadd;

                minutes--;
            }
        }

        vector<Player> res=ingame1;

        for(int k=0;k<numberplayers;k++)
        {
            res.push_back(ingame2[k]);
        }

        //ingame1.assign(ingame2.begin(),ingame2.end());
        sort(res.begin(),res.end(),ComparTeam);
        //sort(ingame2.begin(),ingame2.begin()+numberplayers,ComparTeam);

        cout<<"Case #"<<c+1<<":";

        for(int i=0;i<numberplayers*2;i++)
        {
            cout<<" "<<res[i].name;
        }

        cout<<endl;
        ingame1.clear();
        ingame2.clear();
        input.clear();
        team1.clear();
        team2.clear();

    }
    return 0;
}
