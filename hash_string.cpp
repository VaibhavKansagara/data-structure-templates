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

const ll p = 11;
const ll mod = 1110111110111;   //this is a unique combination which is useful 
ll compute_hash(string const& s) {
    ll hash_value = 0,i=0;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow[i]) % mod;
        i++;
    }
    return hash_value;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    
}









