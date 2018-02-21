#include <bits/stdc++.h>
using namespace std;
#define REP(i, n)  for(int i=0;i<(int)(n);++i)
#define FOR(i, b, n)  for(int i=b;i<(n);++i)
#define ALL(c) (c).begin(),(c).end()
#define SS size()
#define PB push_back
#define ST first
#define ND second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> si;
typedef vector<vi> vvi;
typedef pair<int,int> pii; 

template<typename T, typename U> static void AMIN(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void AMAX(T &x, U y) { if (x < y) x = y; }


/**
 * Dany graf nieskierowany, z wagami na krawędziach (np. odległości między miastami). 
 *
 * Znaleźć minimal spanning tree dla tego grafu (algorytm prism).
 * 
 * Uwaga: graf będzie dany jako vector<pair<pii, int>>, gdzie pair<pii,int> opisuje pojedynczą krawędź (drogę), w ten sposób:
 * pair<pii,int> road; 
 * road.first.first   : węzeł startowy
 * road.first.sencod  : węzeł końcowy
 * road.second		  : długość drogi
 */

//https://visualgo.net/en/mst

int main() {
  int n = 9;
  vector<pair<pii,int>> roads = {{{0,1},8}, {{0,2},12}, {{1,2},13}, {{1,3},25}, {{1,4},9}, {{2,3},14}, {{2,6},21}, 
  		{{3,4},20}, {{3,5},8}, {{3,6},12}, {{3,7},12}, {{3,8},16}, {{4,5},19},
  		{{5,7},11}, {{6,8},11}, {{7,8},9}};

  vector<pair<pii,int>> mst; //do znalezienia		

  //dla każdego miasta trzeba znać drogi z niech wychodzące (miasto docelowe i długość)
  // {długość, miasto_docelowe}
  vector<vector<pii>> outgoing(n,vector<pii>());	//n, bo tyle jest miast, outgoing[5] == drogi wychodzące z miasta nr 5
  for(auto r : roads) {
  	outgoing[r.ST.ST].push_back({r.ND, r.ST.ND});
  	outgoing[r.ST.ND].push_back({r.ND, r.ST.ND});
  }

  set<int> t; 	//miasta już w MST
  priority_queue<pii> todo_roads; 	//uwaga: to jest PQ; sortowane po długości drogi

  //warunek startowy:
  t.insert(0);
  for(auto r : outgoing[0]) todo_roads.push(r);

  while(!todo_roads.empty()) {
  	pii edge = todo_roads.top(); todo_roads.pop();
  	int lenght = edge.ST;
  	int target = edge.ND;
  	if (t.count(target)>0) contineue; 
  	mst.push_back({})	///dont have "from" info
  }


}
