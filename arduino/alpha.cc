///////////////////////////////////////////////////////////
// czytanie czujnika światła
// podłączenie pinu sygnału do porti A0
// doku: https://botland.com.pl/czujniki-swiatla-i-koloru/2260-temt6000-czujnik-natezenia-swiatla-otoczenia-modul-sparkfun.html

int noga = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  double value = analogRead(noga);
  Serial.println(value);
  delay(100);   
}
///////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////
// Odczyt temperatury z 18B20 (Dallas)
//
// widok pinów (uwaga na to który jest ground):
// https://ae01.alicdn.com/kf/HTB19LMqKpXXXXbOXXXXq6xXFXXXF/Free-Shipping-10pcs-DALLAS-DS18B20-18B20-18S20-TO-92-IC-CHIP-Thermometer-Temperature-Sensor.jpg_640x640.jpg
// https://create.arduino.cc/projecthub/TheGadgetBoy/ds18b20-digital-temperature-sensor-and-arduino-9cc806 
///////////////////////////////////////////////////////////


#include <OneWire.h>
#include <DallasTemperature.h>


const int noga = 2;
OneWire oneWire(noga); 
DallasTemperature sensors(&oneWire);


void setup() {
  Serial.begin(9600);
//  pinMode(noga, INPUT);
  sensors.begin(); 

}

void loop() {
  //int value = analogRead(noga);
  //double temp = 1.0 * value / 10;
  //Serial.print(temp);
  sensors.requestTemperatures();
  Serial.print(sensors.getTempCByIndex(0));
  Serial.println("C");
  delay(1000);
}

