#include <bits/stdc++.h>
#define REP(i,n)  for(int i=0;i<(int)(n);++i)
#define FOR(i,b,n)  for(int i=b;i<(n);++i)
#define ALL(c) (c).begin(),(c).end()
#define SS size()
#define CLR(a,v) memset((a),(v), sizeof a)
#define PB push_back
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

int n;  //nodów w grafie
vvi ch; //sąsiedzi każdego noda
vi w;   //waga każdego noda
vi pod;  //waga nodów pod danym

/**
 * Problem: 
 *  Dany jest graf (drzewo). Każdy z nodów ma "wagę". Dla każdego noda
 * obliczyć wagę wszystkich nodów pod nim, zakładając, że "czubkiem" dzewa jest
 * node "0". 
 * 
 * Przykład: 
 *          0
 *        /  \
 *       1   2
 *       |
 *       3
 * Wagi: w[0]=1, w[1]=5, w[2] = 3; w[3] = 1.
 * 
 * Rozwiązanie: pod[3]=0, pod[2]=0, pod[1]=1, pod[0] = (5 + 3 + 1) = 9
 * 
 * 
 * todo: 
 * - dopisać log wchodzenia i wychodzenia z nodów
 * - dla każdego noda podać jego "głębokość" względem "0"
 * - rozpatrzyć "urywający się" graf dla wagi pod >=M (np 5)
 */

vector<bool> vis;   //już odwiedzone nody
int oblicz_wage(int rt) {
    vis[rt] = true;
    int suma_wag = 0; 
    for(int c : ch[rt]) {
        if (!vis[c]) {
            suma_wag += oblicz_wage(c);
        }
    }
    pod[rt] = suma_wag;
    return w[rt] + suma_wag;
}

int main()
{
    //dane grafu
    int n = 9; 
    vector<pii> g = {{0,1},{1,2},{1,3},{0,4},{4,5},{5,6},{5,7},{4,8}};
    w = {1,1,1,1,1,1,1,1,1};

    //standardowe przygotowanie grafu:    
    ch = vvi(n, vi());  //pusta tablica sąsiadów
    vis = vector<bool>(n);    
    pod = vi(n);
    
    for(pii p : g) {
        ch[p.ST].PB(p.ND);
        ch[p.ND].PB(p.ST);
    }
    
    oblicz_wage(0); //startujemy przeszukiwanie grafu
    
    REP(i,n) {
        cout << "waga pod [" << i << "] : " << pod[i] << endl;
    }
}



