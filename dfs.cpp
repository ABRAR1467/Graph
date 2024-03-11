#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define pii             pair<int,int>
#define mp              make_pair
#define ll              long long
#define pb              push_back


int level[100005];
vector<int>ans;
vector<int>grp[100005];
int visited[100005];

void dfs(int src)
{
    visited[src] = 1;
    ans.push_back(src);
    for(int i=0;i<grp[src].size();i++)
    {
        int x = grp[src][i];
        if(!visited[x])
        {
            dfs(x);
        }
    }
}
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        grp[x].push_back(y);
        grp[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
/*
6 5
1 2
1 3
2 4
3 5
3 6
*/

