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
vector<int> vis;

/**
 * Przejście przez graf skierowany z wykrywaniem cykli
 */

void go(int rt) {
    cout << "wchodze do " << (rt+1) << endl;
    vis[rt] = 1;
    for(int k : nxt[rt]) {
        if (vis[k]==0) go(k);
        if (vis[k]==1) {
            cout << "znalazłem cykl na linii: " << (rt+1) << "->" << (k+1)
                 << "  !!!!" << endl;
        }
    }
    cout << "wychodze z " << (rt+1) << endl;
    vis[rt] = 2;
}


int main() {
    int n, m; cin >> n >> m;
    nxt = vsi(n,si());
    prv = vsi(n,si());
    vis = vector<int>(n, 0);

    REP(i,m) {
        int u, v; cin >> u >> v; u--, v--;
        nxt[u].insert(v);
        prv[v].insert(u);
    }

    REP(i,n) {
        cout << (i+1) << " -> ";
        for(int k : nxt[i]) cout << (k+1) << ", ";
        cout << endl;
    }
    cout << "---------------\n";

    REP(i,n) {
        if (vis[i]==0) go(i);
    }


}






