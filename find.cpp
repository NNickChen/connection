#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

map <string,vector <string> > graph;
map <string,string> job;
map <string,bool> vis;

queue <string> Q;

string bfs(string myname,string object)
{
    Q.push(myname);
    vis[myname]=true;
    while(!Q.empty())
    {
        string name;
        name=Q.front();
        // cout<<name<<" ";
        if (job[name]==object)
        return name;
        Q.pop();
        // cout<<job[name]<<" ";
        for (int i = 0; i < graph[name].size(); ++i)
        {
            string frname=graph[name][i];
            if(!vis[frname])
            {
                vis[frname]=true;
                // cout<<frname<<" ";
                Q.push(frname);
            }
        }
        // cout<<endl;
    }
    return "";
}

int main()
{
	string myname,object;
    cin>>object;
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
    // cout<<myname<<"\n";
    string ans=bfs(myname,object);
    if(ans.empty())
    cout<<"You don't have any connection to a(n) "<<object<<endl;
    else
    cout<<ans<<" is a(n) "<<object<<endl;
    return 0;
}