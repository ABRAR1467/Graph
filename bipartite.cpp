#include<bits/stdc++.h>
using namespace std;

#define ff              first
#define ss              second
#define pii             pair<int,int>
#define ll              long long
#define pb              push_back
#define fast_in_out     ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

vector<bool>visited(100005,false);
vector<ll>grp[100005];
int color[100005];
ll cnt[4];

void dfs(ll src)
{
      visited[src] = true;
      for(ll i=0;i<grp[src].size();i++)
      {
          if(!visited[grp[src][i]])
          {
              color[grp[src][i]] = !color[src];
              dfs(grp[src][i]);
          }
      }
}

int main()
{
    ll n;
    cin>>n;
    for(ll i=0;i<n-1;i++)
    {
        ll u,v;
        cin>>u>>v;
        grp[u].push_back(v);
        grp[v].push_back(u);
    }
    color[1] = 0;
    dfs(1);
    for(ll i=1;i<=n;i++)
    {
        cnt[color[i]]++;
    }
    ll ans = cnt[0]*cnt[1]-(n-1);
    cout<<ans<<endl;
    return 0;
}

