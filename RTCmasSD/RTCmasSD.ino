#include <SD.h>
#include <Time.h>
#include <TimeLib.h>
#include <Wire.h>
#include <RTClib.h>

RTC_DS3231 rtc;
File myFile;
void setup()
{
  Serial.begin(9600);
  Serial.print("Iniciando SD ...");
  if (!SD.begin(4)) {
    Serial.println("No se pudo inicializar");
    return;
  }
  Serial.println("inicializacion exitosa");

  // Comprobamos si tenemos el RTC conectado
 if (! rtc.begin()) {
 Serial.println("No hay un módulo RTC");
 while (1);
 }

 // Ponemos en hora, solo la primera vez, luego comentar y volver a cargar.
 // Ponemos en hora con los valores de la fecha y la hora en que el sketch ha sido compilado.
 rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
}

void loop()
{

  myFile = SD.open("datalog.txt", FILE_WRITE);//abrimos  el archivo
  
  if (myFile) { 
        Serial.print("Escribiendo SD: ");
        DateTime now = rtc.now();
              
        myFile.print("Dia: ");
        myFile.print(now.day());
        myFile.print(", Mes:");
        myFile.print(now.month());
        myFile.print(", Anio:");
        myFile.print(now.year());
        
        myFile.print(", Hora:");
        myFile.print(now.hour());
        myFile.print(", Minuto:");
        myFile.print(now.minute());
        myFile.print(", Segundos:");
        myFile.print(now.second());
        myFile.println();
        
        myFile.close(); //cerramos el archivo
        
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
  
  } else {
    Serial.println("Error al abrir el archivo");
  }
  delay(1000);
}
