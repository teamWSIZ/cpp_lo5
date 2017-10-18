#include <bits/stdc++.h>
using namespace std;
#define REP(i, n)  for(int i=0;i<(int)(n);++i)
#define FOR(i, b, n)  for(int i=b;i<(n);++i)
#define ALL(c) (c).begin(),(c).end()
#define PB(c) push_back(c)
#define SS size()
#define ST first
#define ND second
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int main() {
//    map<int,int> m;
//    m[0]++;
//    cout << m.size() <<endl;
//    m.erase(0);
//    cout << m.size() <<endl;

    vector<int> a = {2, 4, 4, 7, 7, 2, 5, 2, 1, 1, 1, 8, 4};
    int k = 4;
    map<int,int> bla;
    REP(i,k) bla[a[i]]++;

    int mx = bla.size();
    for(int start = 1; start + k <= a.size(); start++) {
        //przesuwamy sie do okna startującego na start:
        //czyli wywalamy liczbe na start-1
        //dodajemy liczbe na start+k-1
        bla[a[start+k-1]]++;
        bla[a[start-1]]--;
        //jesli usuneliśmy ostatnią, to wywalmy "klucz" a[start-1], by móc dostać wynik z "bla.size"
        if (bla[a[start-1]]==0) bla.erase(a[start-1]);
        cout << "start:" << start << " --> " << bla.size() << endl;
    }


}

















