#include <DHT.h>
#include <DHT_U.h>

#define DHTTYPE DHT11 // DHT 11
float DHTPIN = A2;


DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  // A leitura de temperatura e umidade pode levar 250ms!
  // O atraso do sensor pode chegar a 2 segundos.
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // testa se retorno é válido, caso contrário algo está errado.
  if (isnan(t) || isnan(h))
  {
    Serial.println ("Failed to read from DHT");
    delay(2000);
  }
  else
  {
    Serial.print("Umidade: ");
    Serial.print(h);
    Serial.print (" %t");
    Serial.print ("temperatura: ");
    Serial.print (t);
    Serial.println(" °C");
    delay(2000);  
  }
  
  }

