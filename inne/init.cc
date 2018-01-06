#define REP(i, n)  for(int i=0;i<(int)(n);++i)
#define FOR(i, b, n)  for(int i=b;i<(n);++i)
#define ALL(c) (c).begin(),(c).end()
#define SS size()
#define PB push_back
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;

template<typename T, typename U> static void amin(T &x, U y) { if (y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if (x < y) x = y; }

template <typename T> void print(T& w) {
    for(auto e : w) cout << e << ", ";
    cout << endl;
}

ll inv(ll a, ll m){
    return 1 < a ? m - inv(m % a, a) * m / a : 1;
}
