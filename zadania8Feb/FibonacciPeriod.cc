#include <bits/stdc++.h>
#define REP(i,n)  for(int i=0;i<(int)(n);++i)
#define FOR(i,b,n)  for(int i=b;i<(n);++i)
#define ALL(c) (c).begin(),(c).end()
#define PB(c) push_back((c))
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
	int a = 0; 
	int b = 1; 
	int M = 1007;
	vi A; 
	A.PB(a);
	REP(i, 10040) {
		cout << a << " "; 
		int t = a + b; 
		a = b;
		b = t % M;
		A.PB(a);
		if (a==0 && b==1) {
			cout << "period=" << i << endl;
			break;
			//a[0] --> equiv --> a[108], okres = 108
		}
	}
	cout << A[108] << endl;
	ll tgt = 100000000000LL;
	cout << "wynik=" << A[tgt%108] << endl;
	
}
