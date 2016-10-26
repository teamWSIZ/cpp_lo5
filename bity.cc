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

//Kompilacja: g++ -std=c++11 easy.cc

int main() {
    //vi w = {2,3,5,7};
    //for(int i : w) {
    //  cout << i << endl;
    //}
   bitset<5> b(12);
   cout << b.to_string() << endl;

   vector<int> ww = {2,4,6,8,10};
   for(int u : ww) {
     cout << u << endl;
   }

}
