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

ll Log[MAXN];
iPair st[MAXN][50];

void computelog(){
    Log[1] = 0;
    for (ll i = 2; i < MAXN; i++){
        Log[i] = Log[i/2] + 1;
    }
}

void preprocess_sparse_table(iPair arr[],ll N,ll K){
    for (ll i = 0; i < N; i++) 
        st[i][0] = arr[i];
    for (ll j = 1; j <= K; j++) 
    for (ll i = 0; i + (1 << j) <= N; i++) 
        st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    computelog();

    ll n;
    cin>>n;
    iPair arr[MAXN];
    for(ll i=0;i<n;i++){
        cin>>arr[i].F;
        arr[i].S=i;
    }
    preprocess_sparse_table(arr,n,Log[MAXN-1]);
    ll q;
    cin>>q;
    while(q--){
        ll L,R;
        cin>>L>>R;
        ll j = Log[R - L + 1];
        iPair minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
        cout<<minimum.F<<" "<<minimum.S<<endl;
    }
}









