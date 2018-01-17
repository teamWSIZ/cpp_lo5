#include <bits/stdc++.h>
using namespace std;
#define REP(i, n)  for(int i=0;i<(int)(n);++i)
#define FOR(i, b, n)  for(int i=b;i<(n);++i)
#define ALL(c) (c).begin(),(c).end()
#define SS size()
#define PB push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef vector<si> vsi;

template<typename T, typename U> static void AMIN(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void AMAX(T &x, U y) { if (x < y) x = y; }

//http://codeforces.com/contest/915/problem/D

vsi nxt, prv;

int main() {
    int n, m; cin >> n >> m;
    nxt = vsi(n,si());
    prv = vsi(n,si());
    REP(i,m) {
        int u, v; cin >> u >> v; u--, v--;
        nxt[u].insert(v);
        prv[v].insert(u);
    }

    REP(i,n) {
        cout << (i+1) << " -> ";
        for(int k : nxt[i]) cout << k << ", ";
    }



}






