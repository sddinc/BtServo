#include <Servo.h>

int led_q1 = 2;
int led_q2 = 3;
int led_q3 = 4;
String state ;
char state_x = 0;
int flag = 0;

Servo myservo;
int servoAngle = 0;   // servo position in degrees


void setup() {
  pinMode(led_q1, OUTPUT);
  pinMode(led_q2, OUTPUT);
  pinMode(led_q3, OUTPUT);
   myservo.attach(7);
  Serial.begin(9600); // Default connection rate for my BT module
 
}

void loop() {if (Serial.available() > 0) {
    state = Serial.read();
//     Serial.println(state_x);
//    state=state_x%5;
      Serial.println("-----");
      Serial.println(state);
    flag = 0;
  }

  if (state == "a") {
    if (flag == 0) {
      Serial.println("reset position ");
    
      //restart();

      myservo.write(0);  
      delay(2000);
      flag = 1;
       
     
    }
  }
  else if (state == 97) {
    if (flag == 0) {
      Serial.println("Q0");
     for(servoAngle = 0; servoAngle < 45; servoAngle++)  //move the micro servo from 0 degrees to 180 degrees
  {                                  
    myservo.write(servoAngle);              
    delay(50);                  
  }
      flag = 1;
      
    }
  }

  else if (state == 98) {
    if (flag == 0) {
      Serial.println("Q1");
     for(servoAngle = 0; servoAngle < 45; servoAngle++)  //move the micro servo from 0 degrees to 180 degrees
  {                                  
    myservo.write(servoAngle);              
    delay(50);                  
  }
      flag = 1;
      
      
    }
  }
  else if (state == "50") {
    if (flag == 0) {
      Serial.println("Q2");
      //q2();
       myservo.write(135);  
      digitalWrite(led_q1,HIGH);
      digitalWrite(led_q2,HIGH);
      digitalWrite(led_q3,LOW);      
      flag = 1;
    }
  }
  else if (state == "51") {
    if (flag == 0) {
      Serial.println("Q3");
    //  q3();
        myservo.write(180);  
       digitalWrite(led_q1,HIGH);
      digitalWrite(led_q2,HIGH);
      digitalWrite(led_q3,HIGH); 
       flag = 1;
    }
  } 

  
}//looop

int q0(){
  for(servoAngle = 0; servoAngle < 45; servoAngle++)  //move the micro servo from 0 degrees to 180 degrees
  {                                  
    myservo.write(servoAngle);              
    //delay(50);                  
  }  
  }

  int q1(){
  for(servoAngle = 45; servoAngle < 90; servoAngle++)  //move the micro servo from 0 degrees to 180 degrees
  {                                  
    myservo.write(servoAngle);              
    //delay(50);                  
  }  
  }

int q2(){
  for(servoAngle = 90; servoAngle < 135; servoAngle++)  //move the micro servo from 0 degrees to 180 degrees
  {                                  
    myservo.write(servoAngle);              
    //delay(50);                  
  }
  }
int q3(){
  for(servoAngle = 135; servoAngle < 180; servoAngle++)  //move the micro servo from 0 degrees to 180 degrees
  {                                  
    myservo.write(servoAngle);              
    //delay(50);                  
  }
  }

int restart(){
  for(servoAngle = 180; servoAngle > 0; servoAngle--)  //now move back the micro servo from 0 degrees to 180 degrees
  {                                
    myservo.write(servoAngle);          
    //delay(50);      
  }
  }
