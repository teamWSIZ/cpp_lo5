#include<bits/stdc++.h>
using namespace std;

int main() {
  ifstream plik("abc.txt");
  ofstream output("bbb.txt");
  string linia;  
  for(; getline(plik, linia);) {
    cout << "->" + linia << endl;
    output << "->" + linia << endl;
  }
} 
