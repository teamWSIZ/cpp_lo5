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

int main() {
  vector<pii> w1 = {{1, 2}, {3, 4}, {1, 8}};
  vector<pii> w2 = {{1, 2}, {1, 8}, {3, 4}};

  sort(ALL(w1));
  sort(ALL(w2));

  cout <<" takie same? " << (w1==w2) << endl;
  
  //Zadanie 1:
  // Dany jest wektor wynikow konkursu informatycznego, w postaci
  vector<int> wynik = {1,2,1,8,3};
  //zakładamy, że uczestnik "0" otrzymał wynik[0] punktów, uczestnik 1 wynik[1] itd.
  //Proszę wypisać numery uczestników posortowanych w kolejności od tego, który uzyskał
  //najwięcej punktów do tego który uzyskał najmniej.
  
   //Zadanie2: rozpatrzmy liczby całkowite od 0 do 10 włacznie, na osi liczbowej.
  // Mówimy, ze przedział [a,b] pokrywa liczby od a do b, w tym sensie,
  // ze zawiera on wszystkie liczby od a do b włacznie, czyli {a,a+1,...,b-1,b}
  // Zadany jest zbiór przedziałó w postaci wektora par {a,b}.
  // Proszę sprawdzić, czy każda z liczb od 0 do 10 włącznie jest pokryta przez 
  // przynajmniej jeden z podanych przedziałów.
  //Przykład 1:
  vector<pair<int, int>> W1 = {{1, 3}, {2, 5}, {1, 8}};
  //odpowiedź: nie (pozotają niepokryte 0, 9, 10
  //Przykład 2:
  vector<pair<int, int>> W2 = {{1, 3}, {4, 5}, {5, 10}};
  //odpowiedź: tak
  
  
  //Zadanie3:
  // Rozpatrzmy punkty o całkowitych współrzędnych na płaszczyźnie.
  // Niech współrzędne punktów będą opisywane w postaci {x,y}, gdzie
  // zawężamy się do kwadratu 0<=x,y<=100
  // Proszę wyznaczyć największą liczbę punktów na tej płaszczyźnie, leżących
  // na tym samym (pewnym) okręgu. Przykład: punkty {0,5},{3,4},{4,3},{5,0}
  // leżą na okręgu o promieniu 5, natomiast punkty:
  // {1,18},{6,17},{10,15},{15,10},{17,6},{18,1} na okręgu o promieniu sqrt(100+225)
  //
  // Wersja truniejsza: proszę wypisać pary punktów dla "najlepszego" okręgu.
};
