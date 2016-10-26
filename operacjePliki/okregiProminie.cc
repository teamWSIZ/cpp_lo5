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
	ifstream plik("c:\\bbb\\dane.txt");
	//ofstream output("bbb.txt");
	//string linia;  
	int x, y, r; 
	int ile = 0;
	int najw = 0;
	vi blu (1000);
	while(plik >> x >> y >>r) {
		blu [r-1]++;
		if (r == 1){
			cout << x << " --> " << y << endl;
		}
		if (najw < r){
			najw = r;
		}
		ile ++;
	}
	int viel = 0;
	int gdzie = 0;
	for (int i = 0;i < 50; i++){
		if (viel < blu[i]){
			viel = blu[i];
			gdzie = i;
		}
	}
	cout << "okręgów jest " << ile << " najwiekszy okrąg ma promień = " << najw << endl;
	cout << "najwięcej promieni jest " << gdzie + 1 << " jest ich " << viel << endl;
}
	
