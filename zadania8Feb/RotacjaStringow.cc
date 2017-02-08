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
	// "1234" -> "4123" -> "3412" -> "2341" -> "1234" (rotacje"

	// dany jest napis s="abcdX", oraz r="dXabc", 
	// Sprawdzić czy `r` jest rotacją `s`

	string w = "abcdd";
	int x = w.find("dd", 0);
	cout << x << endl;
	
	string g = w + w + "abra kadabra";
	cout << g << endl;
	cout << g.substr(3) << endl;
	
}
