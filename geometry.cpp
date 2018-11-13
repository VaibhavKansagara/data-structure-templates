#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define MAXN 100005
#define INF 1e15
#define REP(i,n) for (ll i=0;i<n;i++)
#define sc(i) scanf("%d",&i);
#define pr(i) prllf("%d ",i);
using namespace std; 
typedef long long ll;
typedef pair<ll,ll> iPair;
#define _sz(x) (ll)x.size()
typedef vector<vector<ll> > matrix;
const ll MOD = 1000000007;
const ll alphabet = 256;
#define PI 3.1415926535897932384626

struct point{
    double x,y;
    inline point(double x=0,double y=0):x(x),y(y){}
};

inline point operator+(point x,point y){return point(x.x+y.x,x.y+y.y);}
inline point operator-(point x,point y){return point(x.x-y.x,x.y-y.y);}
inline double dot(point u,point v){return u.x*v.x+u.y*v.y;}
inline double cross(point u,point v){return u.x*v.y-u.y*v.x;}
inline double length(point u){return sqrt(dot(u,u));}
//dist_to_seg is basically shortest distance between a point and a line segment.
inline double dist_to_seg(point a,point u,point v){     
    if (dot(a-u,v-u)<0) return length(a-u);
    if (dot(a-v,u-v)<0) return length(a-v);
    return fabs(cross(u-a,v-a))/length(u-v);
}
