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

/*
 * 1) Dana jest liczba x z [0,40]; podać jej rozkład na sumę dwóch 
 * liczb pierwszych.
 *
 * 2) Dana jest liczba x z [0,120]; sprawdzić czy można ją zapisać
 *  jako sumę pewnych (np. czterech) liczb z podanego zbioru liczb 
 *  pierwszych.
 * 
 * x=55  --> 55 = 2 + 11 + 13 + 29
 * 
 */

int main() {
  vi w = {2,3,5,7,11,13,17,19,23,29,31,37};
  int x = 34; 
  set<int> s;
  for(int i : w) s.insert(i);
  for(int i : w) {
    if (i>x) break; 
    if (s.count(x-i)>0) {
      cout << i << " " << x-i << endl;
      return 0;
    }
  } 
  cout << "NIE" << endl;
}
