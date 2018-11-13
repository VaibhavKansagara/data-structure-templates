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

vector<vector<int> > adj(MAXN);
int dp[MAXN];

void df2(int v, int p = -1) //ans is the longest path this needs vectorized implentation of graph
{
    int mx1 = 0, mx2 = 0;
    for (int i = 0; i < adj[v].size(); i++)
    {
        int to = adj[v][i];
        if (to == p) continue;
        dfs2(to, v);
        int val = dp[to] + 1;
        mx2 = max(mx2, val);
        if (mx1 < mx2) swap(mx1, mx2);
    }
    dp[v] = mx1;
    ans = max(ans, mx1 + mx2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        
}









