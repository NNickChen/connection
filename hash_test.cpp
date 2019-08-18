#include<iostream>
#include <queue>
using namespace std;

string graph[1000][100][100];
string name[1000][100];

static int sosu_table[26] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};

int calc_hash(string s)
{
    int hash=0;
    for(int i =0; i < s.size();i++)
    {
        if(s[i]>='a'&&s[i]<='z')
         hash += sosu_table[s[i] - 'a'];
        else if(s[i]>='A'&&s[i]<='z')
         hash += sosu_table[s[i] - 'A'];
	else hash+=sosu_table[(s[i]&0xff)%26];

    }
    return hash;
}

queue <string> Q;

int main()
{
    while(1)
    {
        string name1;
        cin>>name1;
        if(name1[0]=='0') break;
        int hash=calc_hash(name1);
        // cout<<hash<<endl;
        int i;
        for(i=0;i<100&&name[hash][i].size()>0;i++);
        name[hash][i]=name1;
        int friends;
        cin>>friends;
        for(int x=0;x<friends;x++)
        {
            string friendd;
            cin>>friendd;
            int j;
            for(j=0;j<100&&graph[hash][i][j].size()>0;j++);
            graph[hash][i][j]=friendd;
        }
    }
    while(1)
    {
    	string name1;
    	cin>>name1;
    	if(name1[0]=='0') break;
    	int hash=calc_hash(name1);
    	int i;
    	for(i=0;i<100&&name[hash][i]!=name1;i++);
    	// cout<<name[hash][i]<<"\n";
    	for(int j=0;j<100;j++)
    	{
    		if(graph[hash][i][j].size()>0)
    		 cout<<graph[hash][i][j]<<" ";
    	}
        cout<<"\n";
    }
    return 0;
}