#include <Servo.h>
#include <stdlib.h>
#include <stdio.h>

Servo myservo;

int postion = 100;   // initial position

int ldr0 = A0;  // LRD 0 pin
int ldr1 = A1;  // LDR 1 pin
int ldr2 = A2;  // LDR 2 pin
int tolerance = 2;

float temp3 = A3; // temperature pin 3
float temp4 = A4; // temperature pin 4
float temp5 = A5; // temperature pin 5


//FILE * ldr1 = fopen("Photodiode state.xlsx","w");
//FILE * ldr2 = fopen("Photodiode state.xlsx","w");
//FILE * ldr3 = fopen("Photodiode state.xlsx","w");

void setup()
{
  Serial.begin(9600); // bits per second
  myservo.attach(9, 544, 2400);  // attaches the servo on pin 9 to the servo object
  pinMode(ldr0, INPUT);
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);

  pinMode(temp3, INPUT);
  pinMode(temp4, INPUT);
  pinMode(temp5, INPUT);
  myservo.write(postion);
}

void loop()
{
  int val0 = analogRead(ldr0); // read the value of ldr 0
  int val1 = analogRead(ldr1); // read the value of ldr 1
  int val2 = analogRead(ldr2); // read the value of ldr 2

  float ldr0 = (float)val0 * (100 / 1024.0);
  Serial.print("sensor number 0 reading is \n");
  Serial.print(ldr0);
  Serial.print("%");
  Serial.print(val0);
  delay(2000);
  
  float ldr1 = (float)val1 * (100 / 1024.0);
  Serial.print("sensor number 1 reading is\n");
  Serial.print(ldr1);
  Serial.print("%");
  Serial.print(val1);
  delay(2000);
  
  float ldr2 = (float)val2 * (100 / 1024.0);
  Serial.print("sensor number 2 reading is\n");
  Serial.print(ldr2);
  Serial.print("%");
  Serial.print(val2);
  delay(2000);

  if ((abs(val0 - val1) <= tolerance) || (abs(val1 - val0) <= tolerance))
  {
    // if sensor values are in tolerance do nothing
  }

  else
  {
    if (ldr0 > ldr1)
    {
      postion = --ldr2;  // deincrement to untill the middle sensor equals ldr1
      delay(200);
    }

    if (ldr0 <= ldr2)  //increment untill middle sensor equals ldr2
    {
      postion = ++ldr2;
    }
    delay(200);

    if (postion >= 180)
    {
      postion = 180; // reset to 180 if it goes higher
    }
    delay(2000);

    if (postion <= 40)
    {
      postion = 0;  // reset to 0 if it goes lower
    }
    delay(2000);

    myservo.write(postion); // write the position to servo
    delay(100);

  }



  //fprintf(ldr1, "current reading is %d\n", ld1)
  //fprintf(ldr2, "current reading is %d\n", ld2)
  //fprintf(ldr3, "current reading is %d\n", ld3)
  //return 0;
}
