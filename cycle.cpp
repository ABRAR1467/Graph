#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define pii             pair<int,int>
#define ll              long long
#define pb              push_back
#define fast_in_out     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define maxN            100005
vector<int>grp[100005];
int visited[100005];
int par[100005];

bool dfs(int src)
{
    visited[src] = true;
    for(int i=0;i<grp[src].size();i++)
    {
        int v = grp[src][i];
        if(!visited[v])
        {
            par[v] = src;
            if(dfs(v)==true)return true;
        }
        else if(v!=par[src])
        {
            return true;
        }
    }
    return false;
}


int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }
    par[0] = -1;
    for(int i=0;i<=n;i++)
    {
        if(!visited[i])
        {
            if(dfs(i))
            {
                cout<<"cycle"<<endl;
                return 0;
            }
        }
    }
    cout<<"No cycle";
    return 0;
}
/*
4 4
0 1
0 2
1 3
1 4

2 3
0 1
1 2
2 0
*/
