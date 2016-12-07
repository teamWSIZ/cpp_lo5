#include <bits/stdc++.h>
using namespace std;
#define REP(i,n)  for(int i=0;i<(int)(n);++i)
#define FOR(i,b,n)  for(int i=b;i<(n);++i)
#define ALL(c) (c).begin(),(c).end()
#define SS size()
#define CLR(a,v) memset((a),(v), sizeof a)
#define ST first
#define ND second
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int,int> pii;

typedef vector<int> vi;


int main() {
  ll n; cin >> n; 
  int ans = 0;
  ll sum = 1;
  ll pow = 2;
  while(sum < n) {
    sum += pow;
    if (n==sum) break;
    if (n % sum == 0) ++ans;
    pow *= 2;
  }
  cout << ans << endl;
  
}

