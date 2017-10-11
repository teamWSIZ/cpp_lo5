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



struct Creature {
    string type;
    int hp;
    int att;
    int def;
    int min_dmg;
    int max_dmg;

    Creature(string type, int hp, int att, int def,
             int min_dmg, int max_dmg) : type(type), hp(hp), att(att), def(def),
                                                                   min_dmg(min_dmg), max_dmg(max_dmg) {}
};

struct CreatureGroup {
    Creature type;
    int count;
    int hp_left; //hp ostatniego członka grupy

    CreatureGroup(const Creature &type, int count, int hp_left) : type(type), count(count),
                                                                  hp_left(hp_left) {}
};


void fight(CreatureGroup& attacker, CreatureGroup& defender) {
    //grupa atakujaca zaatakuje defenderów; własności defenderów mają zostać zmodyfikowane

    int min_dmg = attacker.type.min_dmg * attacker.count;
    int max_dmg = attacker.type.max_dmg * attacker.count;

    double modifier = 1;

    int diff = attacker.type.att - defender.type.def;

    if (diff > 0) {
        modifier += (0.05) * diff;
    } else {
        modifier += (0.025) * diff;
    }
    min_dmg *= modifier;
    max_dmg *= modifier;
    //teraz mamy range demage'a, np. 22 : 33
    cout << "atakuje:" << attacker.type.type << endl;
    cout << "count:" << attacker.count << endl;
    cout << "demage range: [" << min_dmg << " : " << max_dmg << "] " << endl;

    int demage = min_dmg + (rand() % (max_dmg - min_dmg + 1));
    int total = (defender.count-1) * defender.type.hp + defender.hp_left;

    cout << "generated demage:" << demage << endl;
}






int main() {
    srand(time(0));
    Creature demon("Demon", 10, 5, 2, 10, 20);  //to jest instancja kreatury
    Creature chowaniec("Chowaniec", 8, 12, 8, 5, 8);

    CreatureGroup demony(demon, 10, 2);
    CreatureGroup chowance(chowaniec, 20, 8);

    fight(demony, chowance);
    fight(chowance, demony);

}



















