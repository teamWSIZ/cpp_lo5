#include <bits/stdc++.h>
using namespace std;

#define REP(i,n)  for(int i=0;i<(int)(n);++i)
#define FOR(i,b,n)  for(int i=b;i<(n);++i)
#define ALL(c) (c).begin(),(c).end()
#define SS size()
#define CLR(a,v) memset((a),(v), sizeof a)
#define ST first
#define ND second
#define PB push_back
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;

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
  queue<int> q;	//kolejka typu FIFO (jak w sklepie)
  q.push(11); 	//wrzucenie do kolejki liczby 11
  q.push(15); 	
  //cout << q.size() << endl;	//sprawdzenie ile elementów w kolejce
  //cout << q.front() << endl;	//podejrzenie pierwszego elementu 
  //q.pop();	//usunięcie pierwszego elementu
  cout << q.size() << endl;

}
