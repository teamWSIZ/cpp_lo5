#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
#define pb(a) push_back((a))
#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define mp make_pair
#define x first
#define y second
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()


//Graf jest dany przez wektory "a", "b" 
// 1) Znaleźć sąsiadów wierzchołka "int c"
// 2) Sprawdzić czy w grafie istnieje droga od "int c" do "int d" 


//          5
//          |
//  0 - 1 - 2 - 3
//      |
//      4

vi near(vi& from, vi& to, int c) {
  vi res;
  int n = from.size();
  for(int i=0; i<n; i++) {
    if (from[i]==c) res.pb(to[i]);
    if (to[i]==c) res.pb(from[i]);
  }
  return res;
}

void print(vi& what) {
  for(int i : what) cout << i << ",";
  cout << endl;
}

int main() {
  ios::sync_with_stdio(0);
  vi a = {0,1,2,1,2}; //skad
  vi b = {1,2,3,4,5};

  int c = 2;   //// rozwiazac zadanie 1

  print(a);
  vi nears = near(a, b, 2);
  print(nears);
  //queue<int> q;
  //q.push(11); 
  //cout << q.size() << endl;
  //cout << q.front() << endl;
  //q.pop();
  //cout << q.size() << endl;

}
