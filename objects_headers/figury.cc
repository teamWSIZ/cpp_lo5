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

///jakie klasy wystąpią
struct F;
struct K;
struct P;

///headers -- czyli __zero__ kodu, tylko sygnatury funkcji, i zmienne wewnętrzne

bool czyKolizja(K* k1, K& k2) {
    return k1->x - k2.x;
}

bool czyKolizja(P& p, K* k) {
    return p.y - k->x;
}

struct FInterface {
    int typ;
    virtual bool czyKolizja(FInterface& f) = 0;
};



struct F : FInterface {
    bool czyKolizja(FInterface& f) override {
        if (typ==0) {
            if (f.typ==0) {
                K& k2 = (K&)f;
                //nie może być referencja poniżej
                return czyKolizja((K*)this, k2);
            }  else {
                P& p = (P&)f;
                //nie może być referencja poniżej
                return czyKolizja(p, (K *) this);
            }
        }
        return false; //impl dla this->typ==1
    }
};

struct K : F {
    int x;
    K() { typ = 0; }
};

struct P : F {
    int y;
    P() { typ = 1; }
};

///impl -- tu można korzystać z


int main() {
    K kolo;
    P pros;
    kolo.x = 1;
    pros.y = 2;
    F& f1 = kolo;
    F& f2 = pros;
    cout << f1.czyKolizja(f2) << endl;
}
