//very useful implementation - map is used so you can directly make changes instead of first findding 
// position and then making changes.
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e5+5;
ll n;
ll cur,ans;
map<ll,ll>t;

ll get(ll pos){
    ll cur=0;
    for(;;pos=(pos&(pos+1))-1){
        cur=max(cur,t[pos]);
        if(pos<=0){
            break;
        }
    }
    return cur;
}

void update(ll pos,ll val){
    for(;pos<=1e9;pos=(pos|(pos+1))){
        t[pos]=max(t[pos],val);
    }
}


struct ABH{
    ll a,b,h;
};
ABH a[N];
bool cmp(ABH x,ABH y){
    return x.b>y.b || (x.b==y.b && x.a>y.a);
}


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i].a>>a[i].b>>a[i].h;
    }
    sort(a+1,a+n+1,cmp);
    for(ll i=1;i<=n;i++){
        cur=get(a[i].b-1)+a[i].h;
        ans=max(ans,cur);
        update(a[i].a,cur);
    }
    cout<<ans;
}