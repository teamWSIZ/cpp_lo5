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

class Point {
public:
	int x; 
	int y; 
	
	Point(int xx = 0, int yy = 0) {
		x = xx;
		y = yy;
	}
	Point(Point& other) {
		x = other.x;
		y = other.y;
	}
	
	string to_string() {
		string res = "";
		res += "{x=" + std::to_string(x) + ", y=" + std::to_string(y) + "}";
		return res;
	}
	
	double len() {
		return sqrt(0.0 + x*x+y*y);
	}
	
	double angle(Point& p) {
		return (0.0 + p.x * x + p.y * y)/(len() * p.len());
	}
};

Point rakieta(Point& prak, Point& vrak, Point& psam, Point& vsam) {
	Point noweV(0,0);
	
	return noweV;
}





int main() {
	Point x(1,0);
	Point y(2,0);
	cout << x.to_string() << endl;
	cout << x.angle(y) << endl;
	
}
