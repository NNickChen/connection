#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

map <string,vector <string> > graph;
map <string,string> job;
map <string,bool> vis;

queue <string> Q;

void bfv(string myname)
{
    Q.push(myname);
    vis[myname]=true;
    while(!Q.empty())
    {
        string name;
        name=Q.front();
        cout<<name<<" ";
        Q.pop();
        cout<<job[name]<<" ";
        for (int i = 0; i < graph[name].size(); ++i)
        {
            string frname=graph[name][i];
            if(!vis[frname])
            {
                vis[frname]=true;
                cout<<frname<<" ";
                Q.push(frname);
            }
        }
        cout<<endl;
    }
}

int main()
{
	string myname;
	bool isFirstTime=true;
    while(1)
    {
        string name;
        string job1;
        cin>>name;
        if(name[0]=='0') break;
        cin>>job1;
        if(isFirstTime)
        {
        	myname=name;
        	isFirstTime=false;
        }
        job[name]=job1;
        int friends;
        cin>>friends;
        for(int i=0;i<friends;i++)
        {
            string friendd;
            cin>>friendd;
            graph[name].push_back(friendd);
        }
    }
    bfv(myname);
    return 0;
}