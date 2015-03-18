// Przyklady (wersja prostsza)
// {1,1,2,2,2,2} OK
// {1,4,4,4,4} OK
// {2,2,2,2} OK
// {1,2,2,1} OK
// {1,4} ERR
// {1,2,1,2} ERR
// {2} ERR

// Wersja trudniejsza: zapytano ludzi na niktórych pozycjach, i odpowiedzieli prawdę; 
// (0 oznacza, że nie zapytano na tej pozycji)
// Proszę sprawdzić, czy na podstawie ich odpowiedzi da się już wyznaczyć pełny rozkład odpowiedzi w rzędzie

// Przykłady:
// {0,2}  TAK
// {2,0,0,2} TAK
// {0,2,2,0} NIE
// {0,2,0,3,0} TAK
// {0,0,3,0,0,0,4} TAK
// {0,2,0,2,0,2} TAK
// {2,0,2,0} TAK
// {0,0,2} NIE



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



