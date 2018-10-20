#include <OneWire.h>
#include <DallasTemperature.h>

#define ONE_WIRE_BUS 5

OneWire oneWire(ONE_WIRE_BUS);

DallasTemperature sensors(&oneWire);

 float Celcius=0;
 float Fahrenheit=0;
void setup(void)
{
  
  Serial.begin(9600);
  sensors.begin();
}

void loop(void)
{ 
  sensors.requestTemperatures(); 
  delay(1000);
  Celcius=sensors.getTempCByIndex(0);
  Fahrenheit=sensors.toFahrenheit(Celcius);

   if (Fahrenheit > 32)
   {Serial.print("Temperature Alert - Pumphouse pipes are at risk of freezing"); 
   
  

}}
