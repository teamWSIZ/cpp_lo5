int PIN = 9;
int PID = 8;

void setup(){
  Serial.begin(9600);
  pinMode(PIN, OUTPUT);
  pinMode(PID, OUTPUT);
  digitalWrite(PIN, LOW);
  digitalWrite(PID, LOW);
}

int DELAY = 50; //ms
int FULL = 50;
int x = 0;  //really need to reset to zero once on top
int x_dst = FULL; 
int t = 0;

void motionControl() {
  if (x<x_dst) {
    digitalWrite(PIN, HIGH);
    digitalWrite(PID, LOW);
    x++;
  } else if (x>x_dst) {
    digitalWrite(PIN, LOW);
    digitalWrite(PID, HIGH);
    x--;
  } else {
    digitalWrite(PIN, LOW);
    digitalWrite(PID, LOW);
  }
  Serial.print(x);
  Serial.print(" : ");
  Serial.println(x_dst);
}


void loop() {
  motionControl();
  t++;
  if (t==100) x_dst = 0;
  delay(DELAY);
}
