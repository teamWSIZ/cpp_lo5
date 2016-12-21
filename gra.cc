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
	//dane przechowywane przez instancje klasy Point; 
	//odpowiada ona punktowi (lub wektorowi) na plazczyznie dwu-wymiarowej
	double x; 
	double y; 
	
	//tworzenie punktu o zadanych koordynatach
	Point(double xx = 0, double yy = 0) {
		x = xx;
		y = yy;
	}
	
	//tworzenie kopii punktu
	Point(Point& other) {
		x = other.x;
		y = other.y;
	}
	
	//dodawanie do punktu innego punktu (dodawanie wspolrzednych)
	void add(Point& p) {
		x += p.x;
		y += p.y;
	}
	
	//mnozenie punktu (wektora) przez liczbe 
	void multiply(double factor) {
		x *= factor;
		y *= factor;
	}
	
	//zamiana danych punktu na napis gotowy do wydruku
	string to_string() {
		string res = "";
		res += "{x=" + std::to_string(x) + ", y=" + std::to_string(y) + "}";
		return res;
	}
	
	//dlugosc wektora / odleglosc od srodka ukladu (punktu 0,0)
	double len() {
		return sqrt(x*x+y*y);
	}
	
	//zwraca cos kata miedzy obecnym wektorem i wektorem p
	double angle(Point& p) {
		return (p.x * x + p.y * y)/(len() * p.len());
	}
	
	//odleglosc miedzy obecnym punktem i punktem p
	double dist(Point& p) {
		Point diff(x - p.x, y - p.y);
		return diff.len();
	}
};

Point rakieta(Point& prak, Point& vrak, Point& psam, Point& vsam) {
	Point noweV(0,0);
	
	return noweV;
}


//ta funkcja definiuje jak ma sie zmieniac predkosc rakiety w zaleznosci od pozycji i predkosci obiektow
Point killer_rocket(Point psam, Point vsam, Point prak, Point vrak) {
	return vrak;
}

//ta funkcja definiuje jak ma sie zmieniac predkosc samolotu w zaleznosci od pozycji i predkosci obiektow
Point smart_plane(Point psam, Point vsam, Point prak, Point vrak) {
	return vsam;
}


//silnik do symulacji bitwy
class Engine {
private:
	Point psam;
	Point vsam;
	Point prak;
	Point vrak;

public:
	void run() {
		psam = Point(2,2);
		vsam = Point(-1,0);
		prak = Point(0,0);
		vrak = Point(0,2);
		
		double t = 0;
		double dt = 0.1;  //powinno byc 0.001
		while (t<1) {
			Point diff = vsam;
			diff.multiply(dt);
			psam.add(diff);
			
			diff = vrak;
			diff.multiply(dt);
			prak.add(diff);
			
			//tu zmodyfikowac predkosci vsam, vrak
			vrak = killer_rocket(psam, vsam, prak, vrak);
			vsam = smart_plane(psam, vsam, prak, vrak);
				
			if (psam.dist(prak)<0.05) {
				cout << "plane has shot down!" << endl;
				return;
			}
			
			//debug info
			cout << "------------\n";
			cout << "t=" << t << endl;
			cout << "prak: " << prak.to_string() << endl;
			cout << "vrak: " << vrak.to_string() << endl;
			cout << "psam: " << psam.to_string() << endl;
			cout << "vsam: " << vsam.to_string() << endl;
			
		}
		cout << "plane escaped to safety!" << endl;		
	}
};



//proby wykorzystania klasy point
int main() {
	Point x(1,0);
	Point y(2,0);
	cout << x.to_string() << endl;
	cout << x.angle(y) << endl;
	Point z(0,0);
	z = x;
	z.x = 11;
	cout << x.to_string() << endl;
	cout << z.to_string() << endl;

}
