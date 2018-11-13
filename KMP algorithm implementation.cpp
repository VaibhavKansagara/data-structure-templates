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

void computeLPSArray(string pat, int M, int lps[]) 
{ 
    int len = 0; 
    lps[0] = 0;
    int i = 1; 
    while (i < M) { 
        if (pat[i] == pat[len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else 
        {
            if (len != 0) { 
                len = lps[len - 1]; 
            } 
            else 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
} 

vector<int> KMPSearch(string pat,string txt) 
{ 
    vector<int> vt;
    int M = pat.length(); 
    int N = txt.length();
    int lps[M]; 
    computeLPSArray(pat, M, lps); 
    int i = 0;
    int j = 0; 
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
        if (j == M) { 
            vt.pb(i - j); 
            j = lps[j - 1]; 
        }
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0) 
                j = lps[j - 1]; 
            else
                i = i + 1; 
        } 
    } 
    return vt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string txt= "ABABCABABABABCABABABABCABABABABCABAB"; 
    string pat= "ABABCABAB";
    vector<int> vt=KMPSearch(pat,txt);
    for(auto e:vt)
        cout<<e<<" ";
}









