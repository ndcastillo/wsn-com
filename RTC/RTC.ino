// Librería para la comunicación I2C y la RTClib

#include <Time.h>
#include <TimeLib.h>
#include <Wire.h>
#include <RTClib.h>

// Declaramos un RTC DS3231
RTC_DS3231 rtc;
time_t fecha;

void setup () {
 Serial.begin(9600);
 setTime(12, 32, 0, 13, 12, 2016);
 fecha = now();
 
 delay(3000);

 // Comprobamos si tenemos el RTC conectado
 if (! rtc.begin()) {
 Serial.println("No hay un módulo RTC");
 while (1);
 }

 // Ponemos en hora, solo la primera vez, luego comentar y volver a cargar.
 // Ponemos en hora con los valores de la fecha y la hora en que el sketch ha sido compilado.
 rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop () {
 DateTime now = rtc.now();

 Serial.print(now.day());
 Serial.print('/');
 Serial.print(now.month());
 Serial.print('/');
 Serial.print(now.year());
 Serial.print(" ");
 Serial.print(now.hour());
 Serial.print(':');
 Serial.print(now.minute());
 Serial.print(':');
 Serial.print(now.second());
 Serial.println();
 delay(1000);
}
