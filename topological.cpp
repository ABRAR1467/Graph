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
stack<int>st;

void dfs(int src)
{
    visited[src] = true;
    for(int i=0;i<grp[src].size();i++)
    {
        int v = grp[src][i];
        if(!visited[v])
        {
            dfs(v);
        }
    }
    st.push(src);
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
        //grp[v].push_back(u);
    }
    for(int i=0;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i);
        }
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
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
