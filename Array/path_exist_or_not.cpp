/* Ajay Raj Srivastava */
#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#include<list>
#include<deque>
#define MOD 1e9+7
#define INF 1e16
#define _USE_MATH_DEFINES
#define ll long long
using namespace std;

vector< vector<int> >adj(10);
bool* visited;
void fast()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
}

int main()
{
    int nodes,edges,x,y;
    //freopen("stdin.in","r",stdin);
    //freopen("stdout.out","w",stdout);
    fast();
    cin>>nodes;
    nodes = nodes * nodes;

    visited=new bool[nodes+1];
    adj.resize(nodes+1);
    memset(visited,false,sizeof(visited));
    for(int i=1;i<=edges;i++)
        {cin>>x>>y;
	adj[x].push_back(y);
	adj[y].push_back(x);}

    int s=1;//source node
    //bfs
    queue<int>q;
    q.push(s);
    visited[s]=true;
    cout<<s<<" ";
    while(!q.empty())
    {
	int p=q.front();
        q.pop();
        for(int i=0;i<adj[p].size();i++)
	    {
 	    if(visited[adj[p][i]]==false)
		{q.push(adj[p][i]);
		visited[adj[p][i]]=true;
                cout<<adj[p][i]<<" ";
                }
	    }
    }
    return 0;
}


