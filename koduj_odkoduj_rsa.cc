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

int n = 1271;

int ppow(int p, int w) {
  int x = 1; 
  while(w) {
    if (w%2) (x = x * p % n);
    p = (p * p) % n;
    w/=2;
  }
  return x;
}

string odkoduj_napis(vi a, int d) {
  string s = "";
  for(int k : a) {
    s += (char)ppow(k, d);
  }
  return s;
}

vi zakoduj_napis(string s, int e) {
  vi res;
  for(char c : s) {
    res.push_back(ppow(c, e));
  }
  return res; 
}



int main() {
  cout << ppow(3,4) << endl;
  int e = 7;
  int d = 343; 

  FOR(i,0,255) {  
   int lit = i;
   int kod = ppow(lit, e) % n;
   //cout << kod << endl;
   int lit2 = ppow(kod, d) % n; 
   cout << lit << " : " << lit2 << endl;
  }
	
  string blah = "";
  cin >> blah; 
  cout << endl;

  vi w = zakoduj_napis(blah, e);
  for(int k : w) cout << k << ", ";


  cout << odkoduj_napis(zakoduj_napis(blah, e), d) << endl;

}
