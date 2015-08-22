`#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,b,n) for(int i=b;i<n;++i)
#define RFOR(i,n,b) for(int i=n;i>=b;--i)
#define ALL(c) (c).begin(),(c).end()
#define SS size()
#define PB push_back
#define CLR(a, val) memset((a),(val), sizeof a)
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef long long ll;
typedef pair<int,int> pii;
#define ST first
#define ND second
#define MP(a, b) make_pair((a),(b))


/**
 *  AlgoZ -- find indexOf "T" (all) in "S"
 */



struct AlgoZ {
    //res[] = how many chars of prefix of 's' can be fitted starting at `at`
    vi solve(string s) {
        int n = s.SS;
        vi z(n);
        int L = 0, R = 0;
        for (int i = 1; i < n; i++) {
            if (i > R) {
                L = R = i;
                while (R < n && s[R-L] == s[R]) R++;
                z[i] = R-L; R--;
            } else {
                int k = i-L;
                if (z[k] < R-i+1) z[i] = z[k];
                else {
                    L = i;
                    while (R < n && s[R-L] == s[R]) R++;
                    z[i] = R-L; R--;
                }
            }
        }
        return z;
    }

    vi indexOf(string S, string T) {
        //occurances of T in S
        string all = T+"#"+S;
        vi z = solve(all), res;
        for (int at = T.SS; at < all.SS; at++) if (z[at]==T.SS) 
            res.PB(at - T.SS-1);
        return res;
    }
};

int main() {
    string S = "aabaaabaaaabaa";
    string T = "aa";
    AlgoZ engine; 
    for(int i : engine.indexOf(S,T)) 
        cout << i << " -->" << S.substr(i) << endl;

}
