
#include <bits/stdc++.h>
#define REP(i,n)  for(int i=0;i<(int)(n);++i)
#define FOR(i,b,n)  for(int i=b;i<(n);++i)
#define ALL(c) (c).begin(),(c).end()
#define SS size()
#define CLR(a,v) memset((a),(v), sizeof a)
#define ST first
#define ND second
template<typename T, typename U> inline void AMIN(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void AMAX(T &x, U y) { if(x < y) x = y; }
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

int main() {
  ios::sync_with_stdio(0);	
  int n; cin >> n; 
  int k; cin >> k; 
  vl a(n); 
  ll mi = 2e10;
  REP(i,n) {
	cin >> a[i]; 
	mi = min(mi, a[i]); 
  }
  ll res = 0; 
  REP(i,n) {
     ll u = a[i]; 
     if ((u-mi)%k != 0) {cout << -1 << endl; return 0;}
     res += (u-mi)/k;
  }
  cout << res << endl;
  
}
