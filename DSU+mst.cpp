#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
#define MAXN 200005
#define INF 1e18
#define sc(i) scanf("%d",&i);
#define pr(i) printf("%d ",i);
using namespace std; 
typedef long long ll;
typedef pair<ll,ll> iPair;
#define _sz(x) (ll)x.size()

vector<int> parent, rank;
vector<Edge> edges;
vector<Edge> result;
int n,cost;

void make_set(int v) {
    parent(v) = v;
    rank[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
    }
}

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

int main(){
	//input edges.
    for (int i = 0; i < n; i++)
        make_set(i);
    sort(edges.begin(), edges.end());
    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }

    //print the mst_weight
    cout<<cost;
}