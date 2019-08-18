#include<iostrem>
using namespace std;

string graph[1000][100][100];
string name[1000][100];

int calc_hash(string s)
{
    int hash=0;
    for(int i =0; i < s.size();i++)
    {
        if(s[i]>='a'&&s[i]<='z')
         hash += sosu_table[s[i] - 'a'];
        else
         hash += sosu_table[s[i] - 'A'];
    }
    return hash;
}

queue <string> Q;

int main()
{
    while(1)
    {
        string name;
        cin>>name;
        int hash=calc_hash(name);
        int friends;
        cin>>friends;
        for(int i=0;i<friends;i++)
        {
            string friend;
            cin>>friend;
            int i,j;
            for(i=0;i<100&&name[hash][i].size()>0;i++);
            for(j=0;j<100&&graph[hash][i][j].size()>0;j++);
            graph[hash][i][j]=friend;
            name[hash][i]=name;
        }
    }
    return 0;
}