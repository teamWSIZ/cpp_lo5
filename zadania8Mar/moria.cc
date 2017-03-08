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

class Moria {
public:
	vector<vector<int>> below;		//below[5]: lista komnat ponizej komnaty 5
	int rooms;
	int MAX_DEPTH = 7;
	int SCREEN_WIDTH = 150;
	int SCALE = 32;
	int CHANCE = 92; //95% szansy na stworzenie komnaty

	
	void createMine(int rt, int lv) {
        below[rt] = vector<int>();
        cout << "creating room " << rt << " at depth " << lv << endl;
        if (lv<MAX_DEPTH) {
            for (int i = 0; i < 2; i++) {
				//jeśli wylosuje się za duża liczba, to nie tworzymy komnaty
				if (rand() % 100 > CHANCE) {
					cout << "Oh no! Orc's have struck! No room created!"<< endl;
					continue; 
				}
                int id = (++rooms);
                below[rt].push_back(id);
                createMine(id, lv+1);
            }
        }
        cout << "finished room " << rt << " at depth " << lv << 
        "; below it we see rooms:";
        for(int r : below[rt]) cout << r << " ";
        cout << endl;
    }
    
    //to jest konstruktor -- wykonywany przy tworzeniu obiektu Moria
    Moria() {
        below = vector<vector<int>>(2000);
        rooms = 1;
        createMine(1, 1);
        srand(time(NULL));
	}
	
	///drukowanie kopalni na ekranie:
	/// pierw tworzymy strukturę w której zapamiętujemy gdzie są komnaty,
	/// potem drukujemy kopalnię na podstawie tej struktury:
	/// - znak 'o' tam, gdzie ma być komnata,
	/// - znak '.' gdzie jest miejsce puste. 
	void printTheMine() {
		//ekran; "true" oznaczać będzie komnatę
        vector<vector<bool>> screen = 
			vector<vector<bool>>(20, vector<bool>(SCREEN_WIDTH));
			
        printRoom(1, 1, screen, screen[0].size()/2, SCALE);	//start drukowania: od górnego szybu
        
        for (int i = 0; i < screen.size(); i++) {
            for (int j = 0; j < screen[0].size(); j++) {
                cout << (screen[i][j] ? 'o' : '.');
            }
            cout << endl;
        }
	}
	
	///drukowanie komnaty: zaznacza komnatę na `screen` i wywołuje siebie
	/// dla wszystkich komnat poniżej
	void printRoom(int rt, int lv, vector<vector<bool>>& screen, int x, int len) {
        screen[lv][x] = true;
        int child_x = x - len;
        for(int c : below[rt]) {
            printRoom(c, lv+1, screen, child_x, len/2);
            child_x += 2 * len;
        }
	}
	
	///Zadanie: napisać tą funkcję, czyli znaleźć głębokość najgłębszej
	/// komnaty w Morii...
	int maxDepth() {
		//.....
	}
	
};


int main() {
	Moria moria;
	moria.printTheMine();
	//cout << moria.maxDepth() << endl;
}

