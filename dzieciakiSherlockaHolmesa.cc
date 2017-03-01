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
 * Zadanie:
 * f(n) = suma takich par {x,y}, x<y, gcd(x,y)=1 (gcd = nwd)
 * g(n) = suma po podzielnikach d liczby n z   f(n/d)
 *
 * F1(x) = g(f(x))
 * F2(x) = f(g(f(x)))
 * F3(x) = g(f(g(f(x))))
 * ...
 *
 * Wczytać liczbę "x" i wypisać F_1 do F_100
 * 
 */




int gcd(int x, int y) {return y==0?x:gcd(y,x%y);}

int f(int n) {
  int a = 0;
  FOR(i,1,n+1) {
    int y = n - i;
    if (y<=i) break;
    if (gcd(i,y)==1) ++a;
  }
  return a;
}

int g(int x) {
  set<int> d;
  FOR(i,1,sqrt(x)+1) {
    if (x % i == 0) {d.insert(i); d.insert(x/i);}
  }
  d.insert(x);
  int res = 0;
  for(int u : d) res += f(x/u);
  return res;
}

int main() {
  cout << f(10) << endl;
  //cout << g(13) << endl; 
  int y; cin >> y;

  REP(i,10) {
    cout << "i=" << i << " " << y << endl;
    y = ((i%2==0)?f(y):g(y));
  } 

}
