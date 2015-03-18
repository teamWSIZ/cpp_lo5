// Przyklady
// {1,1,2,2,2,2} OK
// {1,4,4,4,4} OK
// {2,2,2,2} OK
// {1,2,2,1} OK
// {1,4} ERR
// {1,2,1,2} ERR
// {2} ERR


bool czyJestDobry(vector<int> dane) {
  //nasz kod
  return true; //or false
}

void test(vector<int> dane, bool dobryWynik) {
  bool wynik = czyJestDobry(dane);
  if (wynik==dobryWynik) {
    cout << "OK" << endl;
  } else {
    for(int i=0; i<dane.size(); i++) {
      cout << ", " << dane[i];
    }
    cout << "poprawny wynik:"<< dobryWynik << " otrzymano:" << wynik << endl;
  }
}

//wykorzystanie testera:
int main() {
  test({1,2,3},true);

};



