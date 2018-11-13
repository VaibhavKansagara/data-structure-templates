#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define MAXN 100001
#define INF 1000000000
#define REP(i,n) for (ll i=0;i<n;i++)
#define sc(i) scanf("%d",&i);
#define pr(i) printf("%d ",i);
using namespace std; 
typedef long long ll;
typedef pair<ll,ll> iPair;
typedef pair<ll,iPair> PAIR;
#define _sz(x) (ll)x.size()
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
const ll alphabet = 256;
#define PI 3.1415926535897932384626

void bfs(ll s,ll level[]) {
    bool vis[V];
    memset(vis,false,sizeof(vis));
    list<ll> q;
    q.push_back(s);
    level[s] = 0 ;
    vis[s] = true;
    ll temp;
    while(!q.empty())
    {
        ll p = q.front();
        q.pop_front();
        for(auto e:adj[p])
        {
            if(!vis[e])
            {
                level[e] = level[p]+1;
                q.push_back(e);
                vis[e] = true;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
}









