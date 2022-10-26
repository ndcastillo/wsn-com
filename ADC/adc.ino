#include <Wire.h>
#include <Adafruit_ADS1X15.h>

Adafruit_ADS1115 ads;
const float multiplier = 0.1875F;

void setup(void)
{
  Serial.begin(9600);
 
  ads.begin();
}

void loop(void)
{
  int16_t results = ads.readADC_Differential_0_1();  
 
  Serial.print("Diferencial: "); 
  Serial.print(results); 
  Serial.print(" "); 
  Serial.print(results * multiplier); 
  Serial.println("mV");

  delay(1000);
}
