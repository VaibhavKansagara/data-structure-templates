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

vector<vector<ll> > adj(MAXN);
void shortestPath (ll src,ll dist[])
{
    priority_queue< iPair, vector <iPair> , greater<iPair> > pq;
    pq.push(make_pair(0, src));
    dist[src] = 0;
    while (!pq.empty())
    {
        ll u = pq.top().second;
        pq.pop();
        list< pair<ll, ll> >::iterator i;
        for(auto e:adj[u])
        {
            ll v = e.F;
            ll weight = e.S;
            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
}









