#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,b,n) for(int i=b;i<n;++i)
#define ALL(c) (c).begin(),(c).end()
#define SS size()
#define PB push_back
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef long long ll;
typedef pair<int,int> pii;
#define ST first
#define ND second


///////////////////////////////////////////////
///forward definitions: jakie klasy wystąpią
struct F;
struct K;
struct P;


///////////////////////////////////////////////
/// headers -- czyli __zero__ kodu, tylko sygnatury funkcji, i zmienne wewnętrzne

struct FInterface {
    int typ;
    virtual bool czyKolizja(FInterface& f) = 0;
};

struct F : FInterface {
    bool czyKolizja(FInterface& f) override ;
};

struct K : F {
    int x;
    K();
};

struct P : F {
    int y;
    P();
};

///////////////////////////////////////////////
/////// KOD -- tu wolno korzystac z "." i "->"

bool czyKolizja_fn(K& k1, K& k2) {
    return (k1.x - k2.x)==0;
}

bool czyKolizja_fn(P& p, K& k) {
    return (p.y - k.x)==0;
}

bool czyKolizja_fn(K& k, P&p) {
    return czyKolizja_fn(p, k);
}


bool F::czyKolizja(FInterface& f)  {
    if (typ==0) {
        if (f.typ==0) {
            K& k2 = (K&)f;
            return czyKolizja_fn((K&)*this, k2);
        }  else {
            P& p = (P&)f;
            return czyKolizja_fn((K&)*this, p);
        }
    } return false; //todo: impl dla this->typ==1
}

K::K() { typ = 0; }

P::P() { typ = 1; }



int main() {
    K kolo;
    P pros;
    kolo.x = 2;
    pros.y = 2;
    F& f1 = kolo;
    F& f2 = pros;
    cout << f1.czyKolizja(f2) << endl;
    K kolo2;
    kolo2.x = 2;
    F& f3 = kolo2;
    cout << f3.czyKolizja(f1) << endl;
}
