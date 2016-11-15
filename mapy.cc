#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

/**
 *  Mapy, map<typ1,typ2>, czyli odwzorowania z jednego typu zmiennych w drugie.
 *  Przykład: 
 *     map<string,int> m; m["abrakadabra"]=12;    //jak tablica indeksowana string-ami
 *     map<int,int> m; m[1]=5; m[1000000000]=8;   //jak tablica z ogromnym przedziałem indeksów
 *
 *
 */

int main() {
  map<int,vi> m;
  m[0] = vi();
  m[0].push_back(12);
  m[1].push_back(11);
  m[1].push_back(11);
  m[1].push_back(11);
  m[1].push_back(11);

  vi& w = m[1];  //referencja czyli rodzaj "aliasu"
  for(int i=0; i<w.size(); i++) {
    cout << "->" << w[i] << endl;
  }
  cout << m[1].size() << endl;  //4; tyle jest elementów w wektorze m[1]

  map<int,int> mm;
  mm[-1e9] = 3;
  mm[8] = 17;
  mm[1e9] = 2;

  cout << mm.count(8) << endl;  //1, czyli jest 1 element dla indeksu 8
  cout << mm[-1e9] << endl; //3, dla indeksu 1000000000 (==1e9)

}
