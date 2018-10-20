
const float  OffSet = 0.469 ;

float V, P;

void setup()
{
  Serial.begin(9600);        // open serial port, set the baud rate to 9600 bps
}
void loop()
{
  //Connect sensor to Analog 0
  V = analogRead(0) * 5.00 / 1024;     //Sensor output voltage
  P = ((V - OffSet) * 400) * .14503773800722;             //Calculate water pressure

  //Serial.print("Pressure = ");
  //Serial.println(P);
  if (P < 1 or P > 5)
    {Serial.println("Water Pressure Alert - Pumphouse water pressue is out of the threshold.");
    }
  
  delay(5000);
}
