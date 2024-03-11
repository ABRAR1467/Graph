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
int indegree[100005];
queue<int>q;
vector<int>topo;

void bfs(int src)
{
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for(int i=0;i<grp[u].size();i++)
        {
            int x = grp[u][i];
            indegree[x]--;
            if(indegree[x]==0)
            {
                q.push(x);
            }
        }
    }
}


int main()
{
    int n,m;
    cin>>n>>m;
    stack<int>st;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        grp[u].push_back(v);
        //grp[v].push_back(u);
    }
    for(int i=0;i<=n;i++)
    {
        for(auto it: grp[i])
        {
            //cout<<it<<" ";
            indegree[it]++;
        }
        //cout<<endl;
    }
    for(int i=0;i<=n;i++)
    {
        cout<<indegree[i]<<" ";
        if(indegree[i]==0)
        {
            q.push(i);
        }
    }
    bfs(0);
    for(int i=0;i<topo.size();i++)
    {
        cout<<topo[i]<<" ";
    }
    cout<<endl;
    return 0;
}
/*
5 6
5 2
5 0
4 0
4 1
2 3
3 1
*/
