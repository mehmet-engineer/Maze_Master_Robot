#include <Servo.h>

Servo motor;

const int trig=12;
const int echo=13;

const int sol_geri=11;
const int sol_ileri=10;
const int sag_geri=9;
const int sag_ileri=8;

const int servo=7;

#define V 0.0343909

  int sure=0;
  int mesafe=0;
  
void setup() {

  motor.attach(servo);
  pinMode(echo,INPUT);
  pinMode(trig,OUTPUT);

  Serial.begin(9600);
  
}

void loop() {

  motor.write(90);
  
  digitalWrite(trig,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig,LOW);

  sure = pulseIn(echo,HIGH) / 2;
  mesafe = V * sure;


  if(mesafe <= 28)
  {
    int distance1=0;
    int distance2=0;
    
    digitalWrite(sol_ileri,HIGH);
    digitalWrite(sag_ileri,HIGH);
    digitalWrite(sol_geri,HIGH);
    digitalWrite(sag_geri,HIGH);
    delay(500);
    
    digitalWrite(sol_geri,HIGH);
    digitalWrite(sag_geri,HIGH);
    digitalWrite(sol_ileri,LOW);
    digitalWrite(sag_ileri,LOW);
    delay(600);

    digitalWrite(sol_geri,LOW);
    digitalWrite(sag_geri,LOW);
    delay(500);

    motor.write(40);
    delay(500);
    distance1 = mesafeyi_olc();
    delay(200);

    motor.write(140);
    delay(500);
    distance2 = mesafeyi_olc();
    delay(200);

    if(distance1 >= distance2)
    {
       motor.write(40);
       delay(400);
       
       digitalWrite(sol_ileri,HIGH);
       digitalWrite(sag_geri,HIGH);
       digitalWrite(sol_geri,LOW);
       digitalWrite(sag_ileri,LOW);
       delay(250);

       motor.write(90);
       delay(400);
    }
    else
    {
       motor.write(140);
       delay(400);
      
       digitalWrite(sag_ileri,HIGH);
       digitalWrite(sol_geri,HIGH);
       digitalWrite(sag_geri,LOW);
       digitalWrite(sol_geri,LOW);
       delay(250);

       motor.write(90);
       delay(400);
    }

    
    
  }
  else
  {
    
    digitalWrite(sol_ileri,HIGH);
    digitalWrite(sag_ileri,HIGH);
    digitalWrite(sol_geri,LOW);
    digitalWrite(sag_geri,LOW);

  }
  

}

int mesafeyi_olc()
{
  digitalWrite(trig,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig,LOW);

  sure = pulseIn(echo,HIGH) / 2;
  mesafe = V * sure;
  return mesafe;
}
