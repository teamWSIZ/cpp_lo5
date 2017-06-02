/*
 * Oprogramowanie modułu sterowania ekranem dla projektora w gim16bb
 * 
 * Do kalibracji:
 * SCREEN_FULL - tak aby ekran rozwijal sie w pelni
 * LIGHT_ON - tak aby wykryl projektor wlaczony, ale nie przypadkowo
 */

int SCREEN_FULL = 20; //wiecej -- ekran pojedzie nizej
int SCREEN_ROLLED_UP = -SCREEN_FULL/10; //bedzie polegal na czujniku by wykryc zwiniety ekran; mozna ustalic=0 to sam zatrzyma

int DELAY = 100; //ms
int SOUND_DISTANCE_TIMEOUT = 2000; //microseconds (2000 ~= max 20cm)
int LIGHT_ON = 150; //wiecej -- wiecej swiatla potrzeba do wykrycia jako 'projektor wlaczony'
int SCREEN_SOUND_DISTANCE = 10; //odleglosc od czujnika do ekranu (ekran zaslania widok czujnika)
//sterowanie pozycja ekranu
//uwaga: wiekszy DELAY spowoduje ze kroki sa dluzsze
int screen = 0;   //pozycja ekranu w "krokach" ; resetowana na zero jesli wykryto ze ekran full up
int screen_dst = 0; //pozycja do ktorej chcemy aktualnie przesunac ekran (silnikiem)



//piny
int PINL = 2; //analog A0
int PINTRIG = 3; //do czujnika odległości - wysyla
int PINECHO = 2; //do czujnika odległości - odbiera
int PINUP = 6;    //silnik UP
int PINDN = 5;    //silnik DOWN


//sprawdz z sensora swiatla czy projektor jest wlaczony
bool projectorRunning() {
    double value = analogRead(PINL);
    Serial.print("Swiatlo:");
    Serial.println(value);
    if (value>=LIGHT_ON) return true;
    else return false;
}

//Mierzy i podaje dystans w cm z ultradzwiekowego czujnika odleglosci
int soundDistance() {
    long czas, dystans;
    digitalWrite(PINTRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(PINTRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(PINTRIG, LOW);

    czas = pulseIn(PINECHO, HIGH, SOUND_DISTANCE_TIMEOUT);
    dystans = czas / 58;
    if (dystans==0) dystans = 1000;

    Serial.print("Odleglosc z czujnika dzwiekowego:");
    Serial.println(dystans);

    return dystans;
}

//sprawdz czy ekran jest calkowicie podniesiony
bool isScreenRolledUp() {
    if (soundDistance() >= SCREEN_SOUND_DISTANCE) {
        return true;
    }
    return false;
}

//logika sterowania pinami tak, by silnik przesunal ekran tam gdzie chcemy
void motionControl() {
    if (screen<screen_dst) {
        digitalWrite(PINUP, HIGH);
        digitalWrite(PINDN, LOW);
        screen++;
    } else if (screen>screen_dst) {
        digitalWrite(PINUP, LOW);
        digitalWrite(PINDN, HIGH);
        screen--;
    } else {
        digitalWrite(PINUP, LOW);
        digitalWrite(PINDN, LOW);
    }
    Serial.print("[");
    Serial.print(screen);
    Serial.print(" : ");
    Serial.print(screen_dst);
    Serial.println("]");
}

void setup() {
    Serial.begin(9600);
    pinMode(PINTRIG, OUTPUT);
    pinMode(PINECHO, INPUT);
    pinMode(PINUP, OUTPUT);
    pinMode(PINDN, OUTPUT);

    //wylacz ruchy silnika
    digitalWrite(PINUP, LOW);
    digitalWrite(PINDN, LOW);
}

void loop() {
    Serial.println("----------");
    if (projectorRunning()) {
        screen_dst = SCREEN_FULL;
    } else {
        if (isScreenRolledUp()) {
            //widac w nieskonczonosc
            //rekalibracja pozycji na =0
            screen = 0;
            screen_dst = 0;
        } else {
            //projektor wylaczony, ale ekran nie calkiem zwiniety:

            //jesli jeszcze nie ustawilismy ze silnik ma go zwijac
            if (screen_dst>0) {
                screen_dst = SCREEN_ROLLED_UP;
            }
        }
    }
    motionControl();

    //debug
    if (projectorRunning()) {
        Serial.println("Projektor jest włączony");
    } else {
        Serial.println("Projektor jest wyłączony");
    }

    Serial.print("Pozycja ekranu:");
    Serial.println(screen);
    Serial.println("----------");

    delay(DELAY);

}
