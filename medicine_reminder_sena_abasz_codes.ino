#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3f, 16 , 2);
#include <Servo.h>
Servo servo_1;
Servo servo_2;
#include <virtuabotixRTC.h>
virtuabotixRTC myRTC(6,7,8);
int buzzer = 2;
int i = 0;
int button = 12;
int button_d = 0;

void setup() {
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(12,INPUT);
  //myRTC.setDS1302Time(00 ,57 , 21 , 7 , 02 , 01, 2022);
  servo_1.attach(9);//pinlerini gir
  servo_2.attach(10);
  lcd.clear();
  lcd.begin(16,2);
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Medicine Reminder");
  delay(2000);
  lcd.setCursor(2,1);
  lcd.print("Box");
  delay(2000);
  

}

void loop() {
  myRTC.updateTime(); 
  servo_1.write(0);
  servo_2.write(0);
  button_d = digitalRead(button);
 lcd.setCursor(5,0);
 lcd.print(myRTC.hours);
 lcd.print(":");
 lcd.print(myRTC.minutes);
 lcd.print(":");
 lcd.print(myRTC.seconds);
 delay(1000);
  lcd.clear();
  Serial.print(myRTC.dayofmonth);                          //Günü ekrana gönderiyoruz
  Serial.print("/");
  Serial.print(myRTC.month);                            //Ayı ekrana gönderiyoruz
  Serial.print("/");
  Serial.print(myRTC.year);                                //Yılı ekrana gönderiyoruz
                                   
  Serial.print(myRTC.hours);                               //Saati ekrana gönderiyoruz
  Serial.print(":");
  Serial.print(myRTC.minutes);                             //Dakikayi ekrana gönderiyoruz  
  Serial.print(":");
  Serial.println(myRTC.seconds);                         //Saniyeyi ekrana gönderiyoruz
  delay(1000);//1 saniye bekle
  
  if (myRTC.hours== 22 && myRTC.minutes== 19 && button_d == 0 ){
  digitalWrite(2,HIGH);
   delay(5);
   digitalWrite(2,LOW);
   delay(5);
  } 
 if (myRTC.hours== 22 && myRTC.minutes== 19  && myRTC.seconds == 15){
 for( i = 0; i <= 180; i++) {
    servo_1.write(i);
    delay(2);
  }
  for( i = 180; i>=0; i--){ 
    servo_1.write(i);
    delay(2);
   }
}
if(myRTC.hours== 22 && myRTC.minutes== 19 && button_d == 1){
  digitalWrite(2,LOW);
}


if (myRTC.hours== 9  && myRTC.minutes== 00 && button_d == 0 ){
  digitalWrite(2,HIGH);
   delay(5);
   digitalWrite(2,LOW);
   delay(5);
   
}
  
if (myRTC.hours== 9  && myRTC.minutes== 00 && myRTC.seconds == 15){
 for( i = 0; i <= 180; i++) {
    servo_2.write(i);
    delay(2);
  }
  for( i = 180; i>=0; i--){ 
    servo_2.write(i);
    delay(2);
   }
}


if (myRTC.hours== 19  && myRTC.minutes== 00  && button_d == 0 ){
  digitalWrite(2,HIGH);
   delay(5);
   digitalWrite(2,LOW);
   delay(5);
   
}
if (myRTC.hours== 19  && myRTC.minutes== 00 && myRTC.seconds == 15){
 for( i = 0; i <= 180; i++) {
    servo_2.write(i);
    delay(2);
  }
  for( i = 180; i>=0; i--){ 
    servo_2.write(i);
    delay(2);
   }
}



  

   

  


}
