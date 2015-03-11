//Zadanie jest nasępujące:
// Zadany jest string s, np. s="abcca"
// Dla każdej litery `char c` definiujemy jej wartość jako  `c - 'a' + 1` (czyli np. wartosc a to 1, d to 4 itd). 
// Dodatkowo, dla każdej litery `char c` definiujemy jej wagę jako liczbę liter w `s`, które są mniejsze bądź równe
// literze `c`; czyli dla powyższego stringu `s` waga 'a' to 2, waga 'b' to 3, waga 'c' to 5. 

// Proszę policzyć sumę wag pomnożonych przez wartości wszystkich litek zadanego stringu s, czyli 
// sum_{i=0...len(s)-1} waga[s[i]] * wartosc[s[i]].

// Przykład 1: s="babca", suma=2*4 + 1*2 + 2*4 + 3*5 + 1*2 = 35
// Przykład 2: s="thequickbrownfoxjumpsoverthelazydog", suma=11187
