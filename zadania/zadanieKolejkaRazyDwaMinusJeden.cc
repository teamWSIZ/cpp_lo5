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
* Zadanie: startujemy z liczby "st", i chcemy osiagnac liczbe "end";
* w kazdym kroku z liczby "x" mozemy przejsc do "2*x" albo do "x-1". 
* Prosze wyliczyc po jakiej najmniejszej liczbie krokow, startujc z "st" mozna 
* osiagnac "end". 
* 
* Przyklad: st=4 end=7 (odp=2); st=15 end=20 (odp=6)
*/

int main() {
    int st = 15, end = 20;
    queue<int> Q;
    int dyst[10000] = {0};
    Q.push(st);
    dyst[st] = 1;
    while (Q.size()>0) {
        int at = Q.front(); Q.pop();
        dyst[at] =1;
        cout << "sprawdzam wezel:" << at << endl;
//        if (at==end) {
        //todo: tu trzeba zrobic cos, co odpowiednio bedzie zwracalo dystans od "st"
//            cout << "best=" << dist[at] << endl;
//            break;
//        }
        int nowy1 = at * 2;
        int nowy2 = at -1;
        //tutaj trzeba odpowiednio zapisac nowy dystans do dyst[nowy1/2]
        if (nowy1<=100 && dyst[nowy1]==0) Q.push(nowy1);
        if (nowy2>=0 && dyst[nowy2]==0) Q.push(nowy2);
    }

}
