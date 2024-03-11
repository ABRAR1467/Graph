#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define pii             pair<int,int>
#define mp              make_pair
#define ll              long long
#define pb              push_back
#define fast_in_out     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int level[100005];
int visited[100005];
vector<int>ans;
vector<int>grp[100005];

void bfs(int src)
{
    queue<int>q;
    q.push(src);
    visited[src] = 1;
    level[src] = 0;
    ans.push_back(src);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0;i<grp[u].size();i++)
        {
            int x = grp[u][i];
            if(!visited[x])
            {
                ans.push_back(x);
                q.push(x);
                level[x] = level[u]+1;
                visited[x] = 1;
            }
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
            bfs(i);
        }
    }
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        cout<<level[i]<<" ";
    }
    cout<<endl;

    return 0;
}
/*
7 6
1 2
1 3
2 4
2 7
3 5
3 6
*/

