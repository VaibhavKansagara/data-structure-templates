#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define MAXN 100001
#define INF 1000000000
#define REP(i,n) for (ll i=0;i<n;i++)
#define sc(i) scanf("%d",&i);
#define pr(i) prllf("%d ",i);
using namespace std; 
typedef long long ll;
typedef pair<ll,ll> iPair;
typedef pair<ll,iPair> PAIR;
#define _sz(x) (ll)x.size()
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
const ll alphabet = 256;
#define PI 3.1415926535897932384626

ll n, t[4*MAXN],lazy[4*MAXN];
void build(ll a[], ll v, ll tl, ll tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        ll tm = (tl + tr)/2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = 0;
    }
}

void push(ll v) {
    t[v*2] += lazy[v];
    lazy[v*2] += lazy[v];
    t[v*2+1] += lazy[v];
    lazy[v*2+1] += lazy[v];
    lazy[v] = 0;
}

void update(ll v, ll tl, ll tr, ll l, ll r, ll addend) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] += addend;
        lazy[v] += addend;
    } else {
        push(v);
        ll tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), addend);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, addend);
        t[v] = max(t[v*2], t[v*2+1]);
    }
}

ll query(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r)
        return -INF;
    if (tl == tr)
        return t[v];
    push(v);
    ll tm = (tl + tr) / 2;
    return max(query(v*2, tl, tm, l, min(r, tm)), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++){
        cin>>arr[i];
    }
    build(arr,1,0,n-1);
    ll q;
    cin>>q;
    while(q--){
        ll L,R;
        cin>>L>>R;
        update(1,0,n-1,L,R,100);
        cout<<query(1,0,n-1,L,R);
    }
}









