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
  vector<pii> w1 = {{1, 2}, {3, 4}, {1, 8}};
  vector<pii> w2 = {{1, 2}, {1, 8}, {3, 4}};

  sort(ALL(w1));
  sort(ALL(w2));

  cout <<" takie same? " << (w1==w2) << endl;
  
  //Zadanie 1:
  // Dany jest wektor wynikow konkursu informatycznego, w postaci
  vector<int> wynik = {1,2,1,8,3};
  //zakładamy, że uczestnik "0" otrzymał wynik[0] punktów, uczestnik 1 wynik[1] itd.
  //Proszę wypisać numery uczestników posortowanych w kolejności od tego, który uzyskał
  //najwięcej punktów do tego który uzyskał najmniej.
  
};
