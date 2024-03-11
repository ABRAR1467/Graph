#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define pii             pair<int,int>
#define ll              long long
#define pb              push_back
#define fast_in_out     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int INF = 1e9;
vector<pii>grp[100005];
vector<int>dist(100005,INF);

void dijkstra(int src)
{
    priority_queue<pii,vector<pii>,greater<pii>>pq;


    pq.push({0,src});
    dist[src] = 0;

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for(auto i=grp[u].begin();i!=grp[u].end();i++)
        {
            int v = (*i).first;
            int weight = (*i).second;
            if(dist[v]>dist[u]+weight)
            {
                dist[v]=dist[u]+weight;
                pq.push({dist[v],v});
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
        int u,v,w;
        cin>>u>>v>>w;
        grp[u].push_back({v,w});
        grp[v].push_back({u,w});
    }
    dijkstra(0);
    for(int i=0;i<=n;i++)
    {
        //cout<<"Source:  "<<"Distance"<<endl;
        cout<<i<<"  "<<dist[i]<<endl;
    }
    return 0;
}
/*
8 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
*/

