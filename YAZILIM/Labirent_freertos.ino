

#include <Arduino_FreeRTOS.h>
#include <Servo.h>
Servo myServo1;
Servo myServo2;

void TaskServo1( void *pvParameters );
void TaskServo2( void *pvParameters );
void setup() {

  // Now set up two Tasks to run independently.
  xTaskCreate(
    TaskServo1
     , "DigitalRead"  // A name just for humans
    , 128  // This stack size can be checked & adjusted by reading the Stack Highwater
    ,NULL
    , 2  // Priority, with 3 (configMAX_PRIORITIES - 1) being the highest, and 0 being the lowest.
    ,NULL );

  xTaskCreate(
    TaskServo2
    ,  "DigitalRead"
    ,  128  // Stack size
    ,  NULL
    ,  2  // Priority
    ,  NULL );
    Serial.begin (9600);

}
void loop()
{
 
}
void TaskServo1( void *pvParameters __attribute__((unused)) )  // This is a Task.
{
 
  myServo1.attach(9);
  int Pot1=A0;
  int deger;
 
  for (;;) // A Task shall never return or exit.
  {
    deger=analogRead(Pot1);
    deger=map(deger,0,1023,0,180);
       myServo1.write(deger);
   
      }
    vTaskDelay(1);
  }
  void TaskServo2( void *pvParameters __attribute__((unused)) )  // This is a Task.
{
 myServo2.attach(11);
  int Pot2=A1;
int deger1;
 
  for (;;) // A Task shall never return or exit.
  {
 deger1=analogRead(Pot2);
  deger1=map(deger1,0,1023,0,180);
  Serial.print("deger1");
     Serial.println(deger1);
   myServo2.write(deger1);

 
      }
  vTaskDelay(1);
  }
