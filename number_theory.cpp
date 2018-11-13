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

int fac[MAXN];
ll power(ll x, ll y, ll p)
{
    ll res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

ll modInverse(ll n, ll p)
{
    return power(n, p-2, p);
}

ll nCrModPFermat(ll n, ll r, ll p)
{
   if (r==0)
      return 1;
    return (fac[n]* modInverse(fac[r], p) % p *
            modInverse(fac[n-r], p) % p) % p;
}

vector<int> getDivisors(int n) 
{
    vector<int> vt;
    for (int i=1; i<=sqrt(n); i++) 
    { 
        if (n%i == 0) 
        { 
            if (n/i == i)
                vt.pb(i);
            else{ 
                vt.pb(i);vt.pb(n/i);
            } 
        } 
    } 
    sort(vt.begin(),vt.end());
    return vt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    fac[0] = 1; 
    for (int i=1 ; i<=n; i++) 
        fac[i]=(fac[i-1]*i)%MOD; 

}









