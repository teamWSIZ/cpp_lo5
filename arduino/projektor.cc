/*
 * Oprogramowanie modułu sterowania ekranem dla projektora w gim16bb
 */


int screenPos = 0;   //pozycja ekranu w "krokach"; resetowana na zero jesli wykryto ze ekran full up
const int fullUp = 20; 
const int screenStep = 5;
const int screenDistance = 10; //od czujnika to ekranu jak jest opuszczony


//piny
const int lightPin = 0; //analog A0
const int distTrigPin = 6; //do czujnika odległości
const int distEchoPin = 7; //do czujnika odległości


//sprawdz z sensora czy projektor jest wlaczony
bool isProjOn() {
  double value = analogRead(lightPin);
  Serial.print("Light value:");
  Serial.println(value);
  if (value<=200) return true; 
  else return false; 
}


int findDistance() {
  long czas, dystans;
  digitalWrite(distTrigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(distTrigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(distTrigPin, LOW);
 
  czas = pulseIn(distEchoPin, HIGH, 10000); 
  dystans = czas / 58;
  if (dystans==0) dystans = 666;

  Serial.print("Distance:");
  Serial.println(dystans);
 
  return dystans;
}

//sprawdz czy ekran jest calkowicie podniesiony
bool isScreenFullUp() {
  if (findDistance() >= screenDistance) {
    //widac w nieskonczonosc
    if (screenPos <=0) {
      screenPos = 0;
      Serial.println("Calibrating screenPos to zero");
    }
    return true; 
  }
  return false; 
}

//sprawdz czy ekran jest calkowicie opuszczony
bool isScreenFullDown() {
  return screenPos >= fullUp; 
}

void moveScreenUp() {
  screenPos -= screenStep;
}

void moveScreenDown() {
  screenPos += screenStep; 
}


void setup() {
  Serial.begin(9600);
  pinMode(distTrigPin, OUTPUT);
  pinMode(distEchoPin, INPUT);
}

void loop() {
  Serial.println("----------");
  if (isProjOn()) {
    if (!isScreenFullDown()) {
      moveScreenDown();
    }
  } else {
    if (!isScreenFullUp()) {
      moveScreenUp();
    }
  }

  //debug
  if (isProjOn()) {
    Serial.println("Projektor jest włączony");
  } else {
    Serial.println("Projektor jest wyłączony");
  }

  Serial.print("Pozycja ekranu:");
  Serial.println(screenPos);
  Serial.println("----------");

  delay(1000);

}


