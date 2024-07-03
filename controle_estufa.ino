#include "DHT.h"

#define setpoint 50.00 // ºC - Define a temperatura desejada

#define rele 27 // Define o pino do rele
#define dhtPino 25 // Define o pino do dht 

#define DHTTYPE DHT11 // Define o tipo do dht

float temp = 0; // Temperatura da estufa

DHT dht(dhtPino, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  pinMode(rele, OUTPUT);
  digitalWrite(rele, HIGH);
  
}

void loop() {
  temp = dht.readTemperature();

  if (temp > setpoint + 5){
    digitalWrite(rele, LOW);
  }

  if (temp < setpoint - 10){
    digitalWrite(rele, HIGH);
  }

  Serial.print("Temperatura: ");
  Serial.println(temp);

}
