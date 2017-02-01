#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main() {
	LL a = 0;
	LL b = 1;
	for(LL i = 0; i< -1; i++) {
		LL c = a + b;
		cout << c << " ";
		a = b;
		b = c;
	}
	///
	vector<int> w = {1,2,3,4,3,3,2,5,0};
	//bool byla[10000];
	set<int> byla;
	//for(int i = 0; i< 10000; ++i) byla[i]=false;
	
	for(int i = 0; i< w.size(); ++i) {
		if (byla.count(w[i])==0) {
			byla.insert(w[i]); 
			cout << w[i] << " ";
		}
	}
	//////////////////////
	string nnn = "abrakadabra";
	cout << nnn << endl;
	cout << nnn[2] << endl;
	
	for(char c = 'a';  c <= 'z'; c++) { 
		cout << c << ",";
	}
	//petla po i=0... nnn.size()
	  //petla po znakach c='a'...'z'
	    //www = nnn; potem zamienic element nr. i na znak `c`
	
	
	
	
}

