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

/**
 * Zadanie: pionek startuje z pozycji a=0; 
 *   w każdym ruchu rzucamy kostką; wynik rzutu to k.
 *   pionek przechodzi do pozycji "a+k"; jeśli to "6", to kończymy grę, jeśli wychodzi a+k>6, 
 *   to pionek nie kończy gry, tylko odbija się od pola nr 6, tak, że np. 
 *   będąc na 5, z k=3 trafiamy na 4,
 *   będąc na 5, z k=2 trafiamy na 5.
 *
 *  Zadanie: wyliczyć po ilu rzutach kostką (średnio) pionek osiągnie pole 6.
 *
 */

int main() {
 	srand(time(0));
	int MX = 100000000;
	double sum = 0; 
	REP(i,MX) {
		int a = 0, c = 0; 
		while(true) {
    	++c;
			int ko = 1 + (rand() % 6);
      if (a + ko == 6) break;
			a += ko;
		  if (a>6) a = 6 - (a - 6);
    }
    sum += c;
  }
  cout << (sum / MX) << endl;
}
