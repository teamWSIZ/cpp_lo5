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


template <typename T> void printContainer(T& a) {
  auto it = a.begin();
  cout << "{" << *(it++);
  for(; it!=a.end(); ++it) cout << ", " << (*it);
  cout << "}\n";
}



class Serwer {
public:
  int id;
  string ip;

  Serwer(int id, string ip) : id(id), ip(ip) { }

  bool operator<(const Serwer& rhs) const {
    return this->id < rhs.id;
  }

  int getId() const {
    return id;
  }

  void setId(int id) {
    Serwer::id = id;
  }

  string getIp() const {
    return ip;
  }

  void setIp(string ip) {
    Serwer::ip = ip;
  }
};



set<Serwer> baza;

//interface
class B {

public:
  virtual void saySometing()=0;
};

//implementation
class D : public B {

public:
  virtual void saySometing(){
    cout << "something\n";
  }
};
//

class Wiad {
private:
  int numer;  //niedosępna z zewnątrz

public:
  string tytul;

  Wiad(){}

  Wiad(int num, string tyt) {
    numer = num;
    tytul = tyt;
  }

  void napiszTytul() const {
    cout << "tytul=" << tytul << endl;
  }

  bool operator<(const Wiad& inna) const {
    return numer < inna.numer;
  }



};


int main() {
//  Serwer pierwszy(1, "dublin");
//  Serwer drugi(2, "london");
//  baza.insert(pierwszy);
//  baza.insert(drugi);
//
//  cout << baza.size() << endl;
//  cout << baza.count(Serwer(1,"")) << endl;
//
//  D d;
//  d.saySometing();

  Wiad nowa(11, "abcd");
  nowa.tytul = "abcd";


  Wiad inna(12,"");
  inna.tytul = "tajny";

 

//
//  nowa.napiszTytul();
//  inna.napiszTytul();
//
//  Wiad dziennik[20];
//  for (int i = 0; i < 20; ++i) {
////    dziennik[i].numer = i;
//    dziennik[i].tytul = string(10,'a'+i);
//    dziennik[i].napiszTytul();
//  }
//
//  vector<int> w(30,1);
//  cout << w[24] << endl;
//
//
//
//  set<int> S;
//  S.insert(12);
//  S.insert(38);
//  S.insert(44);
//  S.insert(12);

//  set<string> S;
//  S.insert("abc");
//  S.insert("a");
//  S.insert("abc");

  set<Wiad> S;

  S.insert(nowa);
  S.insert(inna);
  S.insert(Wiad(10,"aaaa"));

  bitset<5> b;


  for(set<Wiad>::iterator i = S.begin(); i!= S.end(); ++i) {
    (i->napiszTytul());
  }

  
  //Wskaźniki
  int w = 12;
  const int* pw = &w;

  cout << (*pw) << endl;
//  (*pw) = 11;
  cout << (*pw) << endl;
  cout << w << endl;

  //Wskaźnik do instancji naszej klasy
  Wiad* pInna = &inna;
  pInna->napiszTytul();


  //pętle w C++11
//  for(string s : S) cout << s << endl;


};

