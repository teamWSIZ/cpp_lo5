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
#define MP(a,b) make_pair((a),(b))

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


//See: http://codeforces.com/blog/entry/11080

typedef
	tree<
	  pair<int,int>,
	  null_type,
	  less<pair<int,int> >,
	  rb_tree_tag,
	  tree_order_statistics_node_update
	> ordered_set;

typedef
	tree<
	  int,
	  null_type,
	  less<int>,
	  rb_tree_tag,
	  tree_order_statistics_node_update
	> oset;

typedef
	tree<
	  string,
	  null_type,
	  less<string>,
	  rb_tree_tag,
	  tree_order_statistics_node_update
	> sset;

int main() {
	// ordered_set t;
	// t.insert(MP(1,2));
	// t.insert(MP(2,10));
	// cout << t.order_of_key(MP(2,9)) << endl;
	// oset tt;
	// tt.insert(10);
	// tt.insert(30);
	// cout << tt.order_of_key(15) << endl;

	sset ss;
	ss.insert("abc");
	ss.insert("aaa");
	ss.insert("aba");
	cout << ss.order_of_key("abb") << endl;
}
