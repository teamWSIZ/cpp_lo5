#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,b,n) for(int i=b;i<n;++i)
#define ALL(c) (c).begin(),(c).end()
#define SS size()
#define ST first
#define ND second

struct Stud {
  int idStud;
  string imie;
  string nazw;
  string uni;
  string miasto;
  int rok;
  int dochod;
};

Stud czytajZpliku(fstream& ff) {
  Stud s;
  ff >> s.idStud >> s.imie >> s.nazw >> s.uni >> s.miasto >> s.rok >> s.dochod;
  return s;
}

string to_string(Stud& s) {
  return s.imie + s.nazw + s.miasto;
}

struct Uni {
  int idUni;
  string nazwa;
};


//Studenci
map<int,Stud> studs;

//Uniwersytety
map<int,Uni> unis;

int main() {
  fstream pp("abc.txt");
  REP(i,3) {
    Stud s = czytajZpliku(pp);
    studs[s.idStud] = s;
    cout << to_string(s) << endl;
  }
  set<string> nazwyUni;
  for(pair<int,Stud> s : studs) {
    nazwyUni.insert(s.second.uni);
  }
  for(string s : nazwyUni) cout << s << endl;

  double suma = 0;
  for(pair<int,Stud> s : studs) {
    suma += s.ND.dochod;
  }
  cout << 1.0 * suma / studs.size() << endl;

  map<string,int> aaa;
  for(pair<int,Stud> s : studs) {
    aaa[s.ND.miasto]++;
  }
  int mx = -1;

}
