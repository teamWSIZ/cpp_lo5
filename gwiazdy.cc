#include <bits/stdc++.h>
using namespace std;
#define REP(i,n)  for(int i=0;i<(int)(n);++i)
#define FOR(i,b,n)  for(int i=b;i<(n);++i)
#define ALL(c) (c).begin(),(c).end()
#define SS size()
#define CLR(a,v) memset((a),(v), sizeof a)
#define ST first
#define ND second
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int,int> pii;



// Sytuacja: mamy "gwiazdy" czyli pary (x,y)
// trzeba dla każdego zapytania o "x" powiedziec ile jest 
// gwiazd z tym "x" (i analogicznie dla 'y')

typedef vector<int> vi;


int main() {
  //int atX[1000];
  //REP(i,1000) atX[i]=0;
  int ROZ = 1e9; //wielkośc przedziału wspolrzędnych
  //vi atX(ROZ);
  map<int,int> ATX;

  srand(111);
  int x;
  REP(i,1e6) {
    x = rand() % ROZ;
    //atX[x]++;
    ATX[x]++;
  }
  //REP(i,ROZ) {
    //if (atX[i]>0) cout << i << "-->" <<  atX[i] << endl;
  //  if (ATX.count(i)>0) cout << i << "-->" <<  ATX[i] << endl;
  //}
 
  //dla c++11
  for(pair<int,int> p : ATX) {
    // ta mapa ma pary typu {klucz,wartosc}; klucze to int, wartosc to int
    // p.fist to pierwszy element pary, p.second to drugi
    if (p.second < 2) continue; 
    cout << p.first << " --> " << p.second << endl;
  }

  //Zadanie: zbieramy kary z pokemonami; różnych typów kart jest N
  // (np. N=10000). Co tydzień kupujemy 10 kart, każda z nich jest
  // losowego typu. Proszę wypisać, dla każdego tygodnia, ile różnych
  // kart już mamy. Proszę oszacować po ilu tygodniach uzbieramy N/2 różnych
  // kart (czyli np. 500 dla N=1000). 
  //
  // Sprawdzamy to dla srand(111); 

}

