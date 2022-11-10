#include <Arduino_FreeRTOS.h>

void TaskBlink1( void *pvParameters );

void TaskBlink2( void *pvParameters );

void Taskprint( void *pvParameters );

void setup() {

  // comunicacion 9600 bps:

  Serial.begin(9600);

  xTaskCreate(

    TaskBlink1

    ,  "task1"   

    ,  128  

    ,  NULL

    ,  1  

    ,  NULL );

  xTaskCreate(

    TaskBlink2

    ,  "task2"

    ,  128  

    ,  NULL

    ,  1  

    ,  NULL );

    xTaskCreate(

    Taskprint

    ,  "task3"

    ,  128  

    ,  NULL

    ,  1  

    ,  NULL );

vTaskStartScheduler();

}

void loop()

{

}

bool shiftLeft(){
    bool shiftValue;
    shiftValue = PORTB<<1;
    Serial.println(shiftValue);
    return shiftValue;
}

int shiftRight(){
    int shiftValue;
    shiftValue = PORTB>>1;
    return shiftValue;
}

void TaskBlink1(void *pvParameters)  {
  // B0 B1 B2 B3

  //DDRD &= 1B11111111;
  
  pinMode(8, OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  
  PORTB = B00000001;
  bool dir = true;
  while(1)

  {

    //Serial.println("Task1");
    //vTaskDelay( 300 / portTICK_PERIOD_MS );

    if (PORTB<B00010000 & dir){
        PORTB = PORTB<<1; 
    }
    else if (PORTB<=B00010000 & dir){
        PORTB = B00001000;
        dir = false;
    }
    else{
        PORTB = PORTB>>1;
        if(PORTB==B00000000 & !dir){
            dir=true;
            vTaskDelay( 300 / portTICK_PERIOD_MS );
            PORTB=B00000001;
        }
    }
    vTaskDelay( 300 / portTICK_PERIOD_MS );

  }

}

void TaskBlink2(void *pvParameters)  

{

  //pinMode(7, OUTPUT);

  //DDRD = B11111111;
  //pinMode(10, OUTPUT);
  //pinMode(11, OUTPUT);
  
  while(1)

  {

   //Serial.println("Task2");

   //PORTB = (PORTB | B00001100);
   //vTaskDelay( 500 / portTICK_PERIOD_MS ); 
   //PORTB = (PORTB | B00000000);
   //vTaskDelay( 500 / portTICK_PERIOD_MS ); 

   
    //digitalWrite(7, HIGH);   

    //vTaskDelay( 300 / portTICK_PERIOD_MS ); 

    //digitalWrite(7, LOW);   

    //vTaskDelay( 300 / portTICK_PERIOD_MS ); 

  }

}

void Taskprint(void *pvParameters)  {

  int counter = 0;

  while(1)

  {

counter++;

  Serial.println(counter); 

  vTaskDelay(500 / portTICK_PERIOD_MS);    }

}