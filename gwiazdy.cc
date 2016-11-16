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

  int ROZ = 1000; //wielkośc przedziału wspolrzędnych


  vi atX(ROZ);

  srand(111);

  int x;
  REP(i,10) {
    x = rand() % ROZ;
    atX[x]++;
  }

  REP(i,ROZ)
    if (atX[i]>0)
      cout << i << "-->" <<  atX[i] << endl;


}

