#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 5

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);


float Celcius = 0;
float Fahrenheit = 0;
const float  OffSet = 0.3;
float V, P;

void setup()
{
  Serial.begin(9600);
  sensors.begin();
}

void loop() {
  // Pressure sensor
  
  // Connect sensor to A0, V = sensor output
  V = analogRead(0) * 5.00 / 1024;

  // Calculate water pressure
  P = ((V - OffSet) * 400) * .14503773800722;

  //Serial.print("Pressure = ");
  //Serial.println(P);
  // If pressure is LESS than 1 OR GREATER than 5 -alert
  if (P < 1 or P > 5) {
    Serial.println("Water Pressure Alert - Pumphouse water pressue is out of the threshold.");
  }   

  // Temperature sensor

  // Get data
  sensors.requestTemperatures();

  // Temp in C
  Celcius=sensors.getTempCByIndex(0);

  // Convert temp from C to F
  Fahrenheit=sensors.toFahrenheit(Celcius);

  // If temp is GREATER than 32 - alert
  if (Fahrenheit > 75) {
    Serial.println("Temperature Alert - Pumphouse pipes are at risk of freezing");
  }

  // 1 Second delay
  delay(15000);
}
