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

int spf[MAXN];

void sieve() 
{ 
    spf[1] = 1; 
    for (int i=2; i<MAXN; i++) 
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2) 
        spf[i] = 2; 
    for (int i=3; i*i<MAXN; i++) 
    {  
        if (spf[i] == i) 
        { 
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j) 
                    spf[j] = i; 
        } 
    } 
}

vector<int> getFactorization(int x) 
{ 
    vector<int> ret; 
    while (x != 1) 
    { 
        ret.pb(spf[x]); 
        x = x / spf[x]; 
    } 
    return ret; 
}

bool isprime(int x)
{
    return spf[x]==x;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    sieve();
    //not unique prime factors.
    vector<int> vt=getFactorization(1000);
    for(auto e:vt)
        cout<<e<<" ";
}









